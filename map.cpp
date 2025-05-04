/*
? insert() – Добавление элемента
Добавляет пару ключ-значение в map.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    Способ 1: Через make_pair
    myMap.insert(std::make_pair(1, "Apple"));

    Способ 2: Через pair
    myMap.insert(std::pair<int, std::string>(2, "Banana"));

    Способ 3: Через {}
    myMap.insert({3, "Cherry"});

    Вывод
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
1: Apple
2: Banana
3: Cherry
*/

/*
? operator[] – Доступ или добавление элемента
Если ключ существует, возвращает значение. Если нет – создаёт новую пару.

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;

    ages["Alice"] = 25;   // Добавляем
    ages["Bob"] = 30;

    std::cout << "Alice's age: " << ages["Alice"] << std::endl; // Доступ

    Если ключа нет, он создаётся со значением по умолчанию (0 для int)
    std::cout << "Charlie's age: " << ages["Charlie"] << std::endl;

    return 0;
}
  Вывод:
Alice's age: 25
Charlie's age: 0
*/

/*
? find() – Поиск элемента
Возвращает итератор на найденный элемент или end(), если ключа нет.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};

    auto it = myMap.find(2);
    if (it != myMap.end()) {
        std::cout << "Found: " << it->second << std::endl;
    } else {
        std::cout << "Not found!" << std::endl;
    }

    return 0;
}
  Вывод:
Found: Two
*/

/*
? erase() – Удаление элемента
Удаляет элемент по ключу, итератору или диапазону.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "A"}, {2, "B"}, {3, "C"}};

    myMap.erase(2); // Удаление по ключу

    auto it = myMap.find(3);
    if (it != myMap.end()) {
        myMap.erase(it); // Удаление по итератору
    }

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
1: A
*/

/*
? size() – Размер map
Возвращает количество элементов.

#include <iostream>
#include <map>

int main() {
    std::map<char, int> letters = {{'a', 1}, {'b', 2}};
    std::cout << "Size: " << letters.size() << std::endl;

    return 0;
}
  Вывод:
Size: 2
*/

/*
? empty() – Проверка на пустоту
Возвращает true, если map пуст.

#include <iostream>
#include <map>

int main() {
    std::map<int, int> emptyMap;

    if (emptyMap.empty()) {
        std::cout << "Map is empty!" << std::endl;
    }

    return 0;
}
  Вывод:
Map is empty!
*/

/*
? clear() – Очистка map
Удаляет все элементы.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "A"}, {2, "B"}};
    myMap.clear();

    std::cout << "Size after clear: " << myMap.size() << std::endl;

    return 0;
}
  Вывод:
Size after clear: 0
*/

/*
? count() – Проверка наличия ключа
Возвращает 1 (если ключ есть) или 0 (если нет).

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> fruits = {{"apple", 10}, {"banana", 5}};

    std::cout << "Has 'apple': " << fruits.count("apple") << std::endl;
    std::cout << "Has 'mango': " << fruits.count("mango") << std::endl;

    return 0;
}
  Вывод:
Has 'apple': 1
Has 'mango': 0
*/

/*
? lower_bound() и upper_bound() – Поиск по диапазону
? lower_bound(key) – первый элемент, не меньший key.
? upper_bound(key) – первый элемент, больший key.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{10, "A"}, {20, "B"}, {30, "C"}};

    auto low = myMap.lower_bound(15); // Первый >= 15
    auto up = myMap.upper_bound(25);  // Первый > 25

    std::cout << "Lower bound of 15: " << low->first << std::endl;
    std::cout << "Upper bound of 25: " << up->first << std::endl;

    return 0;
}
  Вывод:
Lower bound of 15: 20
Upper bound of 25: 30
*/

/*
? emplace() – Эффективное добавление
Создает элемент на месте (без копирования).

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;

    myMap.emplace(1, "Apple");
    myMap.emplace(2, "Banana");

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
1: Apple
2: Banana
*/

/*
? swap() – Обмен содержимого
Меняет местами два map.

#include <iostream>
#include <map>

int main() {
    std::map<int, int> map1 = {{1, 10}, {2, 20}};
    std::map<int, int> map2 = {{3, 30}, {4, 40}};

    map1.swap(map2);

    std::cout << "map1 after swap:" << std::endl;
    for (const auto& pair : map1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
map1 after swap:
3: 30
4: 40
*/

/*
? max_size() – Максимально возможный размер
Возвращает теоретический максимум элементов.

#include <iostream>
#include <map>

int main() {
    std::map<int, int> myMap;
    std::cout << "Max size: " << myMap.max_size() << std::endl;

    return 0;
}
  Вывод (зависит от системы):
Max size: 461168601842738790
*/

/*
? equal_range() – Диапазон для ключа
Возвращает пару итераторов (lower_bound и upper_bound).

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{10, "A"}, {20, "B"}, {30, "C"}};

    auto range = myMap.equal_range(20);

    for (auto it = range.first; it != range.second; ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    return 0;
}
  Вывод:
20: B
*/

/*
? at() – Безопасный доступ
Возвращает значение по ключу с проверкой (бросает исключение, если ключа нет).

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap = {{"apple", 10}};

    try {
        std::cout << myMap.at("apple") << std::endl; // OK
        std::cout << myMap.at("banana") << std::endl; // Исключение
    } catch (const std::out_of_range& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
  Вывод:
10
Error: map::at
*/

/*
? operator= – Присваивание
Копирует содержимое другого map.

#include <iostream>
#include <map>

int main() {
    std::map<int, int> map1 = {{1, 10}, {2, 20}};
    std::map<int, int> map2;

    map2 = map1;

    for (const auto& pair : map2) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
1: 10
2: 20
*/

/*
? key_comp() и value_comp() – Компараторы
Возвращают функции сравнения.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap;
    auto keyCompare = myMap.key_comp();

    std::cout << "Compare 3 and 5: " << keyCompare(3, 5) << std::endl;

    return 0;
}
  Вывод:
Compare 3 and 5: 1
*/

/*
? merge() – Объединение двух map (C++17)
Переносит элементы из одного map в другой, если ключи не дублируются.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> map1 = {{1, "Apple"}, {2, "Banana"}};
    std::map<int, std::string> map2 = {{3, "Cherry"}, {4, "Date"}};

    map1.merge(map2); // Объединяем map2 в map1

    std::cout << "map1 after merge:" << std::endl;
    for (const auto& pair : map1) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::cout << "map2 size after merge: " << map2.size() << std::endl;

    return 0;
}
  Вывод:
map1 after merge:
1: Apple
2: Banana
3: Cherry
4: Date
map2 size after merge: 0
*/

/*
? extract() – Извлечение элемента (C++17)
Позволяет "вытащить" элемент из map без его уничтожения (например, для
перемещения в другой map).

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "One"}, {2, "Two"}};

    auto node = myMap.extract(1); // Извлекаем элемент с ключом 1

    if (!node.empty()) {
        std::cout << "Extracted: " << node.key() << " => " << node.mapped() <<
std::endl;
    }

    std::cout << "Map after extract:" << std::endl;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
Extracted: 1 => One
Map after extract:
2: Two
*/

/*
? try_emplace() – Безопасное добавление (C++17)
Пытается добавить элемент, если ключ ещё не существует (избегает лишних
копирований).

#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> myMap;

    myMap.try_emplace("Alice", 25); // Добавляется
    myMap.try_emplace("Alice", 30); // Игнорируется (ключ уже есть)

    std::cout << "Alice's age: " << myMap["Alice"] << std::endl;

    return 0;
}
  Вывод:
Alice's age: 25
*/

/*
? contains() – Проверка наличия ключа (C++20)
Возвращает true, если ключ есть в map (более удобная альтернатива count()).

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "A"}, {2, "B"}};

    if (myMap.contains(2)) {
        std::cout << "Key 2 exists!" << std::endl;
    }

    if (!myMap.contains(3)) {
        std::cout << "Key 3 does not exist." << std::endl;
    }

    return 0;
}
  Вывод:
Key 2 exists!
Key 3 does not exist.
*/

/*
? emplace_hint() – Добавление с подсказкой
Добавляет элемент с "подсказкой" (итератором), где предположительно должен быть
размещён новый элемент (может ускорить вставку).

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{10, "Ten"}, {20, "Twenty"}};

    auto hint = myMap.find(20); // Подсказка: вставить после 20
    myMap.emplace_hint(hint, 15, "Fifteen");

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
10: Ten
15: Fifteen
20: Twenty
*/

/*
? get_allocator() – Получение аллокатора
Возвращает аллокатор, используемый для выделения памяти в map (редко
используется в обычном коде).

#include <iostream>
#include <map>

int main() {
    std::map<int, int> myMap;
    auto allocator = myMap.get_allocator();

    Пример использования аллокатора (не рекомендуется без необходимости)
    int* p = allocator.allocate(1);
    *p = 42;
    std::cout << "Allocated value: " << *p << std::endl;
    allocator.deallocate(p, 1);

    return 0;
}
  Вывод:
Allocated value: 42
*/

/*
? map позволяет задать свою функцию сравнения ключей.

#include <iostream>
#include <map>

// Сортировка в обратном порядке
struct ReverseCompare {
    bool operator()(const int& a, const int& b) const {
        return a > b;
    }
};

int main() {
    std::map<int, std::string, ReverseCompare> myMap = {
        {1, "One"}, {2, "Two"}, {3, "Three"}
    };

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
  Вывод:
3: Three
2: Two
1: One
*/

/*
? == и != – Сравнение map
Проверяет, содержат ли два map одинаковые элементы.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> map1 = {{1, "A"}, {2, "B"}};
    std::map<int, std::string> map2 = {{1, "A"}, {2, "B"}};
    std::map<int, std::string> map3 = {{1, "X"}, {2, "Y"}};

    std::cout << "map1 == map2: " << (map1 == map2) << std::endl; // true
    std::cout << "map1 == map3: " << (map1 == map3) << std::endl; // false

    return 0;
}
  Вывод:
map1 == map2: 1
map1 == map3: 0
*/

/*
? std::erase_if() – Условное удаление (C++20)
Удаляет элементы, удовлетворяющие условию.

#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {
        {1, "A"}, {2, "B"}, {3, "C"}, {4, "D"}
    };

    Удаляем элементы с чётными ключами
    std::erase_if(myMap, [](const auto& pair) {
        return pair.first % 2 == 0;
    });

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
Вывод:
1: A
3: C
*/
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
  string potok;
  int deysvie;
  int id;
  string name;
  map<int, string> study;
  while (1) {
    cout << "Выберите действие:\n"
         << "1 - Добавить студента\n"
         << "2 - Найти студента по айди\n"
         << "3 - Удалить студента по айди\n"
         << "4 - Отобразить всех студентов\n"
         << "5 - Проверка на пустоту базы данных\n"
         << "6 - Очистить базу данных\n"
         << "7 - Вывести количество студентов из базы данных\n"
         << "0 - Завершить программу\n";
    cin >> deysvie;
    cin.ignore();
    if (deysvie == 1) {
      cout << "Введите айди и имя студента для добавления в базу:\n";
      getline(cin,potok);
      istringstream iss(potok);
      if(iss >> id >> name){
      if (study.count(id))
        cout << "Такой айди уже занят:\n";
      else
        study.emplace(id, name);
      }
      else
      cout<<"Ошибка ввода!\n";
    }

    if (deysvie == 2) {
      cout << "Введите айди студента для поиска по базе:\n";
      cin >> id;
      if (study.count(id)) {
        cout << "Студент найден: \n";
        auto iterator = study.find(id);
        cout << "id: " << iterator->first << "  name: " << iterator->second
             << '\n';
      } else
        cout << "Студент не найден\n";
    }

    if (deysvie == 3) {
      cout << "Введите айди студента для удаления из базы:\n";
      cin >> id;
      if (study.count(id)) {
        cout << "Студент найден и удален: \n";
        study.erase(id);
      } else
        cout << "Студент не найден\n";
    }

    if (deysvie == 4) {
      cout << "Студенты в базе данных:\n";
      for (auto i = study.begin(); i != study.end(); i++)
        cout << "id: " << i->first << "name: " << i->second << '\n';
    }

    if (deysvie == 5) {
      if (study.empty())
        cout << "База данных пустая\n";
      else
        cout << "База данных не пустая\n";
    }

    if (deysvie == 6) {
      study.clear();
      cout << "База данных удалена\n";
    }

    if (deysvie == 7)
      cout << "Количество студентов в базе: \n" << study.size() << '\n';

    if (deysvie == 0) {
      cout << "Программа завершила свою работу\n";
      break;
    }
  }
}
