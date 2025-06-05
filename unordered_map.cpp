/*
? insert() – Вставка элемента
Добавляет пару ключ-значение в контейнер.

#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<std::string, int> umap;
    / Вставка через make_pair
    umap.insert(std::make_pair("apple", 50));

    / Вставка через {}
    umap.insert({"banana", 30});

    / Вставка через operator[]
    umap["orange"] = 40;

    / Вывод
    for (const auto& pair : umap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
    Вывод:
    orange: 40
    banana: 30
    apple: 50
*/

/*
? operator[] – Доступ или вставка элемента
Если ключ существует, возвращает ссылку на значение. Если нет – создаёт новую пару.

std::unordered_map<std::string, int> umap;

umap["apple"] = 50;  // Вставка
umap["apple"] = 60;  // Обновление
std::cout << umap["apple"];  // 60
*/

/*
? at() – Доступ к элементу с проверкой
Бросает исключение std::out_of_range, если ключа нет.

std::unordered_map<std::string, int> umap = {{"apple", 50}};

try {
    std::cout << umap.at("apple");  // 50
    std::cout << umap.at("banana"); // Исключение!
} catch (const std::out_of_range& e) {
    std::cerr << "Key not found!" << std::endl;
}
*/

/*
? find() – Поиск элемента
Возвращает итератор на найденный элемент или end(), если ключа нет.

std::unordered_map<std::string, int> umap = {{"apple", 50}};

auto it = umap.find("apple");
if (it != umap.end()) {
    std::cout << "Found: " << it->second << std::endl;  // Found: 50
} else {
    std::cout << "Not found!" << std::endl;
}
*/

/*
? erase() – Удаление элемента
Можно удалять по ключу, итератору или диапазону.

std::unordered_map<std::string, int> umap = {
    {"apple", 50}, {"banana", 30}, {"orange", 40}
};

umap.erase("apple");  // Удаление по ключу

auto it = umap.find("banana");
if (it != umap.end()) {
    umap.erase(it);  // Удаление по итератору
}
*/

/*
? size() и empty() – Размер и проверка на пустоту

std::unordered_map<std::string, int> umap = {{"apple", 50}};
std::cout << umap.size();  // 1
std::cout << umap.empty(); // 0 (false)
*/

/*
? clear() – Очистка контейнера
std::unordered_map<std::string, int> umap = {{"apple", 50}};
umap.clear();
std::cout << umap.size();  // 0
*/

/*
? count() – Проверка наличия ключа
Возвращает 1 (есть) или 0 (нет).

std::unordered_map<std::string, int> umap = {{"apple", 50}};
std::cout << umap.count("apple");  // 1
std::cout << umap.count("banana"); // 0
*/

/*
? bucket_count() и load_factor() – Работа с хеш-таблицей

std::unordered_map<std::string, int> umap = {{"apple", 50}};
std::cout << umap.bucket_count();  // Число "корзин" (бакетов)
std::cout << umap.load_factor();   // Коэффициент заполнения (size / bucket_count)
*/

/*
? emplace() – Эффективная вставка
Создает элемент на месте (без копирования).
std::unordered_map<std::string, int> umap;
umap.emplace("apple", 50);  // Аналог insert, но эффективнее
*/

/*
? reserve() – Резервирование памяти
Задает минимальное количество бакетов.
std::unordered_map<std::string, int> umap;
umap.reserve(100);  // Резервируем место для 100 элементов
*/

/*
? bucket() – Получение номера бакета для ключа
Возвращает номер "корзины" (бакета), в которой находится элемент с указанным ключом.

std::unordered_map<std::string, int> umap = {{"apple", 50}, {"banana", 30}};
size_t bucket = umap.bucket("apple");
std::cout << "apple is in bucket: " << bucket << std::endl;
*/

/*
? bucket_size() – Размер бакета
Возвращает количество элементов в указанной "корзине".

std::unordered_map<std::string, int> umap = {{"apple", 50}, {"banana", 30}};
size_t bucket = umap.bucket("apple");
std::cout << "Bucket size: " << umap.bucket_size(bucket) << std::endl;
*/

/*
? rehash() – Изменение количества бакетов
Устанавливает новое количество бакетов в контейнере.

std::unordered_map<std::string, int> umap;
umap.rehash(20);  // Устанавливаем минимум 20 бакетов
*/

/*
? max_load_factor() – Управление коэффициентом заполнения
Позволяет узнать или установить максимальный коэффициент заполнения (отношение size() к bucket_count()).

std::unordered_map<std::string, int> umap;

/ Установка максимального коэффициента заполнения
umap.max_load_factor(0.7f);
std::cout << "Current load factor: " << umap.load_factor() << std::endl;
std::cout << "Max load factor: " << umap.max_load_factor() << std::endl;
*/

/*
? swap() – Обмен содержимым двух unordered_map
Меняет местами содержимое двух контейнеров.

std::unordered_map<std::string, int> umap1 = {{"apple", 50}};
std::unordered_map<std::string, int> umap2 = {{"banana", 30}};

umap1.swap(umap2);

std::cout << "umap1: ";
for (const auto& pair : umap1) {
    std::cout << pair.first << " ";  // banana
}

std::cout << "\numap2: ";
for (const auto& pair : umap2) {
    std::cout << pair.first << " ";  // apple
}
*/

/*
? extract() – Извлечение элемента (C++17)
Позволяет "извлечь" узел (node) из контейнера без его уничтожения.

std::unordered_map<std::string, int> umap = {{"apple", 50}, {"banana", 30}};

auto node = umap.extract("apple");
if (!node.empty()) {
    std::cout << "Extracted: " << node.key() << " -> " << node.mapped() <<
std::endl;
}
Теперь umap содержит только {"banana", 30}
*/

/*
? merge() – Слияние двух unordered_map (C++17)
Переносит элементы из одного unordered_map в другой.

std::unordered_map<std::string, int> umap1 = {{"apple", 50}};
std::unordered_map<std::string, int> umap2 = {{"banana", 30}};

umap1.merge(umap2);

umap1 теперь содержит {"apple", 50} и {"banana", 30}
umap2 пуст
*/

/*
? contains() – Проверка наличия ключа (C++20)
Более удобная замена count() для проверки наличия ключа.

std::unordered_map<std::string, int> umap = {{"apple", 50}};
if (umap.contains("apple")) {
    std::cout << "Found apple!" << std::endl;
}
*/

/*
? Метод try_emplace() (C++17)
Пытается вставить элемент, если ключ отсутствует. Возвращает итератор и флаг успеха:

std::unordered_map<std::string, int> umap = {{"apple", 50}};

/ Успешная вставка
auto [it1, inserted1] = umap.try_emplace("banana", 30);
std::cout << inserted1 << "\n"; // true

/ Неудачная вставка (ключ уже существует)
auto [it2, inserted2] = umap.try_emplace("apple", 100);
std::cout << inserted2 << "\n"; // false
std::cout << it2->second << "\n"; // 50 (старое значение)
*/

/*
? Метод insert_or_assign() (C++17)
Вставляет элемент или перезаписывает существующий:

std::unordered_map<std::string, int> umap;

/ Вставка нового элемента
umap.insert_or_assign("apple", 50);

/ Перезапись существующего
umap.insert_or_assign("apple", 60);
std::cout << umap["apple"] << "\n"; // 60
*/