/*
todo unordered_multimap - представляет собой ассоциативный контейнер, который
хранит пары ключ-значение, допуская дублирование ключей. Он реализован как
хеш-таблица.

! unordered_multimap находится в библеотеки unordered_map
*/

/*
? unordered_multimap() – создает пустой контейнер.
? unordered_multimap(initializer_list<value_type> init) – создает контейнер из списка инициализации.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    / Пустой unordered_multimap
    std::unordered_multimap<std::string, int> umap1;

    / Инициализация списком
    std::unordered_multimap<std::string, int> umap2 = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 3}  // Допускаются дубликаты ключей
    };

    / Вывод элементов
    for (const auto& pair : umap2) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
    Вывод:
    banana: 2
    apple: 1
    apple: 3
*/

/*
? insert(const value_type& value) – добавляет пару ключ-значение.
? emplace(Args&&... args) – конструирует элемент на месте.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap;

    / insert
    umap.insert({"apple", 1});
    umap.insert(std::make_pair("banana", 2));
    umap.insert({"apple", 4});  // Дубликат ключа

    / emplace
    umap.emplace("orange", 3);
    umap.emplace("apple", 5);  // Еще один дубликат

    / Вывод
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
    Вывод:
    orange: 3
    banana: 2
    apple: 1
    apple: 4
    apple: 5
*/

/*
? find(const key_type& key) – возвращает итератор к первому найденному элементу с ключом key.
? count(const key_type& key) – возвращает количество элементов с ключом key.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 3}
    };

    / find
    auto it = umap.find("apple");
    if (it != umap.end()) {
        std::cout << "Found: " << it->first << " -> " << it->second << std::endl;
    }

    / count
    std::cout << "Number of 'apple's: " << umap.count("apple") << std::endl;
    return 0;
}
    Вывод:
    Found: apple -> 1
    Number of 'apple's: 2
*/

/*
? erase(const key_type& key) – удаляет все элементы с ключом key.
? erase(iterator pos) – удаляет элемент по итератору.
? clear() – очищает весь контейнер.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 3},
        {"orange", 4}
    };

    / Удаление по ключу
    umap.erase("apple");  // Удалит все "apple"

    / Удаление по итератору
    auto it = umap.find("banana");
    if (it != umap.end()) {
        umap.erase(it);
    }

    / Вывод оставшихся элементов
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    / Очистка всего контейнера
    umap.clear();
    return 0;
}
    Вывод:
    orange: 4
*/

/*
? size() – возвращает количество элементов.
? empty() – возвращает true, если контейнер пуст.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap = {
        {"apple", 1},
        {"banana", 2}
    };

    std::cout << "Size: " << umap.size() << std::endl;  // 2
    std::cout << "Is empty? " << (umap.empty() ? "Yes" : "No") << std::endl;  // No

    umap.clear();
    std::cout << "Is empty after clear? " << (umap.empty() ? "Yes" : "No") << std::endl;  // Yes
    return 0;
}
    Вывод:
    Size: 2
    Is empty? No
    Is empty after clear? Yes
*/

/*
? swap(unordered_multimap& other) – обменивает содержимое двух контейнеров.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap1 = {{"A", 1}, {"B", 2}};
    std::unordered_multimap<std::string, int> umap2 = {{"X", 10}, {"Y", 20}};

    umap1.swap(umap2);

    std::cout << "umap1:" << std::endl;
    for (const auto& pair : umap1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "umap2:" << std::endl;
    for (const auto& pair : umap2) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
    Вывод:
    umap1:
    Y: 20
    X: 10
    umap2:
    B: 2
    A: 1
*/

/*
? reserve(size_type count) – устанавливает минимальное количество корзин.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap;
    umap.reserve(100);  // Резервируем место под 100 элементов

    umap.emplace("A", 1);
    umap.emplace("B", 2);

    std::cout << "Bucket count: " << umap.bucket_count() << std::endl;

    return 0;
}
    Вывод:
    Bucket count: 103  // Обычно простое число >= 100
*/

/*
? equal_range(const key_type& key) – возвращает пару итераторов (begin, end) для
всех элементов с ключом key.

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap = {
        {"apple", 1},
        {"banana", 2},
        {"apple", 3},
        {"apple", 5}
    };

    / Получаем диапазон для ключа "apple"
    auto range = umap.equal_range("apple");

    / Перебираем все элементы с ключом "apple"
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
    return 0;
}
    Вывод:
    apple: 1
    apple: 3
    apple: 5
*/

/*
todo Можно сравнивать два unordered_multimap с помощью операторов == и !=.
Контейнеры равны, если:
Имеют одинаковый размер.
Все элементы совпадают (порядок не важен, но количество дубликатов учитывается).

#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_multimap<std::string, int> umap1 = {
        {"apple", 1},
        {"banana", 2}
    };

    std::unordered_multimap<std::string, int> umap2 = {
        {"banana", 2},
        {"apple", 1}
    };

    std::unordered_multimap<std::string, int> umap3 = {
        {"apple", 1},
        {"apple", 2}  // Другой набор элементов
    };

    std::cout << "umap1 == umap2: " << (umap1 == umap2 ? "Yes" : "No") << std::endl;  // Yes
    std::cout << "umap1 == umap3: " << (umap1 == umap3 ? "Yes" : "No") << std::endl;  // No
    return 0;
}
    Вывод:
    umap1 == umap2: Yes
    umap1 == umap3: No
*/