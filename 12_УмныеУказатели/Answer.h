#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*Наследуемся от std::enable_shared_from_this<Node>, чтобы внутри метода
addChild получить корректный shared_ptr на this.
Поле parent держит weak_ptr — оно не увеличивает счетчик ссылок и предотвращает
циклическую утечку. Метод depth() поднимается по цепочке parent, считая уровень
вложенности. printTree выводит каждый узел с отступом, равным его глубине.*/

// Класс Node с поддержкой shared_from_this
struct Node : std::enable_shared_from_this<Node> {
  std::string name;
  std::vector<std::shared_ptr<Node>> children;
  std::weak_ptr<Node> parent;

  explicit Node(std::string name) : name(std::move(name)) {}

  std::shared_ptr<Node> addChild(const std::string &child_name) {
    auto child = std::make_shared<Node>(child_name);
    child->parent = shared_from_this(); // weak ссылка на текущий
    children.push_back(child);
    return child;
  }

  int depth() const {
    int d = 0;
    auto p = parent.lock();
    while (p) {
      ++d;
      p = p->parent.lock();
    }
    return d;
  }
};

// Рекурсивная печать дерева
void printTree(const std::shared_ptr<Node> &node) {
  std::cout << std::string(node->depth() * 2, ' ') << node->name << "\n";
  for (auto &ch : node->children)
    printTree(ch);
}

int main() {
  // Построение дерева
  auto root = std::make_shared<Node>("root");
  auto c1 = root->addChild("child1");
  auto gc1 = c1->addChild("grandchild1");
  auto c2 = root->addChild("child2");
  auto gc2a = c2->addChild("grandchild2a");
  auto gc2b = c2->addChild("grandchild2b");

  // Вывод дерева
  std::cout << "Tree structure:\n";
  printTree(root);

  // Демонстрация weak_ptr -> shared_ptr
  if (auto p = gc2b->parent.lock()) {
    std::cout << "\nParent of " << gc2b->name << " is " << p->name << "\n";
  }

  return 0;
}
