#include <cmath> // sqrt
#include <iostream>
#include <limits> // std::numeric_limits
#include <memory>
#include <vector>

constexpr double PI = 3.14159265358979323846;

struct Shape {
  virtual double area() const = 0;
  virtual ~Shape() = default;
};

/* ───────── прямоугольник ───────── */
struct Rect : Shape {
  double w, h;
  Rect(double w, double h) : w(w), h(h) {}
  double area() const override { return w * h; }
};

/* ───────── круг ───────── */
struct Circ : Shape {
  double r;
  explicit Circ(double r) : r(r) {}
  double area() const override { return PI * r * r; }
};

/* ───────── треугольник ───────── */
struct Tri : Shape {
  double a, b, c;
  Tri(double a, double b, double c) : a(a), b(b), c(c) {}
  double area() const override {
    double p = (a + b + c) / 2;
    double s2 = p * (p - a) * (p - b) * (p - c);
    return s2 > 0 ? std::sqrt(s2) : 0.0; // защита от NaN
  }
};

int main() {
  std::vector<std::unique_ptr<Shape>> shapes;
  char type;

  std::cout << "Формат ввода:\n"
               "  R w h    -- прямоугольник\n"
               "  C r      -- круг\n"
               "  T a b c  -- треугольник\n"
               "Нажмите X для конца ввода\n\n";

  while (std::cin >> type) {
    if (type == 'R') {
      double w, h;
      if (std::cin >> w >> h)
        shapes.emplace_back(std::make_unique<Rect>(w, h));
    } else if (type == 'C') {
      double r;
      if (std::cin >> r)
        shapes.emplace_back(std::make_unique<Circ>(r));
    } else if (type == 'T') {
      double a, b, c;
      if (std::cin >> a >> b >> c)
        shapes.emplace_back(std::make_unique<Tri>(a, b, c));
    } else if (type == 'X') {
      break;
    } else {
      std::cerr << "Неизвестный код фигуры: " << type << "\n";
      // пропустим строку до конца
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  double total = 0.0;
  for (const auto &shp : shapes)
    total += shp->area();

  std::cout << "\nTotal area = " << total << '\n';
}
