/*
? std::thread — создание потока
Позволяет создать поток, который выполняет указанную функцию.

#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(hello);  // Создаем поток, выполняющий функцию hello
    t.join();              // Ждем завершения потока
    return 0;
}
*/

/*
? join() — ожидание завершения потока
Блокирует выполнение текущего потока до тех пор, пока другой поток (для которого
вызван join()) не завершится.

#include <iostream>
#include <thread>

void task() {
    std::cout << "Working in thread..." << std::endl;
}

int main() {
    std::thread t(task);
    std::cout << "Waiting for thread to finish..." << std::endl;
    t.join();  // Основной поток ждет завершения `t`
    std::cout << "Thread finished!" << std::endl;
    return 0;
}

Вывод:
Waiting for thread to finish...
Working in thread...
Thread finished!
*/

/*
? detach() — отделение потока
Позволяет потоку выполняться независимо от основного потока (после detach() поток нельзя join()).

#include <iostream>
#include <thread>
#include <chrono>

void backgroundTask() {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Background task done!" << std::endl;
}

int main() {
    std::thread t(backgroundTask);
    t.detach();  // Отделяем поток (теперь он работает независимо)
    std::cout << "Main thread continues..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Даем время завершиться
    return 0;
}

Вывод:
Main thread continues...
Background task done!
*/

/*
? std::this_thread::sleep_for() — приостановка потока
Приостанавливает выполнение текущего потока на указанное время.

#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Start..." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));  // Ждем 2 секунды
    std::cout << "End!" << std::endl;
    return 0;
}

Вывод:
Start...
(пауза 2 секунды)
End!
*/

/*
? std::thread::hardware_concurrency() — количество поддерживаемых потоков
Возвращает количество потоков, которые могут выполняться параллельно.

#include <iostream>
#include <thread>

int main() {
    unsigned int cores = std::thread::hardware_concurrency();
    std::cout << "This machine supports " << cores << " concurrent threads." << std::endl;
    return 0;
}

Вывод (зависит от процессора):
This machine supports 8 concurrent threads.
*/

/*
? std::thread::get_id() — получение ID потока
Возвращает уникальный идентификатор потока.

#include <iostream>
#include <thread>

void printId() {
    std::cout << "Thread ID: " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::thread t(printId);
    std::cout << "Main thread ID: " << std::this_thread::get_id() << std::endl;
    t.join();
    return 0;
}

Вывод (пример):
Main thread ID: 140737345955648
Thread ID: 140737337562880
*/

/*
? std::promise и std::future — передача результата между потоками
Позволяет одному потоку вернуть результат другому.

#include <iostream>
#include <thread>
#include <future>

void compute(std::promise<int>&& prom) {
    prom.set_value(42);  // Передаем результат
}

int main() {
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    
    std::thread t(compute, std::move(prom));
    
    std::cout << "Result: " << fut.get() << std::endl;  // Блокируется, пока не получит значение
    t.join();
    return 0;
}
*/

/*
? std::call_once — однократный вызов функции
Гарантирует, что функция выполнится только один раз, даже если ее вызывают
несколько потоков.

#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;

void init() {
    std::cout << "Initialized only once!" << std::endl;
}

void task() {
    std::call_once(flag, init);  // Только первый вызов выполнит init()
}

int main() {
    std::thread t1(task);
    std::thread t2(task);
    t1.join();
    t2.join();
    return 0;
}

Вывод:
Initialized only once!  // (Один раз, даже если вызвано из двух потоков)
*/

/*
? Thread Pool (Пул потоков)
Вместо создания и уничтожения потоков на каждую задачу,
пул потоков поддерживает несколько рабочих потоков, которые выполняют задачи из
очереди.

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            workers.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex);
                        cv.wait(lock, [this] { return stop || !tasks.empty();
}); if (stop && tasks.empty()) return; task = std::move(tasks.front());
                        tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template <class F>
    void enqueue(F&& f) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            tasks.emplace(std::forward<F>(f));
        }
        cv.notify_one();
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex);
            stop = true;
        }
        cv.notify_all();
        for (auto& worker : workers) {
            worker.join();
        }
    }

private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable cv;
    bool stop = false;
};

int main() {
    ThreadPool pool(4);

    for (int i = 0; i < 8; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " executed by thread "
                      << std::this_thread::get_id() << std::endl;
        });
    }

    return 0;
}

Вывод (пример):
Task 0 executed by thread 140245231789824
Task 1 executed by thread 140245223397120
Task 2 executed by thread 140245214004416
Task 3 executed by thread 140245240182528
Task 4 executed by thread 140245231789824
...
*/

#include<iostream>
#include<vector>
#include<thread>
#include<chrono>

using namespace std;
using namespace std::chrono;
int main()
{
  vector<int> base;
  vector<int> t1;
  vector<int> t2;
  vector<int> t3;
  vector<int> t4;
  for(int i=100000;i>0;i--)
  {
    base.push_back(i);
  }

  for(int i=0;i<1000;i++)
  {
    cout<<base[i]<<'\t';
  }
  cout<<'\n'<<"_________";
  cout << '\n'<< "__________";
  cout << '\n';

  for(int i=0;i<=base.size()/4;i++)
  t1.push_back(base[i]);
  for(int i=base.size()/4+1;i<=base.size()/4*2;i++)
  t2.push_back(base[i]);
  for(int i=base.size()/4*2+1;i<=base.size()/4*3;i++)
  t3.push_back(base[i]);
  for(int i=base.size()/4*3+1;i<=base.size();i++)
  t4.push_back(base[i]);

  // auto start = high_resolution_clock::now();
  // for(int i=0;i<base.size();i++)
  // {
  //   for(int j=i+1;j<base.size();j++)
  //   {
  //     if(base[i]>base[j])
  //     swap(base[i],base[j]);
  //   }
  // }
  // auto end = high_resolution_clock::now();
  // auto duration = duration_cast<seconds>(end - start); !!ЛИНЕЙНОЕ ВРЕМЯ 57!!


  auto start = high_resolution_clock::now();
  thread one([&t1] {
    for(int i=0;i<t1.size();i++)
    {
      for(int j=i+1;j<t1.size();j++)
      {
        if(t1[i]>t1[j])
        swap(t1[i],t1[j]);
      }
    }
  });

  thread two([&t2] {
    for (int i = 0; i < t2.size(); i++) {
      for (int j = i + 1; j < t2.size(); j++) {
        if (t2[i] > t2[j])
          swap(t2[i], t2[j]);
      }
    }
  });

  thread three([&t3] {
    for (int i = 0; i < t3.size(); i++) {
      for (int j = i + 1; j < t3.size(); j++) {
        if (t3[i] > t3[j])
          swap(t3[i], t3[j]);
      }
    }
  });

  thread four([&t4] {
    for (int i = 0; i < t4.size(); i++) {
      for (int j = i + 1; j < t4.size(); j++) {
        if (t4[i] > t4[j])
          swap(t4[i], t4[j]);
      }
    }
  });

  one.join();
  two.join();
  three.join();
  four.join();

  // for (int i = 0; i < 1000; i++) {
  //   cout << t1[i] << '\t';
  // }
  // cout << '\n';

  auto end = high_resolution_clock::now();
  auto duration = duration_cast<seconds>(end - start);
  cout<<"Затраченное время:\t"<<duration.count()<<'\n';
}