/*
std::async – запускает функцию асинхронно (или отложенно) и возвращает
Политики запуска:
std::launch::async — асинхронный запуск.
std::launch::deferred — отложенный запуск (при первом get()).
std::future с результатом.

int compute() { return 42; }

int main() {
    std::future<int> result = std::async(std::launch::async, compute);
    std::cout << result.get() << std::endl; // Блокируется, пока результат не
готов return 0;
}

std::future<T> – представляет результат асинхронной операции.
get() — блокирует поток до готовности результата.
wait() — ожидает завершения без получения результата.
wait_for() / wait_until() — ожидание с таймаутом.
valid() — проверяет, есть ли shared state.
share() — конвертирует в std::shared_future.
*/

/*
std::promise<T> и std::future<T> – позволяют явно передавать значение между потоками.

std::promise<int> prom;
std::future<int> fut = prom.get_future();

std::thread t([](std::promise<int> p) { p.set_value(100); }, std::move(prom));

std::cout << fut.get() << std::endl; // 100
t.join();
*/

/*
std::shared_future<T> – позволяет нескольким потокам ждать один и тот же результат.

std::shared_future<int> shared_fut = std::async(std::launch::async, []() { return 50; });
auto copy = shared_fut;
std::cout << shared_fut.get() << " " << copy.get() << std::endl; // 50 50
*/

/*
std::packaged_task<T> – оборачивает функцию, чтобы получить future с её результатом.

std::packaged_task<int()> task([]() { return 7 * 6; });
std::future<int> fut = task.get_future();
std::thread(std::move(task)).detach();
std::cout << fut.get() << std::endl; // 42
*/

/*
std::promise
set_value() — устанавливает результат в promise.
set_exception() — передаёт исключение в связанный future.
get_future() — возвращает связанный std::future.
*/

//zzzz

/*
? std::future и std::async
Позволяют запускать функции асинхронно и получать их результат.

#include <iostream>
#include <future>
#include <thread>

int compute() {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 42;
}

int main() {
    Запуск compute() асинхронно
    std::future<int> fut = std::async(std::launch::async, compute);

    std::cout << "Waiting for the result..." << std::endl;
    int result = fut.get();  // Блокирует, пока результат не будет готов
    std::cout << "Result: " << result << std::endl;

    return 0;
}
    Вывод:
Waiting for the result...
Result: 42
*/

/*
? std::promise и std::future
Позволяют передавать значение из одного потока в другой.

#include <iostream>
#include <future>
#include <thread>

void compute(std::promise<int> prom) {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(100);  // Устанавливаем значение
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();

    std::thread t(compute, std::move(prom));  // Передаём promise в поток

    std::cout << "Waiting for the result..." << std::endl;
    int result = fut.get();  // Ждём, пока поток установит значение
    std::cout << "Result: " << result << std::endl;

    t.join();
    return 0;
}
    Вывод:
Waiting for the result...
Result: 100
*/

/*
? std::packaged_task
Обёртка для функции, которая сохраняет результат в future.

#include <future>
#include <iostream>
#include <thread>

int multiply(int a, int b) {
    return a * b;
}

int main() {
    Создаём packaged_task для функции multiply
    std::packaged_task<int(int, int)> task(multiply);
    std::future<int> fut = task.get_future();

    Запускаем задачу в отдельном потоке
    std::thread t(std::move(task), 6, 7);

    std::cout << "Waiting for the result..." << std::endl;
    int result = fut.get();  // Получаем результат
    std::cout << "6 * 7 = " << result << std::endl;

    t.join();
    return 0;
}
    Вывод:
Waiting for the result...
6 * 7 = 42
*/

/*
? Обработка исключений через std::future
Если асинхронная задача выбрасывает исключение, оно передаётся через future.

#include <iostream>
#include <future>
#include <stdexcept>

void might_throw(bool do_throw) {
    if (do_throw) {
        throw std::runtime_error("Error in async task!");
    }
    std::cout << "Task completed successfully." << std::endl;
}

int main() {
    auto fut = std::async(std::launch::async, might_throw, true);

    try {
        fut.get();  // Исключение пробрасывается сюда
    } catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}
    Вывод:
Caught exception: Error in async task!
*/

/*
? std::future::wait() и std::future::wait_for() / std::future::wait_until()
Эти методы позволяют проверять статус future без немедленного получения результата.
TODO Пример с wait():
#include <iostream>
#include <future>
#include <thread>

void slow_operation() {
    std::this_thread::sleep_for(std::chrono::seconds(3));
    std::cout << "Operation completed!" << std::endl;
}

int main() {
    auto fut = std::async(std::launch::async, slow_operation);

    std::cout << "Waiting for the operation to finish..." << std::endl;
    fut.wait(); // Блокирует, пока операция не завершится
    std::cout << "Done!" << std::endl;

    return 0;
}
    Вывод:
Waiting for the operation to finish...
Operation completed!
Done!

TODO Пример с wait_for() (неблокирующая проверка):
#include <iostream>
#include <future>
#include <thread>

int main() {
    auto fut = std::async(std::launch::async, [] {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 123;
    });

    while (true) {
        auto status = fut.wait_for(std::chrono::milliseconds(500));
        if (status == std::future_status::ready) {
            std::cout << "Result: " << fut.get() << std::endl;
            break;
        } else {
            std::cout << "Still waiting..." << std::endl;
        }
    }

    return 0;
}
    Вывод:
Still waiting...
Still waiting...
Still waiting...
Still waiting...
Result: 123
*/

/*
? std::shared_future (многократное использование future)
Если std::future можно использовать только один раз (get() вызывает
перемещение), то std::shared_future позволяет получать результат несколько раз и
передавать между потоками.
#include <future>
#include <iostream>
#include <thread>

void print_result(std::shared_future<int> fut) {
    std::cout << "Thread " << std::this_thread::get_id()
              << ": " << fut.get() << std::endl;
}

int main() {
    std::promise<int> prom;
    auto shared_fut = prom.get_future().share(); // Преобразуем в shared_future

    Запускаем несколько потоков, использующих shared_future
    std::thread t1(print_result, shared_fut);
    std::thread t2(print_result, shared_fut);

    Устанавливаем значение
    prom.set_value(42);

    t1.join();
    t2.join();
    return 0;
}
    Вывод (может варьироваться):
Thread 140123456789760: 42
Thread 140123448397056: 42
*/

/*
? std::future::valid() – проверка валидности future
Проверяет, связан ли future с каким-либо shared state (например, не был ли уже вызван get()).

#include <iostream>
#include <future>

int main() {
    std::future<int> fut = std::async(std::launch::async, [] { return 10; });

    std::cout << "Future is valid: " << fut.valid() << std::endl; // true (1)
    int x = fut.get();
    std::cout << "Future is valid after get(): " << fut.valid() << std::endl; // false (0)

    return 0;
}
    Вывод:
Future is valid: 1
Future is valid after get(): 0
*/

/*
? std::async с политиками запуска
std::async можно запускать с разными политиками:
std::launch::async – гарантирует запуск в новом потоке.
std::launch::deferred – откладывает выполнение до вызова get()/wait() (ленивое вычисление).

#include <iostream>
#include <future>

int main() {
    Отложенное выполнение (deferred)
    auto fut = std::async(std::launch::deferred, [] {
        std::cout << "Deferred task runs!" << std::endl;
        return 5;
    });

    std::cout << "Task not started yet." << std::endl;
    int result = fut.get(); // Запускается только здесь
    std::cout << "Result: " << result << std::endl;

    return 0;
}
    Вывод:
Task not started yet.
Deferred task runs!
Result: 5
*/

/*
? std::future::share() - преобразование future в shared_future
Позволяет преобразовать обычный future в разделяемый shared_future:

#include <iostream>
#include <future>
#include <vector>
#include <thread>

void worker(std::shared_future<int> sf) {
    std::cout << "Worker got: " << sf.get() << std::endl;
}

int main() {
    std::promise<int> p;
    auto sf = p.get_future().share();  // Преобразуем в shared_future
    
    std::vector<std::thread> threads;
    for (int i = 0; i < 3; ++i) {
        threads.emplace_back(worker, sf);  // Можем копировать shared_future
    }
    
    p.set_value(42);  // Все worker'ы получат 42
    
    for (auto& t : threads) t.join();
    return 0;
}
*/
#include<iostream>
#include<exception>
#include<future>
#include<thread>
#include<vector>
using namespace std;

int sqare(int x)
{
    if(x<0)
    throw invalid_argument("ERROR: x < 0");
    return x*x;
}

void sendValue(promise<int> &&prom,int value)
{
    prom.set_value(value);
}

int main()
{
    future<int> result = async(launch::async,sqare,5);
    cout<<result.get()<<'\n';
    vector<thread> th;

    promise<int> prom;
    future<int> fut=prom.get_future();
    th.emplace_back(sendValue,move(prom),30);
    th.emplace_back([&fut](){cout<<fut.get()<<'\n';});

    packaged_task<int(int)> task([](int x){return sqare(x);});
    future<int> futt = task.get_future();
    th.emplace_back(move(task),10);
    th.emplace_back([&futt](){cout<<futt.get()<<'\n';});

    shared_future<int> share = async(launch::async,[](){return 30;});
    th.emplace_back([&share](){cout<<share.get()<<'\n';});
    th.emplace_back([&share]() { cout << share.get() << '\n'; });

    promise<int> prome;
    future<int> fute = prome.get_future();
    th.emplace_back(sendValue, move(prome), -1);
    th.emplace_back([&fute]() { cout << fute.get() << '\n'; });

    for (auto &i : th)
    i.join();
}