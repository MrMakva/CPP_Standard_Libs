/*
todo unordered_multiset - это ассоциативный контейнер, который хранит набор
элементов без определенного порядка, позволяя дубликаты. Он реализован как
хеш-таблица.

! unordered_multise находится в библеотеки unordered_set
*/

/*
? Создание и инициализация

#include <iostream>
#include <unordered_set>

int main() {
    / Пустой unordered_multiset
    std::unordered_multiset<int> ums1;
    
    / Инициализация списком
    std::unordered_multiset<int> ums2 = {1, 2, 3, 2, 4, 3, 5};
    
    / Копирование из другого unordered_multiset
    std::unordered_multiset<int> ums3(ums2);
    
    / С указанием размера хеш-таблицы
    std::unordered_multiset<int> ums4(10);
    
    / С указанием размера хеш-таблицы и функции хеширования
    std::unordered_multiset<int> ums5(10, std::hash<int>());
    return 0;
}
*/

/*
? Вставка элементов
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums;
    
    / insert() - вставка элемента
    ums.insert(10);
    ums.insert(20);
    ums.insert(30);
    ums.insert(20); // Дубликаты разрешены
    
    / insert() с подсказкой позиции
    auto hint = ums.begin();
    ums.insert(hint, 15);
    
    / insert() диапазона из другого контейнера
    std::vector<int> vec = {5, 10, 15};
    ums.insert(vec.begin(), vec.end());
    
    / emplace() - создание элемента на месте
    ums.emplace(25);
    
    for (int n : ums) {
        std::cout << n << " ";
    }
   return 0;
}
*/

/*
? Доступ к элементам
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {1, 2, 3, 2, 4, 3, 5};
    
    / count() - количество элементов с заданным ключом
    std::cout << "Count of 2: " << ums.count(2) << std::endl;
    
    / find() - поиск элемента (возвращает итератор)
    auto it = ums.find(3);
    if (it != ums.end()) {
        std::cout << "Found: " << *it << std::endl;
    }
    
    / equal_range() - диапазон элементов с заданным ключом
    auto range = ums.equal_range(3);
    for (auto i = range.first; i != range.second; ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/

/*
? Размер и емкость
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {1, 2, 3, 2, 4, 3, 5};
    
    std::cout << "Size: " << ums.size() << std::endl;
    std::cout << "Max size: " << ums.max_size() << std::endl;
    std::cout << "Empty: " << (ums.empty() ? "true" : "false") << std::endl;
    
    return 0;
}
*/

/*
? Удаление элементов
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {1, 2, 3, 2, 4, 3, 5};
    
    / erase() по ключу - удаляет все элементы с этим ключом
    ums.erase(2); // Удалит все двойки
    
    / erase() по итератору
    auto it = ums.find(3);
    if (it != ums.end()) {
        ums.erase(it); // Удалит только один элемент 3
    }
    
    / erase() диапазон
    ums.erase(ums.begin(), ums.find(4)); // Удалит все до первого 4
    / clear() - удалить все элементы
    ums.clear();
    return 0;
}
*/

/*
? Обход элементов
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {1, 2, 3, 2, 4, 3, 5};
    
    / Итераторы
    std::cout << "Elements: ";
    for (auto it = ums.begin(); it != ums.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    / Range-based for loop
    std::cout << "Elements: ";
    for (int n : ums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/

/*
? Управление хеш-таблицей
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums = {1, 2, 3, 2, 4, 3, 5};
    
    / bucket_count() - количество корзин
    std::cout << "Bucket count: " << ums.bucket_count() << std::endl;
    
    / max_bucket_count() - максимальное количество корзин
    std::cout << "Max bucket count: " << ums.max_bucket_count() << std::endl;
    
    / bucket_size() - количество элементов в корзине
    for (size_t i = 0; i < ums.bucket_count(); ++i) {
        std::cout << "Bucket " << i << " size: " << ums.bucket_size(i) << std::endl;
    }
    
    / bucket() - корзина, в которой находится элемент
    std::cout << "Element 3 is in bucket: " << ums.bucket(3) << std::endl;
    
    / load_factor() - коэффициент загрузки
    std::cout << "Load factor: " << ums.load_factor() << std::endl;
    
    / max_load_factor() - максимальный коэффициент загрузки
    std::cout << "Max load factor: " << ums.max_load_factor() << std::endl;
    
    / rehash() - изменение количества корзин
    ums.rehash(20);
    std::cout << "New bucket count after rehash: " << ums.bucket_count() << std::endl;
    
    / reserve() - резервирование места
    ums.reserve(50);
    return 0;
}
*/

/*
? Сравнение multiset
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums1 = {1, 2, 3};
    std::unordered_multiset<int> ums2 = {3, 2, 1, 1};
    
    / Операторы сравнения
    if (ums1 == ums2) {
        std::cout << "ums1 and ums2 are equal" << std::endl;
    } else {
        std::cout << "ums1 and ums2 are not equal" << std::endl;
    }
    
    return 0;
}
*/

/*
? Обмен содержимого
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums1 = {1, 2, 3};
    std::unordered_multiset<int> ums2 = {4, 5, 6};

    / swap()
    ums1.swap(ums2);

    std::cout << "ums1: ";
    for (int n : ums1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::cout << "ums2: ";
    for (int n : ums2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    return 0;
}
*/

/*
? Получение аллокатора
#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_multiset<int> ums;

    / get_allocator()
    auto alloc = ums.get_allocator();

    / Пример использования аллокатора
    int* p = alloc.allocate(1);
    alloc.construct(p, 42);
    std::cout << *p << std::endl;
    alloc.destroy(p);
    alloc.deallocate(p, 1);
    return 0;
}
*/