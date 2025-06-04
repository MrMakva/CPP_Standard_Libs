/*
? Создание вектора

#include <iostream>
#include <vector>

int main() {
    / Пустой вектор
    std::vector<int> vec1;

    / Вектор с 5 элементами (значение по умолчанию: 0)
    std::vector<int> vec2(5);

    / Вектор с 5 элементами, каждый равен 10
    std::vector<int> vec3(5, 10);

    / Вектор, инициализированный списком
    std::vector<int> vec4 = {1, 2, 3, 4, 5};

    / Вектор, скопированный из другого вектора
    std::vector<int> vec5(vec4);
    return 0;
}
*/

/*
? push_back() – Добавление элемента в конец

std::vector<int> vec = {1, 2, 3};
vec.push_back(4); // vec = {1, 2, 3, 4}
*/

/*
? pop_back() – Удаление последнего элемента

std::vector<int> vec = {1, 2, 3};
vec.pop_back(); // vec = {1, 2}
*/

/*
? size() – Получение количества элементов

std::vector<int> vec = {1, 2, 3};
std::cout << vec.size(); // Выведет 3
*/

/*
? empty() – Проверка на пустоту

std::vector<int> vec;
if (vec.empty()) {
    std::cout << "Вектор пуст!";
}
*/

/*
? clear() – Очистка вектора

std::vector<int> vec = {1, 2, 3};
vec.clear(); // vec = {}
*/

/*
? at() – Доступ к элементу с проверкой границ

std::vector<int> vec = {10, 20, 30};
std::cout << vec.at(1); // 20
/ vec.at(5) выбросит исключение std::out_of_range
*/

/*
? operator[] – Доступ к элементу без проверки границ

std::vector<int> vec = {10, 20, 30};
std::cout << vec[1]; // 20
/ vec[5] — неопределённое поведение
*/

/*
? front() и back() – Первый и последний элементы

std::vector<int> vec = {1, 2, 3};
std::cout << vec.front(); // 1
std::cout << vec.back();  // 3
*/

/*
? begin() и end() – Итераторы

std::vector<int> vec = {1, 2, 3};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " "; // 1 2 3
}
*/

/*
? insert() – Вставка элемента

std::vector<int> vec = {1, 3, 4};
vec.insert(vec.begin() + 1, 2); // vec = {1, 2, 3, 4}
*/

/*
? erase() – Удаление элемента

std::vector<int> vec = {1, 2, 3, 4};
vec.erase(vec.begin() + 1); // vec = {1, 3, 4}
*/

/*
? resize() – Изменение размера

std::vector<int> vec = {1, 2, 3};
vec.resize(5);       // vec = {1, 2, 3, 0, 0}
vec.resize(2);       // vec = {1, 2}
*/

/*
? reserve() – Резервирование памяти

std::vector<int> vec;
vec.reserve(100); // Зарезервировали память под 100 элементов
*/

/*
? capacity() – Получение зарезервированной памяти

std::vector<int> vec;
vec.reserve(100);
std::cout << vec.capacity(); // 100
*/

/*
? swap() – Обмен содержимого двух векторов

std::vector<int> vec1 = {1, 2, 3};
std::vector<int> vec2 = {4, 5};
vec1.swap(vec2); // vec1 = {4, 5}, vec2 = {1, 2, 3}
*/

/*
? assign() – Замена содержимого вектора

std::vector<int> vec = {1, 2, 3};
vec.assign(5, 10); // vec = {10, 10, 10, 10, 10}
*/

/*
? emplace_back() – Эффективное добавление элемента

std::vector<std::string> vec;
vec.emplace_back("Hello"); // Эффективнее, чем push_back
*/

/*
? emplace() – Вставка элемента через итератор

std::vector<int> vec = {1, 3};
vec.emplace(vec.begin() + 1, 2); // vec = {1, 2, 3}
*/

/*
? data() – Доступ к сырому массиву

std::vector<int> vec = {1, 2, 3};
int* ptr = vec.data();
std::cout << ptr[1]; // 2
*/

/*
? shrink_to_fit() – Уменьшение capacity() до size()
Освобождает неиспользуемую память, уменьшая capacity() до size()

std::vector<int> vec(1000);
vec.resize(10);
vec.shrink_to_fit(); // capacity() станет 10 (или около того, зависит от реализации)
*/

/*
? max_size() – Максимально возможный размер вектора
Возвращает теоретический максимум элементов, который может содержать вектор.

std::vector<int> vec;
std::cout << vec.max_size(); // Зависит от системы (например, 2^64 / sizeof(int))
*/

/*
? operator= – Присваивание
Копирование или перемещение содержимого другого вектора.

std::vector<int> vec1 = {1, 2, 3};
std::vector<int> vec2;
vec2 = vec1;          // Копирование (vec2 = {1, 2, 3})
vec2 = std::move(vec1); // Перемещение (vec1 теперь пуст)
*/

/*
? Сравнение векторов (==, !=, <, >, <=, >=)
Лексикографическое сравнение элементов.

std::vector<int> a = {1, 2, 3};
std::vector<int> b = {1, 2, 4};
if (a < b) {
    std::cout << "a меньше b"; // Выведется, так как 3 < 4
}
*/

/*
? std::swap() – Глобальная функция обмена
Аналог метода swap(), но работает для любых контейнеров.

std::vector<int> vec1 = {1, 2};
std::vector<int> vec2 = {3, 4};
std::swap(vec1, vec2); // vec1 = {3, 4}, vec2 = {1, 2}
*/

/*
? insert() с диапазоном
Вставка нескольких элементов за раз.

std::vector<int> vec = {1, 5};
std::vector<int> to_insert = {2, 3, 4};
vec.insert(vec.begin() + 1, to_insert.begin(), to_insert.end()); // vec = {1, 2, 3, 4, 5}
*/

/*
? erase() с диапазоном
Удаление нескольких элементов за раз.

std::vector<int> vec = {1, 2, 3, 4, 5};
vec.erase(vec.begin() + 1, vec.begin() + 3); // vec = {1, 4, 5}
*/
