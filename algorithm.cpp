/*
? std::sort – сортировка элементов
Сортирует элементы в диапазоне [first, last) в порядке возрастания (по
умолчанию) или с пользовательским компаратором.

std::sort(nums.begin(), nums.end());

Сортировка в обратном порядке:
std::sort(nums.begin(), nums.end(), std::greater<int>());
*/

/*
? std::find – поиск элемента
Ищет первое вхождение элемента и возвращает итератор на него. Если элемент не
найден, возвращает end().

auto it = std::find(nums.begin(), nums.end(), 8);

if (it != nums.end()) {
    std::cout << "Found: " << *it;  // Found: 8
} else {
    std::cout << "Not found";
}
*/

/*
? std::count – подсчёт элементов
Подсчитывает количество вхождений элемента.

std::vector<int> nums = {1, 2, 2, 3, 2, 4};
int cnt = std::count(nums.begin(), nums.end(), 2);
std::cout << cnt;  // 3
*/

/*
? std::reverse – обратный порядок
Переворачивает последовательность.

std::vector<int> nums = {1, 2, 3, 4, 5};
std::reverse(nums.begin(), nums.end()); // nums = {5, 4, 3, 2, 1}
*/

/*
? std::max_element и std::min_element – поиск максимума и минимума
Возвращают итератор на максимальный/минимальный элемент.

std::vector<int> nums = {5, 2, 8, 1, 3};
auto max_it = std::max_element(nums.begin(), nums.end());
auto min_it = std::min_element(nums.begin(), nums.end());

std::cout << "Max: " << *max_it;  // 8
std::cout << "Min: " << *min_it;  // 1
*/

/*
? std::accumulate – сумма элементов
Вычисляет сумму (или другую операцию) элементов.

! #include <numeric> // для accumulate
! Без <numeric> код не скомпилируется

std::vector<int> nums = {1, 2, 3, 4, 5};
int sum = std::accumulate(nums.begin(), nums.end(), 0);
std::cout << sum;  // 15

С умножением (начальное значение 1)
int product = std::accumulate(nums.begin(), nums.end(), 1,
std::multiplies<int>()); std::cout << product;  // 120 (1*2*3*4*5)
*/

/*
? std::binary_search – бинарный поиск
! Если вектор не отсортирован, то вызов std::binary_search приведёт к неопределённому поведению
! Алгоритм может:
TODO Вернуть false, даже если элемент присутствует
TODO Вернуть true для отсутствующего элемента
TODO Завершить программу аварийно
TODO Выдать любой другой непредсказуемый результат

std::vector<int> nums = {1, 2, 3, 4, 5};
bool found = std::binary_search(nums.begin(), nums.end(), 3);
std::cout << found;  // true
*/

/*
? std::copy – копирование элементов
Копирует элементы из одного диапазона в другой.

std::vector<int> src = {1, 2, 3, 4, 5};
std::vector<int> dst(5); // вектор из 5 элементов

std::copy(src.begin(), src.end(), dst.begin()); // dst = {1, 2, 3, 4, 5}
*/

/*
? std::fill – заполнение диапазона значением
Заполняет диапазон указанным значением.

std::vector<int> nums(5); // вектор из 5 нулей
std::fill(nums.begin(), nums.end(), 42); // nums = {42, 42, 42, 42, 42}
*/

/*
? std::replace – замена элементов
Заменяет все вхождения одного значения на другое.

std::vector<int> nums = {1, 2, 3, 2, 5};
std::replace(nums.begin(), nums.end(), 2, 99); // nums = {1, 99, 3, 99, 5}
*/

/*
? std::remove – удаление элементов
"Удаляет" элементы, равные заданному значению (на самом деле сдвигает их в
конец).

std::vector<int> nums = {1, 2, 3, 2, 5};
auto new_end = std::remove(nums.begin(), nums.end(), 2);
nums.erase(new_end, nums.end()); // реальное удаление // nums = {1, 3, 5}
*/

/*
? std::unique – удаление дубликатов
Удаляет соседние дубликаты (перед использованием нужно отсортировать).

std::vector<int> nums = {1, 2, 2, 3, 3, 3, 4};
auto last = std::unique(nums.begin(), nums.end());
nums.erase(last, nums.end()); // nums = {1, 2, 3, 4}
*/

/*
? std::transform – применение функции к каждому элементу
Применяет функцию к каждому элементу и сохраняет результат.

std::vector<int> nums = {1, 2, 3, 4, 5};
std::vector<int> squared(nums.size());

std::transform(nums.begin(), nums.end(), squared.begin(), [](int x) {
    return x * x;
}); // squared = {1, 4, 9, 16, 25}
*/

/*
? std::any_of, std::all_of, std::none_of – проверка условий
Проверяют, выполняется ли условие для элементов.

std::vector<int> nums = {1, 2, 3, 4, 5};

bool any_even = std::any_of(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; });
bool all_positive = std::all_of(nums.begin(), nums.end(), [](int x) { return x > 0; });
bool none_negative = std::none_of(nums.begin(), nums.end(), [](int x) { return x < 0; });

std::cout << any_even;      // true (есть чётные)
std::cout << all_positive;  // true (все положительные)
std::cout << none_negative; // true (нет отрицательных)
*/

/*
? std::shuffle – случайное перемешивание
Перемешивает элементы в случайном порядке.

#include <algorithm>
#include <random>

std::vector<int> nums = {1, 2, 3, 4, 5};
std::random_device rd;
std::mt19937 gen(rd());

std::shuffle(nums.begin(), nums.end(), gen); // nums = {3, 1, 5, 2, 4} (случайный порядок)
*/

/*
? std::merge – слияние двух отсортированных диапазонов
Объединяет два отсортированных диапазона в один (результат также будет отсортирован).
! Если векторы не отсортированы, то std::merge формально сработает
! но результат будет непредсказуемым и, скорее всего, некорректным.

  std::vector<int> v1 = {1, 3, 5};
  std::vector<int> v2 = {2, 4, 6};
  std::vector<int> result(v1.size() + v2.size());

  std::merge(v1.begin(), v1.end(), v2.begin(), v2.end(), result.begin());

  for (int num : result) {
      std::cout << num << " ";  // 1 2 3 4 5 6
    }
*/

/*
? std::set_union, std::set_intersection, std::set_difference – операции с множествами
Работают с отсортированными диапазонами.
! с неотсортированными диапазонами формально приведёт к неопределённому поведению (UB)
! хотя на практике чаще всего вы получите некорректный результат без ошибок компиляции.

TODO set_union – объединение множеств
std::vector<int> a = {1, 2, 3, 4};
std::vector<int> b = {3, 4, 5, 6};
std::vector<int> union_result(a.size() + b.size());

auto it = std::set_union(a.begin(), a.end(), b.begin(), b.end(),
union_result.begin()); union_result.resize(it - union_result.begin()); // union_result = {1, 2, 3, 4, 5, 6}

TODO set_intersection – пересечение множеств
std::vector<int> intersection_result(a.size() + b.size());
it = std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), intersection_result.begin());
intersection_result.resize(it - intersection_result.begin()); // intersection_result = {3, 4}

TODO set_difference – разность множеств (A ∖ B)
std::vector<int> difference_result(a.size() + b.size());
it = std::set_difference(a.begin(), a.end(), b.begin(), b.end(), difference_result.begin());
difference_result.resize(it - difference_result.begin()); // difference_result = {1, 2}
*/

/*
? std::partition – разделение по условию
Переупорядочивает элементы так, чтобы сначала шли элементы, удовлетворяющие
условию, а затем остальные.

std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

auto it = std::partition(nums.begin(), nums.end(), [](int x) {
    return x % 2 == 0;  // чётные числа в начало
}); // nums = {2, 4, 6, 8, 1, 3, 5, 7, 9} (порядок не гарантируется)
*/

/*
? std::rotate – циклический сдвиг
Сдвигает элементы так, что middle становится первым элементом.

std::vector<int> nums = {1, 2, 3, 4, 5};
std::rotate(nums.begin(), nums.begin() + 2, nums.end()); // nums = {3, 4, 5, 1, 2}
*/

/*
? std::next_permutation и std::prev_permutation – перестановки
Генерируют следующую/предыдущую перестановку в лексикографическом порядке.

std::vector<int> nums = {1, 2, 3};
do {
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "\n";
} while (std::next_permutation(nums.begin(), nums.end()));

Вывод:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/

/*
? std::partial_sort – частичная сортировка
Сортирует только первые k элементов.

std::vector<int> nums = {5, 2, 8, 1, 3, 7, 4};
/ Сортируем первые 3 элемента
std::partial_sort(nums.begin(), nums.begin() + 3, nums.end()); // nums = {1, 2, 3, 8, 5, 7, 4}
*/

/*
? std::nth_element – нахождение n-го элемента
Переупорядочивает диапазон так, что n-й элемент занимает правильную позицию (как
в отсортированном массиве).

std::vector<int> nums = {5, 2, 8, 1, 3, 7, 4};
/ Находим 3-й по величине элемент
std::nth_element(nums.begin(), nums.begin() + 2, nums.end());
std::cout << nums[2];  // 3 (так как {1, 2, 3, ...})
*/

/*
? std::minmax_element – минимальный и максимальный элемент
Возвращает пару итераторов на минимальный и максимальный элементы.

std::vector<int> nums = {5, 2, 8, 1, 3};
auto [min_it, max_it] = std::minmax_element(nums.begin(), nums.end());
std::cout << "Min: " << *min_it << ", Max: " << *max_it;  // Min: 1, Max: 8
*/

/*
? std::is_sorted – проверка на отсортированность
Проверяет, отсортирован ли диапазон.

std::vector<int> nums1 = {1, 2, 3, 4, 5};
std::vector<int> nums2 = {5, 3, 1, 4, 2};

bool sorted1 = std::is_sorted(nums1.begin(), nums1.end());  // true
bool sorted2 = std::is_sorted(nums2.begin(), nums2.end());  // false
*/

/*
? std::clamp – ограничение значения в диапазоне
Возвращает значение, "зажатое" между low и high.

int x = 15;
int y = std::clamp(x, 10, 20);  // y=15 (остаётся)
int z = std::clamp(x, 1, 5);    // z=5 (ограничено сверху)
*/

/*
? std::sample – случайная выборка элементов
Выбирает n случайных элементов из диапазона.

#include <random>
std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> sampled(3);  // выборка из 3 элементов
std::random_device rd;

std::sample(nums.begin(), nums.end(), sampled.begin(), 3, std::mt19937(rd())); // sampled = {2, 5, 9} (случайный выбор)
*/

/*
? std::for_each – применение функции к каждому элементу
! Аналог transform, но без сохранения результата. Не возвращает новый модифицированный контейнер
TODO std::for_each - Ничего (void)
TODO std::transform - 	Новый итератор или контейнер

std::vector<int> nums = {1, 2, 3, 4, 5};

std::for_each(nums.begin(), nums.end(), [](int& x) {
    x *= 2;  // умножаем каждый элемент на 2
}); // nums = {2, 4, 6, 8, 10}
*/

/*
? std::adjacent_find – поиск соседних дубликатов
Находит первую пару одинаковых соседних элементов.

std::vector<int> nums = {1, 2, 3, 3, 4, 5, 5};

auto it = std::adjacent_find(nums.begin(), nums.end());
if (it != nums.end()) {
    std::cout << "Duplicate: " << *it;  // Duplicate: 3
}
*/

/*
? std::lexicographical_compare – лексикографическое сравнение
Сравнивает два диапазона как строки в словаре.

std::string s1 = "apple";
std::string s2 = "banana";

bool is_less = std::lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
std::cout << is_less;  // true ("apple" < "banana")
*/

/*
? std::iota – заполнение последовательными значениями
Заполняет диапазон числами value, value+1, value+2, ...

#include <numeric>
std::vector<int> nums(5);
std::iota(nums.begin(), nums.end(), 10); // nums = {10, 11, 12, 13, 14}
*/

/*
? std::mismatch - поиск первого различия между двумя последовательностями
Возвращает пару итераторов к первому несовпадающему элементу в двух диапазонах.

std::vector<int> v1 = {1, 2, 3, 4, 5};
std::vector<int> v2 = {1, 2, 4, 4, 5};

auto result = std::mismatch(v1.begin(), v1.end(), v2.begin());
if (result.first != v1.end()) {
std::cout << "First mismatch at position "
<< std::distance(v1.begin(), result.first)
<< ": " << *result.first << " vs " << *result.second; // Выведет: First mismatch at position 2: 3 vs 4
*/

/*
? std::search - поиск подпоследовательности
Ищет первое вхождение одной последовательности внутри другой.

std::vector<int> data = {1, 2, 3, 4, 5, 1, 2, 3};
std::vector<int> pattern = {1, 2, 3};

auto it = std::search(data.begin(), data.end(), pattern.begin(), pattern.end());
if (it != data.end()) {
    std::cout << "Pattern found at position " << std::distance(data.begin(),
it); // Pattern found at position 0
}
*/

/*
? std::copy_if - копирование с условием
Копирует только элементы, удовлетворяющие предикату.

std::vector<int> src = {1, 2, 3, 4, 5, 6};
std::vector<int> dst;
std::copy_if(src.begin(), src.end(), std::back_inserter(dst),[](int x) { return x % 2 == 0; }); // dst = {2, 4, 6}
*/

/*
? std::generate - заполнение с помощью генератора
Заполняет диапазон значениями, возвращаемыми функцией.

std::vector<int> nums(5);
int counter = 1;
std::generate(nums.begin(), nums.end(), [&counter]() { return counter *= 2; }); // nums = {2, 4, 8, 16, 32}
*/

/*
? std::includes - проверка вхождения одного отсортированного диапазона в другой
Проверяет, содержит ли один отсортированный диапазон все элементы другого.

std::vector<int> v1 = {1, 2, 3, 4, 5};
std::vector<int> v2 = {2, 3, 5};
bool contains = std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());
std::cout << std::boolalpha << contains; // true
*/

/*
? std::inplace_merge - слияние с сортировкой
Объединяет две отсортированные части одного диапазона. быстрее чем std::sort
! Если части вектора не отсортированы, то std::inplace_merge даст некорректный результат
! так как алгоритм рассчитан на работу с уже отсортированными поддиапазонами.

std::vector<int> v = {1, 3, 5, 2, 4, 6};
auto mid = v.begin() + 3; // Граница между отсортированными частями
std::inplace_merge(v.begin(), mid, v.end()); // v = {1, 2, 3, 4, 5, 6}
*/

/*
? std::equal_range - поиск диапазона равных элементов
Для отсортированного диапазона находит поддиапазон, где встречается заданное
значение.

std::vector<int> v = {1, 2, 2, 2, 3, 4, 5};
auto bounds = std::equal_range(v.begin(), v.end(), 2);

std::cout << "2 appears from position " << std::distance(v.begin(),
bounds.first)
<< " to " << std::distance(v.begin(), bounds.second) - 1; // Выведет: 2 appears from position 1 to 3
*/

/*
? std::is_heap и std::make_heap - работа с кучей
Проверка и создание структуры данных "куча".

std::vector<int> v = {9, 5, 7, 1, 3, 2};

bool is_heap = std::is_heap(v.begin(), v.end()); // false
std::make_heap(v.begin(), v.end()); // Преобразует в кучу
is_heap = std::is_heap(v.begin(), v.end()); // true
*/

/*
? std::gcd и std::lcm - НОД и НОК
Наибольший общий делитель и наименьшее общее кратное (C++17).

#include <numeric>
std::cout << std::gcd(24, 36); // 12
std::cout << std::lcm(15, 20); // 60
*/

/*
? std::reduce - параллельное суммирование
Аналог accumulate, но может выполняться параллельно (C++17).

std::vector<int> v = {1, 2, 3, 4, 5};
int sum = std::reduce(v.begin(), v.end(), 0);
std::cout << sum; // 15
*/

/*
? std::transform_reduce - преобразование с сокращением
Комбинация transform и reduce (C++17).

std::vector<int> v = {1, 2, 3, 4, 5};
int result = std::transform_reduce(v.begin(), v.end(),0,std::plus<>(),[](int x) { return x * x; });
std::cout << result; // 1+4+9+16+25 = 55
*/

/*
? std::shift_left и std::shift_right - сдвиг элементов
Сдвигают элементы в диапазоне (C++20).

std::vector<int> v = {1, 2, 3, 4, 5};
std::shift_left(v.begin(), v.end(), 2); // v = {3, 4, 5, 4, 5} (первые два элемента "вышли")

std::shift_right(v.begin(), v.end(), 1); // v = {3, 3, 4, 5, 5}
*/

/*
? std::starts_with и std::ends_with - проверка начала/конца строки
Проверяют, начинается или заканчивается ли строка на заданную подстроку (C++20).

std::string s = "Hello world";
bool starts = s.starts_with("Hello"); // true
bool ends = s.ends_with("planet");    // false
*/

/*
? std::midpoint - середина между двумя числами
Вычисляет среднее значение без переполнения (C++20).

int a = 2'000'000'000;
int b = 2'000'000'002;
std::cout << std::midpoint(a, b); // 2'000'000'001
*/

/*
? std::lerp - линейная интерполяция
Вычисляет значение между двумя числами (C++20).

float start = 10.0f;
float end = 20.0f;
std::cout << std::lerp(start, end, 0.5f); // 15.0
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class study {
    public:
  string name;
  int age;
  double grage;
  bool operator<(study& tmp){
    return name<tmp.name;
  }

};

int main() {
  vector<study> base ={
  {"Alice", 20, 4.5},
  {"Bob", 22, 3.8},
  {"Charlie", 21, 4.2},
  {"David", 23, 3.9},
  {"Eve", 20, 4.7}
  };

  sort(base.begin(),base.end(),[](study a,study b){return a.age<b.age;});
  for(int i=0;i<base.size();i++)
  {
    cout<<base[i].name<<'\t'<<base[i].age<<'\t'<<base[i].grage<<'\n';
  }
  cout<<'\n';

  sort(base.begin(),base.end(),[](study a,study b){return a.grage<b.grage;});
  for(int i=0;i<base.size();i++)
  {
    cout<<base[i].name<<'\t'<<base[i].age<<'\t'<<base[i].grage<<'\n';
  }
  cout<<'\n';

  auto tmp=find_if(base.begin(),base.end(),[](study a){return a.name=="Bob";});
  cout<<tmp->name<<'\t'<<tmp->age<<'\t'<<tmp->grage<<'\n'<<'\n';

  bool flag=any_of(base.begin(),base.end(),[](study a){return a.age==18;});
  cout<<flag<<'\n'<<'\n';

  int z=count_if(base.begin(),base.end(),[](study a){return a.grage>4;});
  cout << z << '\n' << '\n';

  for_each(base.begin(),base.end(),[](study& a){a.age++;});
  for(int i=0;i<base.size();i++)
  {
    cout<<base[i].name<<'\t'<<base[i].age<<'\t'<<base[i].grage<<'\n';
  }
  cout<<'\n';

  replace_if(base.begin(),base.end(),[](study& a){return a.grage==3.9;},study{"Non",0,4});
  for(int i=0;i<base.size();i++)
  {
    cout<<base[i].name<<'\t'<<base[i].age<<'\t'<<base[i].grage<<'\n';
  }
  cout<<'\n';

  vector<study> base2={
    {"Anna",18,3},
    {"Liza",24,3.4},
    {"Gosha",23,2},
    {"Sveta",20,5}
  };
  vector<study> bigbase;

  sort(base.begin(),base.end(),[](study& a,study& b){return a.name<b.name;});
  sort(base2.begin(),base2.end(),[](study& a,study& b){return a.name<b.name;});
  merge(base.begin(), base.end(), base2.begin(), base2.end(), back_inserter(bigbase));
  for(size_t i=0;i<bigbase.size();i++)
  {
    cout<<bigbase[i].name<<'\t'<<bigbase[i].age<<'\t'<<bigbase[i].grage<<'\n';
  }
  cout<<'\n';

  tmp=max_element(bigbase.begin(), bigbase.end(),[](study a,study b){return a.grage<b.grage;});
  cout << tmp->name << '\t' << tmp->age << '\t' << tmp->grage << '\n' << '\n';

  tmp=min_element(bigbase.begin(), bigbase.end(),[](study a,study b){return a.grage<b.grage;});
  cout << tmp->name << '\t' << tmp->age << '\t' << tmp->grage << '\n' << '\n';

  vector<study> minibase ={
    {"Alis",30,3},
    {"Grisha",25,5},
    {"Mari",28,2}
  };
  do
  {
  for(size_t i=0;i<minibase.size();i++)
  {
    cout<<minibase[i].name<<'\t'<<minibase[i].age<<'\t'<<minibase[i].grage<<'\n';
  }
  cout<<'\n';
  }while((next_permutation(minibase.begin(),minibase.end(),[](study& a,study& b){return a.name<b.name;})));

  flag=true;
  flag=all_of(bigbase.begin(),bigbase.end(),[](study& a){return a.grage==3;});
  cout<<flag<<'\n';
}