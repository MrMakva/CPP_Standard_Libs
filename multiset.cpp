/*
todo multiset находится в библиотеки <set>

! Почему multiset находится в <set>?
Общая реализация:

Шаблоны классов set и multiset имеют очень похожую реализацию
Они отличаются только в одном аспекте - set хранит уникальные элементы, а multiset позволяет дубликаты
Оба контейнера используют одинаковую базовую структуру данных (обычно красно-черное дерево)

Исторические причины:

В оригинальной STL (Standard Template Library), которая легла в основу стандартной библиотеки C++, эти классы были объединены
Такой подход сохранился для обратной совместимости

Логическая группировка:

Все ассоциативные контейнеры, работающие с ключами, сгруппированы по парадигмам:
<set> и <map> для сортированных контейнеров
<unordered_set> и <unordered_map> для хэш-таблиц

Практические соображения:
Нет смысла дробить библиотеку на множество мелких заголовочных файлов
Большинство программистов используют set и multiset в одних и тех же сценариях
*/

/*
? Создание multiset

#include <iostream>
#include <set>

int main() {
    / Пустой multiset целых чисел
    std::multiset<int> ms1;

    / Multiset с начальными значениями
    std::multiset<int> ms2 = {5, 2, 8, 2, 5, 3};

    / Копирование другого multiset
    std::multiset<int> ms3(ms2);
    return 0;
}
*/

/*
? Вставка элементов - insert()

std::multiset<int> ms;
ms.insert(10);
ms.insert(5);
ms.insert(10); // Дубликаты разрешены
ms.insert(20);

for (int x : ms) std::cout << x << " "; // Выведет: 5 10 10 20
*/

/*
? Удаление элементов - erase()

std::multiset<int> ms = {1, 2, 2, 3, 4, 4, 4, 5};

/ Удаление одного элемента по значению (удаляет одно вхождение)
ms.erase(2); // Удалит один элемент со значением 2

/ Удаление по итератору
auto it = ms.find(3);
if (it != ms.end()) {
    ms.erase(it);
}

/ Удаление диапазона
ms.erase(ms.begin(), ms.find(4)); // Удаляет все элементы до первого 4

/ Выведет оставшиеся элементы
for (int x : ms) std::cout << x << " ";
*/

/*
? Поиск элементов

std::multiset<int> ms = {1, 2, 2, 3, 4, 4, 4, 5};

/ find() - возвращает итератор к первому найденному элементу
auto it = ms.find(4);
if (it != ms.end()) {
    std::cout << "Found: " << *it << std::endl;
}

/ count() - возвращает количество элементов с заданным значением
std::cout << "Number of 4s: " << ms.count(4) << std::endl;

/ lower_bound() - первый элемент не меньший заданного
auto lb = ms.lower_bound(3);
std::cout << "Lower bound of 3: " << *lb << std::endl;

/ upper_bound() - первый элемент больший заданного
auto ub = ms.upper_bound(3);
std::cout << "Upper bound of 3: " << *ub << std::endl;

/ equal_range() - возвращает пару итераторов (нижняя и верхняя граница)
auto range = ms.equal_range(4);
for (auto it = range.first; it != range.second; ++it) {
    std::cout << *it << " ";
}
*/

/*
? Размер и проверка на пустоту

std::multiset<int> ms = {1, 2, 3};

std::cout << "Size: " << ms.size() << std::endl; // 3
std::cout << "Empty? " << (ms.empty() ? "Yes" : "No") << std::endl; // No

ms.clear();
std::cout << "After clear - size: " << ms.size() << std::endl; // 0
*/

/*
? Доступ к элементам

std::multiset<int> ms = {10, 20, 30, 40};

/ begin()/end() - итераторы
std::cout << "First element: " << *ms.begin() << std::endl;
std::cout << "Elements: ";
for (auto it = ms.begin(); it != ms.end(); ++it) {
    std::cout << *it << " ";
}

/ rbegin()/rend() - обратные итераторы
std::cout << "\nReverse: ";
for (auto rit = ms.rbegin(); rit != ms.rend(); ++rit) {
    std::cout << *rit << " ";
}
*/

/*
? Обмен содержимого - swap()

std::multiset<int> ms1 = {1, 2, 3};
std::multiset<int> ms2 = {4, 5, 6};

ms1.swap(ms2);

Теперь ms1 содержит {4,5,6}, а ms2 содержит {1,2,3}
*/

/*
? Извлечение узлов (C++17)

std::multiset<int> ms = {1, 2, 3, 4, 5};

/ Извлечение узла
auto node = ms.extract(3);
if (!node.empty()) {
    std::cout << "Extracted: " << node.value() << std::endl;
}

/ Вставка обратно
ms.insert(std::move(node));
*/

/*
? Слияние (C++17)

std::multiset<int> ms1 = {1, 2, 3};
std::multiset<int> ms2 = {3, 4, 5};

/ Перенос элементов из ms2 в ms1
ms1.merge(ms2);

ms1 теперь содержит {1, 2, 3, 3, 4, 5}
ms2 теперь пуст
*/