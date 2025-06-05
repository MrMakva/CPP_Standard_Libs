/*
? push(element) – Добавление элемента

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    / Добавляем элементы
    pq.push(50);
    pq.push(20);
    pq.push(30);

    / Теперь очередь: [50, 30, 20] (максимальная куча)
    std::cout << "Top after push: " << pq.top() << std::endl; // 50
    return 0;
}
    Вывод:
    Top after push: 50
*/

/*
? pop() – Удаление верхнего элемента

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    pq.push(50);
    pq.push(20);
    pq.push(30);

    std::cout << "Before pop: " << pq.top() << std::endl; // 50
    pq.pop();  // Удаляем 50
    std::cout << "After pop: " << pq.top() << std::endl;  // 30

    return 0;
}
    Вывод:
    Before pop: 50
    After pop: 30
*/

/*
? top() – Доступ к верхнему элементу

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;
    pq.push(50);
    pq.push(20);
    pq.push(30);

    / Получаем верхний элемент без удаления
    std::cout << "Top element: " << pq.top() << std::endl; // 50
    return 0;
}
    Вывод:
    Top element: 50
*/

/*
? empty() – Проверка на пустоту

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    if (pq.empty()) {
        std::cout << "Queue is empty!" << std::endl;
    }

    pq.push(10);

    if (!pq.empty()) {
        std::cout << "Queue is NOT empty!" << std::endl;
    }
    return 0;
}
    Вывод:
    Queue is empty!
    Queue is NOT empty!
*/

/*
? size() – Количество элементов

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq;

    pq.push(50);
    pq.push(20);
    pq.push(30);

    std::cout << "Size: " << pq.size() << std::endl; // 3
    return 0;
}
    Вывод:
    Size: 3
*/

/*
? emplace() – создание элемента на месте

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<std::string> pq;

    / emplace создаёт строку прямо в очереди (без лишних копирований)
    pq.emplace("Alice");
    pq.emplace("Bob");
    pq.emplace("Charlie");

    std::cout << pq.top() << std::endl;  // "Charlie" (лексикографический порядок)
    return 0;
}
*/

/*
? swap() – обмен содержимого двух очередей

#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> pq1;
    pq1.push(10);
    pq1.push(20);

    std::priority_queue<int> pq2;
    pq2.push(30);
    pq2.push(40);

    pq1.swap(pq2);  // Теперь pq1 содержит {40, 30}, а pq2 – {20, 10}

    std::cout << "pq1 top: " << pq1.top() << std::endl;  // 40
    std::cout << "pq2 top: " << pq2.top() << std::endl;  // 20

    return 0;
}
*/