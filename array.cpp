/*
? Создание массива

#include <array>
#include <iostream>

int main() {
    / Создание массива из 5 целых чисел
    std::array<int, 5> arr1 = {1, 2, 3, 4, 5};

    / Создание массива с инициализацией нулями
    std::array<int, 3> arr2{};

    / Вывод элементов
    for (int num : arr1) {
        std::cout << num << " ";
    }
}
    Вывод: 1 2 3 4 5
*/

/*
? at() - доступ к элементу с проверкой границ

std::array<int, 3> arr = {10, 20, 30};
std::cout << arr.at(1); // 20
/arr.at(5); // Выбросит исключение std::out_of_range
*/

/*
? operator[] - доступ к элементу без проверки границ

std::array<char, 4> letters = {'a', 'b', 'c', 'd'};
letters[2] = 'z'; // Изменяем третий элемент
std::cout << letters[2]; // z
*/

/*
? front() и back() - доступ к первому и последнему элементам

std::array<double, 4> nums = {1.1, 2.2, 3.3, 4.4};
std::cout << nums.front(); // 1.1
std::cout << nums.back();  // 4.4
*/

/*
? data() - доступ к указателю на массив

std::array<int, 3> arr = {100, 200, 300};
int* ptr = arr.data();
std::cout << ptr[1]; // 200
*/

/*
? begin(), end(), rbegin(), rend()

std::array<int, 4> arr = {5, 10, 15, 20};

Прямой обход
for (auto it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it << " ";
}
Вывод: 5 10 15 20

Обратный обход
for (auto it = arr.rbegin(); it != arr.rend(); ++it) {
    std::cout << *it << " ";
}
Вывод: 20 15 10 5
*/

/*
? size(), max_size(), empty()

std::array<std::string, 3> names = {"Alice", "Bob", "Charlie"};

std::cout << names.size();      // 3
std::cout << names.max_size();  // 3 (для array size == max_size)
std::cout << std::boolalpha << names.empty(); // false
*/

/*
? fill() - заполнение массива одним значением

std::array<int, 5> arr;
arr.fill(42); // Заполняем все элементы значением 42

for (int num : arr) {
    std::cout << num << " ";
}
Вывод: 42 42 42 42 42
*/

/*
? swap() - обмен содержимым с другим массивом

std::array<int, 3> a = {1, 2, 3};
std::array<int, 3> b = {4, 5, 6};

a.swap(b);

for (int num : a) {
    std::cout << num << " ";
}
Вывод: 4 5 6
*/

/*
? Сравнение массивов

std::array<int, 3> a = {1, 2, 3};
std::array<int, 3> b = {1, 2, 3};
std::array<int, 3> c = {3, 2, 1};

std::cout << (a == b); // true
std::cout << (a != c); // true
std::cout << (a < c);  // true (лексикографическое сравнение)
*/

/*
? cbegin(), cend(), crbegin(), crend() - константные итераторы

#include <array>
#include <iostream>

int main() {
    std::array<int, 4> arr = {10, 20, 30, 40};

    /Использование константных итераторов (элементы нельзя изменить)
    for (auto it = arr.cbegin(); it != arr.cend(); ++it) {
        std::cout << *it << " ";
        / *it = 0; // Ошибка: нельзя изменить значение через const_iterator
    }
}
    Вывод: 10 20 30 40
*/

/*
? Многомерные массивы

#include <array>
#include <iostream>

int main() {
    / Двумерный массив 3x2
    std::array<std::array<int, 2>, 3> matrix = {
        std::array<int, 2>{1, 2},
        std::array<int, 2>{3, 4},
        std::array<int, 2>{5, 6}
    };

    / Доступ к элементам
    std::cout << matrix[1][0]; // 3

    / Обход всех элементов
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}
    Вывод:
    1 2
    3 4
    5 6
*/