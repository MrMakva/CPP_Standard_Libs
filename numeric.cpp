/*
? std::accumulate – сумма или произведение элементов

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    / Сумма элементов (по умолчанию)
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum: " << sum << std::endl;  // 15

    / Произведение элементов (начальное значение 1)
    int product = std::accumulate(nums.begin(), nums.end(), 1,
                                  [](int a, int b) { return a * b; });
    std::cout << "Product: " << product << std::endl;  // 120
}
*/

/*
? std::inner_product – скалярное произведение

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {4, 5, 6};

    / Скалярное произведение (1*4 + 2*5 + 3*6)
    int dot_product = std::inner_product(a.begin(), a.end(), b.begin(), 0);
    std::cout << "Dot product: " << dot_product << std::endl;  // 32
}
*/

/*
? std::partial_sum – частичные суммы

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());
    
    std::partial_sum(nums.begin(), nums.end(), result.begin());
    
    for (int x : result) {
        std::cout << x << " ";  // 1 3 6 10 15
    }
}
*/

/*
? std::adjacent_difference – разница между соседями

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 4, 7, 11};
    std::vector<int> result(nums.size());
    
    std::adjacent_difference(nums.begin(), nums.end(), result.begin());
    
    for (int x : result) {
        std::cout << x << " ";  // 1 1 2 3 4 (первый элемент остается)
    }
}
*/

/*
? std::iota – заполнение последовательными значениями

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums(5);
    
    std::iota(nums.begin(), nums.end(), 10);  // Начинаем с 10
    
    for (int x : nums) {
        std::cout << x << " ";  // 10 11 12 13 14
    }
}
*/

/*
? std::gcd (C++17) – наибольший общий делитель

#include <iostream>
#include <numeric>

int main() {
    int a = 36, b = 60;
    int greatest_common_divisor = std::gcd(a, b);
    std::cout << "GCD: " << greatest_common_divisor << std::endl;  // 12
}
*/

/*
? std::lcm (C++17) – наименьшее общее кратное

#include <iostream>
#include <numeric>

int main() {
    int a = 6, b = 8;
    int least_common_multiple = std::lcm(a, b);
    std::cout << "LCM: " << least_common_multiple << std::endl;  // 24
}
*/

/*
? std::reduce (C++17) – параллельное суммирование

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int sum = std::reduce(nums.begin(), nums.end(), 0);
    std::cout << "Sum: " << sum << std::endl;  // 15
}
*/

/*
? std::transform_reduce (C++17) – комбинация transform + reduce

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};

    / Вычисляем сумму квадратов
    int sum_squares = std::transform_reduce(
        nums.begin(), nums.end(), 0, std::plus<>(),
        [](int x) { return x * x; }
    );

    std::cout << "Sum of squares: " << sum_squares << std::endl;  // 55
}
*/

/*
? std::inclusive_scan (включающий scan) Каждый элемент результата включает текущий элемент.

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());

    std::inclusive_scan(nums.begin(), nums.end(), result.begin());

    for (int x : result) {
        std::cout << x << " ";  // 1 3 6 10 15 (аналогично partial_sum)
    }
}
*/

/*
? std::exclusive_scan (исключающий scan) Каждый элемент результата не включает текущий элемент.

#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());

    / Начальное значение 0, текущий элемент не включается
    std::exclusive_scan(nums.begin(), nums.end(), result.begin(), 0);

    for (int x : result) {
        std::cout << x << " ";  // 0 1 3 6 10
    }
}
*/

/*
? std::transform_inclusive_scan и std::transform_exclusive_scan (C++17)
Эти функции комбинируют transform и scan, позволяя применять операцию к
элементам перед вычислением частичных сумм.

todo Пример с std::transform_inclusive_scan
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());

    / Вычисляем частичные суммы квадратов
    std::transform_inclusive_scan(
        nums.begin(), nums.end(),
        result.begin(),
        std::plus<>(),
        [](int x) { return x * x; }  // Квадрат элемента
    );

    for (int x : result) {
        std::cout << x << " ";  // 1 5 14 30 55 (1, 1+4, 1+4+9, ...)
    }
}

todo Пример с std::transform_exclusive_scan
#include <iostream>
#include <numeric>
#include <vector>

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());

    / Частичные суммы квадратов (исключая текущий элемент)
    std::transform_exclusive_scan(
        nums.begin(), nums.end(),
        result.begin(),
        0,  // Начальное значение
        std::plus<>(),
        [](int x) { return x * x; }
    );

    for (int x : result) {
        std::cout << x << " ";  // 0 1 5 14 30
    }
}
*/

/*
? std::midpoint (C++20) – середина между двумя числами
Вычисляет среднее значение двух чисел без переполнения.

#include <iostream>
#include <numeric>

int main() {
    int a = 10, b = 20;
    std::cout << std::midpoint(a, b) << std::endl;  // 15

    / Работает и с указателями!
    int arr[] = {1, 2, 3, 4, 5};
    int* p1 = &arr[0];
    int* p2 = &arr[4];
    std::cout << *std::midpoint(p1, p2) << std::endl;  // 3
}
*/

/*
? std::lerp (C++20) – линейная интерполяция
Вычисляет значение между a и b по параметру t (где t ∈ [0, 1]):
lerp(a, b, t) = a + t * (b - a).

#include <iostream>
#include <numeric>

int main() {
    float a = 10.0f, b = 20.0f;
    std::cout << std::lerp(a, b, 0.5f) << std::endl;  // 15.0
    std::cout << std::lerp(a, b, 0.0f) << std::endl;  // 10.0
    std::cout << std::lerp(a, b, 1.0f) << std::endl;  // 20.0
}
*/

#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int main()
{
    vector<int> data={1,2,5,7,3,9,6,4,10,8};
    vector<int> base={10,20,30,40,50};
    vector<int> rezult(data.size());
    int tmp = accumulate(data.begin(),data.end(),0);
    cout<<tmp<<'\n';

    tmp = inner_product(data.begin(),data.end(),base.begin(),0);
    cout << tmp << '\n';

    partial_sum(data.begin(),data.end(),rezult.begin());
    for(auto i=rezult.begin();i!=rezult.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    vector<int> sqeue(5);
    iota(sqeue.begin(),sqeue.end(),10);
    for(auto i=sqeue.begin();i!=sqeue.end();i++)
    cout<<*i<<' ';
    cout<<'\n';

    tmp = gcd(10,15);
    cout << tmp << '\n';

    tmp=lcm(3,4);
    cout << tmp << '\n';

    tmp =transform_reduce(data.begin(),data.end(),0,plus<>(),[](int x){return x*x;});
    cout << tmp << '\n';
}