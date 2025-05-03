/*
? std::atomic<T> — базовый шаблонный класс
Позволяет создавать атомарные переменные типа T (целые числа, указатели и т. д.).

#include <atomic>
#include <iostream>
int main() {
    std::atomic<int> counter(0);   атомарная переменная
    counter.store(10);             запись значения
    int value = counter.load();    чтение значения
    std::cout << "Counter: " << value << std::endl;   Вывод: Counter: 10
    return 0;
}
*/

/*
? store() — атомарная запись
Записывает значение в атомарную переменную.

std::atomic<int> x(0);
x.store(42);  // атомарно записываем 42
*/

/*
? load() — атомарное чтение
Читает значение атомарной переменной.

std::atomic<int> x(42);
int val = x.load();  // атомарно читаем значение
std::cout << "x = " << val << std::endl;  // Вывод: x = 42
*/

/*
? exchange() — атомарный обмен
Заменяет значение атомарной переменной и возвращает старое.

std::atomic<int> x(10);
int old = x.exchange(20);  // x становится 20, old = 10
std::cout << "Old: " << old << ", New: " << x.load() << std::endl;
Вывод: Old: 10, New: 20
*/

/*
? compare_exchange_weak() и compare_exchange_strong() — условная замена
Сравнивает текущее значение с ожидаемым и заменяет его, если они совпадают.

std::atomic<int> x(100);
int expected = 100;
bool success = x.compare_exchange_weak(expected, 200);  // Если x == 100, то x =
200 std::cout << "Success: " << success << ", x = " << x << std::endl;
Вывод: Success: 1, x = 200
*/

/*
? fetch_add() и fetch_sub() — атомарное сложение/вычитание
Добавляет или вычитает значение и возвращает старое.

std::atomic<int> counter(0);
int old = counter.fetch_add(5);  // counter += 5, возвращает 0
std::cout << "Old: " << old << ", New: " << counter << std::endl;
Вывод: Old: 0, New: 5
*/

/*
? fetch_and(), fetch_or(), fetch_xor() — побитовые операции
Атомарные побитовые AND, OR, XOR.

std::atomic<int> flags(0b1100);
int old = flags.fetch_and(0b1010);  // flags &= 0b1010
std::cout << "New flags: " << flags << std::endl;  // Вывод: 8 (0b1000)
*/

/*
? std::atomic_flag — простейший атомарный флаг
Используется для простых блокировок.

#include <atomic>
#include <thread>

std::atomic_flag lock = ATOMIC_FLAG_INIT;
void worker() {
    while (lock.test_and_set(std::memory_order_acquire)) {}  // Ждём
освобождения std::cout << "Critical section" << std::endl;
    lock.clear(std::memory_order_release);  // Освобождаем
}

int main() {
    std::thread t1(worker);
    std::thread t2(worker);
    t1.join(); t2.join();
    return 0;
}
*/

/*
? Память и барьеры (memory_order)
Управление порядком операций (например, memory_order_relaxed,
memory_order_seq_cst).

std::atomic<int> x(0), y(0);

void thread1() {
    x.store(1, std::memory_order_relaxed);
    y.store(1, std::memory_order_release);  // "Освобождает" изменения для thread2
}

void thread2() {
    while (y.load(std::memory_order_acquire) != 1) {}  // "Захватывает" изменения из thread1
    std::cout << "x: " << x.load(std::memory_order_relaxed) << std::endl;  // Гарантированно 1
}
*/

/*
? Специализации для указателей (std::atomic<T*>)
Атомарные операции с указателями.

int arr[10];
std::atomic<int*> ptr(arr);
int* old = ptr.fetch_add(2);  // Сдвигаем указатель на 2 элемента
std::cout << "Old ptr: " << old << ", New ptr: " << ptr.load() << std::endl;
*/

/*
? operator++, operator-- (инкремент/декремент)
Атомарные перегруженные операторы для удобного увеличения/уменьшения значения.

std::atomic<int> counter(0);
counter++;  // Атомарный инкремент (аналогично fetch_add(1))
std::cout << "Counter: " << counter << std::endl;  // Вывод: 1
counter--;  // Атомарный декремент (аналогично fetch_sub(1))
std::cout << "Counter: " << counter << std::endl;  // Вывод: 0
*/

/*
? operator+=, operator-= (атомарное сложение/вычитание)
Атомарные операторы для изменения значения с возвратом нового.

std::atomic<int> value(10);
value += 5;  // Атомарное сложение (value = 15)
std::cout << "Value: " << value << std::endl;
value -= 3;  // Атомарное вычитание (value = 12)
std::cout << "Value: " << value << std::endl;
*/

/*
? is_lock_free() — проверка, поддерживается ли lock-free реализация
Возвращает true, если операции с атомарной переменной выполняются без блокировок (зависит от платформы).

std::atomic<int> x(0);
if (x.is_lock_free()) {
    std::cout << "Атомарные операции выполняются без блокировок!" << std::endl;
} else {
    std::cout << "Атомарные операции требуют блокировок." << std::endl;
}
*/

/*
? wait(), notify_one(), notify_all() (C++20) — ожидание и уведомления
Позволяют реализовать условное ожидание изменений атомарной переменной.

#include <atomic>
#include <thread>

std::atomic<int> data(0);
void consumer() {
    data.wait(0);  // Ждём, пока data не изменится
    std::cout << "Data changed: " << data << std::endl;
}

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    data.store(42);
    data.notify_one();  // Разблокируем один ожидающий поток
}

int main() {
    std::thread t1(consumer);
    std::thread t2(producer);
    t1.join(); t2.join();
    return 0;
}
*/

/*
? std::atomic_ref<T> (C++20) — атомарная ссылка
Позволяет работать с неатомарными переменными как с атомарными.

#include <atomic>
#include <iostream>

int main() {
    int normal_var = 100;
    std::atomic_ref<int> atomic_var(normal_var);  // Создаём атомарную ссылку

    atomic_var.store(200);  // Атомарная запись
    std::cout << "Value: " << normal_var << std::endl;  // Вывод: 200

    int val = atomic_var.load();  // Атомарное чтение
    std::cout << "Atomic read: " << val << std::endl;  // Вывод: 200
    return 0;
}
*/

/*
? std::atomic_flag::test() (C++20) — проверка состояния флага
Проверяет, установлен ли флаг, без его изменения.

#include <atomic>
#include <iostream>

int main() {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    flag.test_and_set();  // Устанавливаем флаг

    if (flag.test()) {  // Проверяем состояние (C++20)
        std::cout << "Флаг установлен!" << std::endl;
    } else {
        std::cout << "Флаг сброшен." << std::endl;
    }
    return 0;
}
*/

/*
? std::atomic_signal_fence() — барьер для сигналов
Обеспечивает порядок операций между потоком и обработчиком сигналов (но не между
потоками).

#include <atomic>
#include <csignal>
#include <iostream>

std::atomic<int> sig_value(0);

void signal_handler(int) {
    std::atomic_signal_fence(std::memory_order_acquire);  // Барьер для чтения
    std::cout << "Signal received! Value: " << sig_value << std::endl;
}

int main() {
    std::signal(SIGINT, signal_handler);
    sig_value.store(42, std::memory_order_release);  // Запись перед барьером
    std::raise(SIGINT);  // Имитируем сигнал
    return 0;
}
*/

/*
? std::atomic_thread_fence() — барьер для потоков
Обеспечивает синхронизацию операций между потоками (без изменения переменных).

#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> x(0), y(0);

void thread1() {
    x.store(1, std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_release);  // Запись до барьера
    y.store(1, std::memory_order_relaxed);
}

void thread2() {
    while (y.load(std::memory_order_relaxed) != 1) {}
    std::atomic_thread_fence(std::memory_order_acquire);  // Чтение после барьера
    std::cout << "x: " << x.load(std::memory_order_relaxed) << std::endl;  // Гарантированно 1
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    t1.join(); t2.join();
    return 0;
}
*/

/*
? Специализация std::atomic<bool>
Оптимизированная версия для булевых значений.

#include <atomic>
#include <thread>

std::atomic<bool> ready(false);
void worker() {
    while (!ready.load()) {}  // Ожидаем флага
    std::cout << "Работа начата!\n";
}

int main() {
    std::thread t(worker);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    ready.store(true);  // Запускаем поток
    t.join();
    return 0;
}
*/

/*
? std::atomic<floating_point> (C++20)
Поддержка атомарных операций с числами с плавающей точкой.

#include <atomic>
#include <iostream>

int main() {
    std::atomic<double> atomic_float(3.14);
    Атомарное сложение (C++20)
    double old = atomic_float.fetch_add(1.5);
    std::cout << "Old: " << old << ", New: " << atomic_float << "\n";  //
Old: 3.14, New: 4.64
    Сравнение и обмен
    double expected = 4.64;
    atomic_float.compare_exchange_weak(expected, 5.0);
    std::cout << "Current: " << atomic_float << "\n";  // Current: 5.0
    return 0;
}
*/

/*
? std::atomic_fetch_add(), std::atomic_fetch_sub() (Free-функции)
Альтернативный синтаксис для атомарных операций.

#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> counter(10);
    Эквивалентно counter.fetch_add(5)
    int old = std::atomic_fetch_add(&counter, 5);
    std::cout << "Old: " << old << ", New: " << counter << "\n";  // Old: 10,
New: 15
    Эквивалентно counter.fetch_sub(3)
    old = std::atomic_fetch_sub(&counter, 3);
    std::cout << "Old: " << old << ", New: " << counter << "\n";  // Old: 15,
New: 12 return 0;
}
*/

/*
? std::atomic_flag::clear() — сброс флага
Сбрасывает атомарный флаг в false.

#include <atomic>
#include <iostream>

int main() {
    std::atomic_flag flag = ATOMIC_FLAG_INIT;
    flag.test_and_set();  // Устанавливаем флаг

    if (flag.test_and_set()) {
        std::cout << "Флаг был установлен\n";
        flag.clear();  // Сбрасываем флаг
    }

    std::cout << "Флаг теперь: " << flag.test() << "\n";  // Вывод: 0 (false)
    return 0;
}
*/

/*
? std::kill_dependency() (устранение зависимостей)
Используется для оптимизации при работе с memory_order_consume.

#include <atomic>

std::atomic<int*> ptr(nullptr);
int data = 0;

void thread1() {
    int* p = new int(42);
    data = 100;
    ptr.store(p, std::memory_order_release);
}

void thread2() {
    int* p = ptr.load(std::memory_order_consume);
    / data не синхронизирована, так как не зависит от ptr
    int local_data = std::kill_dependency(data);
    std::cout << "*p: " << *p << ", data: " << local_data << "\n";
}
*/

/*
? std::atomic<T*>::fetch_add(), fetch_sub() — арифметика указателей
Атомарное изменение указателей с шагом размера типа.

#include <atomic>
#include <iostream>

int arr[5] = {10, 20, 30, 40, 50};

int main() {
    std::atomic<int*> ptr(arr);
    
    int* old = ptr.fetch_add(2);  // Сдвигаем на 2 элемента
    std::cout << "Old: " << *old << ", New: " << *ptr << "\n";  // Old: 10, New: 30
    
    old = ptr.fetch_sub(1);
    std::cout << "Old: " << *old << ", New: " << *ptr << "\n";  // Old: 30, New: 20
    return 0;
}
*/

/*
? Free-функции (свободные функции) в контексте библиотеки <atomic> — это функции,
которые не являются методами класса, но предоставляют аналогичную атомарную
функциональность. Они работают с указателями на атомарные объекты и нужны для
совместимости с C-стилем, обобщённого программирования и специализированных
сценариев.
*/

#include<iostream>
#include<atomic>
#include<thread>
using namespace std;

atomic<int> counter(100);
atomic<bool> update(false);

void add()
{
    for(int i=0;i<1000;i++)
    counter.fetch_add(1,memory_order_relaxed);

}

void sub()
{
    for(int i=0;i<1100;i++)
    counter.fetch_sub(1,memory_order_relaxed);
}

void CAS()
{
    while(!update){}
    int tmp =0;
    counter.compare_exchange_strong(tmp,100);
}

int main()
{
    thread th1(add);
    thread th2(sub);
    thread th3(CAS);

    th1.join();
    th2.join();
    update.store(true, memory_order_acquire);
    while(!update){}
    th3.join();

    counter.load(memory_order_acquire);
    cout<<counter<<'\n';
}