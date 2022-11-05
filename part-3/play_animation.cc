// Christian Alton bonilla
// CPSC 120-01
// 2022-10-26
// Alton77@csu.fullerton.edu
// @alton7759
//
// Lab 07-01
// Partners: @deborahjoneshappy, @jnd323
//
// this code find palindromes
//

#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

using namespace std::chrono_literals;

int main(int argc, char const* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() < 2) {
    std::cout << "Please provide a path to a file. Exiting.";
    return 1;
  }
  std::string file_name{arguments.at(1)};
  std::ifstream input_file_stream(file_name);
  if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
  }
  char letter{0};
  while (input_file_stream.get(letter)) {
    std::cout << letter;
    std::this_thread::sleep_for(2000us);
  }

  input_file_stream.close();
  return 0;
}
