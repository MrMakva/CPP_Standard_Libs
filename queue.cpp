/*
? push(const T& value) – Добавление элемента в конец очереди

#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    std::cout << "Очередь после push: ";
    while (!q.empty()) {
        std::cout << q.front() << " ";
        q.pop();
    }
    Вывод: 10 20 30
    return 0;
}
*/

/*
? emplace(Args&&... args) – Создание элемента на месте (без копирования)
Полезно для сложных объектов (например, std::pair или пользовательских классов).

#include <iostream>
#include <queue>

int main() {
    std::queue<std::pair<int, std::string>> q;
    q.emplace(1, "Alice");  // Создаёт pair(1, "Alice") прямо в очереди
    q.emplace(2, "Bob");

    std::cout << "Очередь после emplace:\n";
    while (!q.empty()) {
        auto& elem = q.front();
        std::cout << elem.first << ": " << elem.second << "\n";
        q.pop();
    }
    / Вывод:
    / 1: Alice
    / 2: Bob
    return 0;
}
*/

/*
? pop() – Удаление первого элемента
Важно: pop() не возвращает значение, только удаляет.

#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(100);
    q.push(200);
    q.push(300);

    std::cout << "Перед pop: " << q.front() << "\n";  // 100
    q.pop();  // Удаляем 100
    std::cout << "После pop: " << q.front() << "\n";  // 200

    return 0;
}
*/

/*
? front() – Доступ к первому элементу

#include <iostream>
#include <queue>

int main() {
    std::queue<char> q;
    q.push('A');
    q.push('B');
    q.push('C');

    std::cout << "Первый элемент: " << q.front() << "\n";  // 'A'
    q.pop();
    std::cout << "Теперь первый: " << q.front() << "\n";   // 'B'

    return 0;
}
*/

/*
? back() – Доступ к последнему элементу

#include <iostream>
#include <queue>

int main() {
    std::queue<double> q;
    q.push(3.14);
    q.push(2.71);
    q.push(1.61);

    std::cout << "Последний элемент: " << q.back() << "\n";  // 1.61
    q.pop();  // Удаляем 3.14
    std::cout << "Теперь последний: " << q.back() << "\n";   // 1.61 (не изменился)

    return 0;
}
*/

/*
? size() – Количество элементов в очереди

#include <iostream>
#include <queue>

int main() {
    std::queue<std::string> q;
    q.push("Hello");
    q.push("World");

    std::cout << "Размер очереди: " << q.size() << "\n";  // 2
    q.pop();
    std::cout << "Теперь размер: " << q.size() << "\n";    // 1

    return 0;
}
*/

/*
? empty() – Проверка, пуста ли очередь

#include <iostream>
#include <queue>

int main() {
    std::queue<int> q;
    q.push(42);

    if (!q.empty()) {
        std::cout << "Очередь не пуста!\n";
    }

    q.pop();
    if (q.empty()) {
        std::cout << "Теперь очередь пуста.\n";
    }

    return 0;
}
*/

/*
? swap(queue& other) – Обмен содержимым двух очередей

#include <iostream>
#include <queue>

int main() {
    std::queue<int> q1, q2;
    q1.push(1);
    q1.push(2);
    q2.push(100);

    q1.swap(q2);  // Теперь q1 = {100}, q2 = {1, 2}

    std::cout << "q1: " << q1.front() << " (размер: " << q1.size() << ")\n";  // 100 (1)
    std::cout << "q2: " << q2.front() << " (размер: " << q2.size() << ")\n";  // 1 (2)

    return 0;
}
*/

/*
? Сравнение очередей (==, !=, <, >, <=, >=)
поддерживает операции сравнения, которые сравнивают элементы лексикографически
(как в словаре).

#include <iostream>
#include <queue>

int main() {
    std::queue<int> q1, q2;
    q1.push(1);
    q1.push(2);
    q2.push(1);
    q2.push(3);

    if (q1 == q2) {
        std::cout << "Очереди равны\n";
    } else {
        std::cout << "Очереди НЕ равны\n";  // Выведется это
    }

    return 0;
}
*/