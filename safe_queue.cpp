//
// Created by angelos on 11/03/2020.
//
#include <future>
#include <iostream>
#include "safeQueue.cpp"

void goat_rodeo() {
  const size_t iterations{1'000'000};
  SafeQueue<int> tin_cans_available;

  auto eat_cans = std::async(std::launch::async, [&] {
    for (size_t i{}; i < iterations; i++) {
      tin_cans_available.wait_and_pop();
    }
  });

  auto deposit_cans = std::async(std::launch::async, [&] {
    for (size_t i{}; i < iterations; i++) {
      tin_cans_available.push(i);
    }
  });

  eat_cans.get();
  deposit_cans.get();

  std::cout << "Size " << tin_cans_available.size() << std::endl;
}

int main() {
  goat_rodeo();
  goat_rodeo();
  goat_rodeo();

  return 0;
}