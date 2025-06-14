#pragma once
/*
  Реализуйте класс

struct Node : std::enable_shared_from_this<Node> {
    std::string name;
    std::vector<std::shared_ptr<Node>> children;
    std::weak_ptr<Node> parent;

    explicit Node(std::string name);

    // Создает узел-потомок и устанавливает его parent
    std::shared_ptr<Node> addChild(const std::string& child_name);

    // Возвращает глубину в дереве (root = 0)
    int depth() const;
};

В main():
Постройте такое дерево:

root
 ├─ child1
 │   └─ grandchild1
 └─ child2
     ├─ grandchild2a
     └─ grandchild2b

Напишите рекурсивную функцию printTree(node, indent), которая выводит на экран
имя узла с отступом, равным его depth().

Продемонстрируйте:
Вывод всего дерева.
Для одного из «внуков» получите и выведите имя его родителя через parent.lock().
Убедитесь, что при выходе из main() никаких утечек нет (например, с
AddressSanitizer или valgrind).

Отдельно прочитайте про shared_from_this.

*/

int main() {}