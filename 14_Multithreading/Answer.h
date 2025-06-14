#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <vector>
#include <atomic>

template<typename T>
class BoundedBuffer {
public:
    explicit BoundedBuffer(size_t capacity)
        : capacity_(capacity) {}

    void push(const T& item) {
        std::unique_lock<std::mutex> lk(mtx_);
        not_full_.wait(lk, [&]{ return buffer_.size() < capacity_; });
        buffer_.push(item);
        not_empty_.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> lk(mtx_);
        not_empty_.wait(lk, [&]{ return !buffer_.empty(); });
        T item = buffer_.front();
        buffer_.pop();
        not_full_.notify_one();
        return item;
    }

private:
    std::queue<T> buffer_;
    size_t capacity_;
    std::mutex mtx_;
    std::condition_variable not_empty_, not_full_;
};

int main() {
    const size_t PRODUCERS = 2;
    const size_t CONSUMERS = 3;
    const int ITEMS_PER_PRODUCER = 20;
    BoundedBuffer<int> buf(5);

    std::atomic<int> consumed_count{0};
    const int TOTAL_ITEMS = PRODUCERS * ITEMS_PER_PRODUCER;

    // Производители
    std::vector<std::thread> producers;
    for (size_t p = 0; p < PRODUCERS; ++p) {
        producers.emplace_back([&, p]() {
            for (int i = 1; i <= ITEMS_PER_PRODUCER; ++i) {
                buf.push(i + p*ITEMS_PER_PRODUCER);
                std::cout << "[Producer " << p << "] pushed " << (i + p*ITEMS_PER_PRODUCER) << "\n";
            }
        });
    }

    // Потребители
    std::vector<std::thread> consumers;
    for (size_t c = 0; c < CONSUMERS; ++c) {
        consumers.emplace_back([&, c]() {
            while (true) {
                int item = buf.pop();
                int prev = consumed_count.fetch_add(1) + 1;
                std::cout << "  [Consumer " << c << "] popped " << item
                          << "  (total popped: " << prev << ")\n";
                if (prev >= TOTAL_ITEMS) break;
            }
        });
    }

    // Ждём завершения
    for (auto& t : producers) t.join();
    for (auto& t : consumers) t.join();
    std::cout << "All items produced and consumed.\n";
}
