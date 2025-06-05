/*
? insert() – Добавляет элемент в контейнер.
? erase() – Удаляет элемент по значению или итератору.
? find() – Ищет элемент и возвращает итератор на него (или end(), если не найден).
? count() – Возвращает количество элементов с заданным ключом (0 или 1, так как unordered_set хранит уникальные элементы).
? size() – Возвращает количество элементов.
? empty() – Проверяет, пуст ли контейнер.
? clear() – Очищает контейнер.
? begin(), end() – Возвращают итераторы на начало и конец контейнера.
? bucket_count() – Возвращает количество "корзин" (buckets) в хеш-таблице.
? load_factor() – Возвращает коэффициент загрузки (среднее количество элементов на корзину).
? rehash() – Устанавливает количество корзин.
? reserve() – Резервирует место для определенного количества элементов.

#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    / 1. Создание unordered_set
    std::unordered_set<std::string> uset = {"apple", "banana", "cherry"};

    / 2. insert() – добавление элементов
    uset.insert("orange");
    uset.insert("apple"); // Не добавится, так как "apple" уже есть

    / 3. erase() – удаление элемента
    uset.erase("banana");

    / 4. find() – поиск элемента
    auto it = uset.find("cherry");
    if (it != uset.end()) {
        std::cout << "Found: " << *it << std::endl; // Found: cherry
    }

    / 5. count() – проверка наличия элемента
    if (uset.count("apple") > 0) {
        std::cout << "Apple is in the set" << std::endl;
    }

    / 6. size() – количество элементов
    std::cout << "Size: " << uset.size() << std::endl; // Size: 3

    / 7. empty() – проверка на пустоту
    if (!uset.empty()) {
        std::cout << "Set is not empty" << std::endl;
    }

    / 8. clear() – очистка контейнера
    uset.clear();

    / 9. Итерация по unordered_set
    uset = {"one", "two", "three"};
    for (const auto& elem : uset) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    / 10. bucket_count() и load_factor()
    std::cout << "Bucket count: " << uset.bucket_count() << std::endl;
    std::cout << "Load factor: " << uset.load_factor() << std::endl;

    / 11. rehash() – изменение количества корзин
    uset.rehash(20);
    std::cout << "New bucket count: " << uset.bucket_count() << std::endl;

    / 12. reserve() – резервирование места
    uset.reserve(100);
    std::cout << "Bucket count after reserve: " << uset.bucket_count() << std::endl;
    return 0;
}
    Вывод:
    Found: cherry
    Apple is in the set
    Size: 3
    Set is not empty
    three two one 
    Bucket count: 7
    Load factor: 0.428571
    New bucket count: 23
    Bucket count after reserve: 103
*/

/*
? emplace() – Эффективная вставка элемента (без создания временного объекта)
std::unordered_set<std::string> uset;
uset.emplace("apple");  // Аналог insert, но может быть эффективнее для сложных объектов
*/

/*
? emplace_hint() – Вставка с подсказкой (может ускорить вставку, если позиция известна)
auto hint = uset.begin();
uset.emplace_hint(hint, "banana");  // Подсказка для ускорения вставки
*/

/*
? swap() – Обмен содержимого двух unordered_set
std::unordered_set<int> set1 = {1, 2, 3};
std::unordered_set<int> set2 = {4, 5, 6};
set1.swap(set2);  // Теперь set1 = {4, 5, 6}, set2 = {1, 2, 3}
*/

/*
? bucket() – Возвращает номер корзины, в которой находится элемент
std::unordered_set<std::string> uset = {"apple", "banana", "cherry"};
size_t bucket = uset.bucket("apple");  // Номер корзины для "apple"
std::cout << "apple is in bucket: " << bucket << std::endl;
*/

/*
? bucket_size() – Возвращает количество элементов в заданной корзине
size_t elems_in_bucket = uset.bucket_size(bucket);
std::cout << "Bucket " << bucket << " has " << elems_in_bucket << " elements" << std::endl;
*/

/*
? max_load_factor() – Управление коэффициентом загрузки
std::unordered_set<int> num_set;
num_set.max_load_factor(0.5);  // Устанавливаем максимальный коэффициент загрузки
num_set.rehash(10);            // Рехешируем для оптимизации
*/

/*
? extract() (C++17) – Извлечение узла без переаллокации
Позволяет "вынуть" элемент из множества без разрушения, чтобы вставить в другое множество.

std::unordered_set<int> set1 {1, 2, 3};
std::unordered_set<int> set2;

auto node = set1.extract(1);  // Извлекаем узел с значением 1
if (!node.empty()) {
    set2.insert(std::move(node));  // Вставляем в set2
}
Вывод:
set1: {2, 3}, set2: {1}
*/

/*
? Конвертация в vector
std::unordered_set<int> uset = {3, 1, 4};
std::vector<int> vec(uset.begin(), uset.end());  // Порядок не гарантирован!
*/

/*
? Сортировка unordered_set
std::unordered_set<int> uset = {3, 1, 4};
std::set<int> sorted(uset.begin(), uset.end());  // {1, 3, 4}
*/