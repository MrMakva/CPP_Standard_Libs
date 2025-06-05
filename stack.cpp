/*
todo Библиотека <stack> в C++ предоставляет контейнер, который работает по
принципу LIFO (Last In, First Out - последним пришёл, первым ушёл).
*/

/*
? push() - Добавление элемента на вершину стека

#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    / Стек теперь содержит: 30 (верх), 20, 10 (низ)
    return 0;
}
*/

/*
? pop() - Удаление элемента с вершины стека

#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop(); // Удаляем 30

    / Теперь стек содержит: 20 (верх), 10 (низ)
    std::cout << "Верхний элемент после pop(): " << s.top() << std::endl;
    return 0;
}
*/

/*
? top() - Доступ к верхнему элементу

#include <iostream>
#include <stack>

int main() {
    std::stack<std::string> s;
    s.push("Первый");
    s.push("Второй");
    s.push("Третий");
    
    std::cout << "Верхний элемент: " << s.top() << std::endl; // Выведет "Третий"
    return 0;
}
*/

/*
? empty() - Проверка на пустоту

#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    if (s.empty()) {
        std::cout << "Стек пуст" << std::endl;
    }
    s.push(42);
    if (!s.empty()) {
        std::cout << "Стек не пуст" << std::endl;
    }
    return 0;
}
*/

/*
? size() - Получение количества элементов

#include <iostream>
#include <stack>

int main() {
    std::stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');

    std::cout << "Размер стека: " << s.size() << std::endl; // Выведет 3
    return 0;
}
*/

/*
? emplace() - Создание элемента на вершине стека (C++11)
Более эффективная альтернатива push() для сложных объектов, так как создает
объект непосредственно в стеке, избегая копирования.

#include <iostream>
#include <stack>
#include <string>

class Book {
public:
    Book(const std::string& title, int year) : title(title), year(year) {}
    void print() const {
        std::cout << title << " (" << year << ")" << std::endl;
    }
private:
    std::string title;
    int year;
};

int main() {
    std::stack<Book> s;
    
    / Использование push (создаем объект и копируем его в стек)
    s.push(Book("1984", 1949));
    
    / Использование emplace (создаем объект непосредственно в стеке)
    s.emplace("Brave New World", 1932);
    
    while (!s.empty()) {
        s.top().print();
        s.pop();
    }
    return 0;
}
*/

/*
? Обмен содержимого стеков swap() (C++11)

#include <iostream>
#include <stack>

int main() {
    std::stack<int> s1, s2;
    
    s1.push(1); s1.push(2); s1.push(3);
    s2.push(4); s2.push(5);
    
    std::cout << "До swap:" << std::endl;
    std::cout << "s1 size: " << s1.size() << ", s2 size: " << s2.size() << std::endl;
    
    s1.swap(s2);
    
    std::cout << "После swap:" << std::endl;
    std::cout << "s1 size: " << s1.size() << ", s2 size: " << s2.size() << std::endl;
    
    return 0;
}
*/

/*
todo Особенности работы со стеком
Адаптер контейнера: std::stack является адаптером контейнера и по умолчанию использует std::deque как базовый контейнер. Можно изменить:
Ограничения доступа: В отличие от других контейнеров, стек предоставляет доступ только к верхнему элементу.
Итераторы отсутствуют: Невозможно использовать итераторы для обхода стека без извлечения элементов.
Производительность: Все операции работают за O(1), так как работают только с верхним элементом.
*/

/*
todo std::stack может использовать различные контейнеры в качестве основы.
Рассмотрим пример с std::vector:

#include <iostream>
#include <stack>
#include <vector>

int main() {
    / Стек на основе vector
    std::stack<int, std::vector<int>> v_stack;
    
    v_stack.push(10);
    v_stack.push(20);
    v_stack.push(30);
    
    std::cout << "Размер стека на vector: " << v_stack.size() << std::endl;
    std::cout << "Верхний элемент: " << v_stack.top() << std::endl;  
    return 0;
}
    std::deque (по умолчанию): Быстрые операции добавления/удаления с обоих концов
    std::vector: Компактное хранение, но может потребовать переаллокации
    std::list: Стабильные указатели на элементы
*/