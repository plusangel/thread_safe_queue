//
// Created by angelos on 12/03/2020.
//
#include <condition_variable>
#include <queue>
#include <type_traits>

template <typename T>
requires std::is_integral<T>::value
    &&std::is_default_constructible<T>::value struct SafeQueue {
  void push(T x) {
    std::lock_guard<std::mutex> guard{mutex};
    safeQueue.push(x);
    cv.notify_one();
  }

  void pop() {
    std::lock_guard<std::mutex> guard{mutex};
    if (!safeQueue.empty())
      safeQueue.pop();
  }

  int wait_and_pop() {
    std::unique_lock<std::mutex> lock{mutex};
    cv.wait(lock, [this] { return !safeQueue.empty(); });
    auto item = safeQueue.front();
    safeQueue.pop();
    return item;
  }

  size_t size() { safeQueue.size(); }

private:
  std::mutex mutex;
  std::condition_variable cv;
  std::queue<T> safeQueue;
};
