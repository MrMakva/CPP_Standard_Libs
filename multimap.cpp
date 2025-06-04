/*
todo multiset находится в библиотеки <set>

! Почему multiset находится в <set>?
Причины схожи и описанны в multiset.cpp
*/

/*
? insert - Создание и вставка элементов

#include <iostream>
#include <map>  // multimap находится здесь

int main() {
    std::multimap<int, std::string> mm;

    / Вставка элементов (допускаются дубликаты ключей)
    mm.insert({1, "Apple"});
    mm.insert({2, "Banana"});
    mm.insert({1, "Avocado"});  // Дубликат ключа 1
    mm.insert({3, "Cherry"});

    / Вывод всех элементов
    for (const auto& pair : mm) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
    Вывод:
    1: Apple
    1: Avocado
    2: Banana
    3: Cherry
*/

/*
? find, count - Поиск элементов

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm = {
        {1, "Apple"},
        {2, "Banana"},
        {1, "Avocado"},
    };

    / Поиск первого элемента с ключом 1
    auto it = mm.find(1);
    if (it != mm.end()) {
        std::cout << "Found: " << it->second << std::endl;  // Apple
    }

    / Подсчёт количества элементов с ключом 1
    std::cout << "Number of 1's: " << mm.count(1) << std::endl;  // 2
}
*/

/*
? erase - Удаление элементов

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm = {
        {1, "Apple"},
        {2, "Banana"},
        {1, "Avocado"},
    };

    mm.erase(1);  // Удаляет все элементы с ключом 1

    for (const auto& pair : mm) {
        std::cout << pair.first << ": " << pair.second << std::endl;  // 2: Banana
    }
}
*/

/*
? lower_bound, upper_bound, equal_range - Диапазон элементов

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm = {
        {1, "Apple"},
        {2, "Banana"},
        {2, "Blueberry"},
        {3, "Cherry"},
    };

    / Находим диапазон ключа 2
    auto lower = mm.lower_bound(2);
    auto upper = mm.upper_bound(2);

    std::cout << "Elements with key 2:" << std::endl;
    for (auto it = lower; it != upper; ++it) {
        std::cout << it->second << std::endl;  // Banana, Blueberry
    }

    / Или используем equal_range
    auto range = mm.equal_range(2);
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->second << std::endl;  // Banan, Blueberry
    }
}
*/

/*
? size() и empty() – проверка размера и пустоты

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm = {
        {1, "Apple"},
        {2, "Banana"},
    };

    std::cout << "Size: " << mm.size() << std::endl;  // 2
    std::cout << "Is empty? " << (mm.empty() ? "Yes" : "No") << std::endl;  // No

    mm.clear();  // Очищаем multimap
    std::cout << "After clear(), is empty? " << (mm.empty() ? "Yes" : "No") << std::endl;  // Yes
}
*/

/*
? clear() – полная очистка контейнера

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm = {
        {1, "Apple"},
        {2, "Banana"},
    };

    mm.clear();  // Удаляем все элементы
    std::cout << "Size after clear(): " << mm.size() << std::endl;  // 0
}
*/

/*
? emplace() – эффективная вставка без копирования
Аналог insert, но создаёт элемент на месте (полезно для сложных объектов):

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm;

    mm.emplace(1, "Apple");  // Аналог mm.insert({1, "Apple"});
    mm.emplace(2, "Banana");

    for (const auto& pair : mm) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}
*/

/*
? swap() – обмен содержимого двух multimap

#include <iostream>
#include <map>

int main() {
    std::multimap<int, std::string> mm1 = {{1, "A"}, {2, "B"}};
    std::multimap<int, std::string> mm2 = {{3, "C"}, {4, "D"}};

    mm1.swap(mm2);  // Теперь mm1 содержит {3, "C"}, {4, "D"}, а mm2 – {1, "A"}, {2, "B"}

    std::cout << "mm1 after swap:" << std::endl;
    for (const auto& pair : mm1) {
        std::cout << pair.first << ": " << pair.second << std::endl;  // 3: C, 4: D
    }
}
*/