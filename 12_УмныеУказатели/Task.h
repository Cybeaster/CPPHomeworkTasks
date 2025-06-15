#pragma once
/*
  «Иерархическое дерево узлов с shared_ptr/weak_ptr»


Вам нужно реализовать класс Node, который представляет узел в древовидной
структуре:

struct Node : std::enable_shared_from_this<Node> {
    std::string name;                                // имя узла
    std::vector<std::shared_ptr<Node>> children;     // список потомков
    std::weak_ptr<Node> parent;                      // ссылка на родителя

    explicit Node(std::string name);                 // конструктор

    std::shared_ptr<Node> addChild(const std::string& child_name);
    // создаёт узел-потомок с именем child_name,
    // автоматически устанавливает его parent,
    // возвращает shared_ptr на нового потомка.

    int depth() const;
    // вычисляет «глубину» узла в дереве:
    // root.depth()==0, потомки root.depth()==1, и т.д.
};


В main():
Постройте такое дерево:

root
 ├─ child1
 │   └─ grandchild1
 └─ child2
     ├─ grandchild2a
     └─ grandchild2b

При вызове printTree(root); она должна вывести каждое имя узла на новой строке,
предваряя его 2×depth пробелами (или любым другим читаемым отступом).

Продемонстрируйте:
Вывод всего дерева.
Для одного из «внуков» получите и выведите имя его родителя через parent.lock().
Убедитесь, что при выходе из main() никаких утечек нет (например, с
AddressSanitizer или valgrind).

Отдельно прочитайте про shared_from_this.

*/

int main() {}