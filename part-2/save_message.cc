// Christian Alton bonilla
// CPSC 120-01
// 2022-10-26
// Alton77@csu.fullerton.edu
// @alton7759
//
// Lab 07-01
// Partners: @deborahjoneshappy, @jnd323
//
// this code saves messages
//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Prompt() {
  std::cout
      << "What's a secret message that you'd like to write into a file?\n";
  std::cout
      << "Type your message out and when you're done press return or enter.\n";
}

int main(int argc, char* argv[]) {
  std::vector<std::string> arguments(argv, argv + argc);
  if (arguments.size() != 2) {
    std::cout << "Please provide a path to a file. Exiting.\n";
    return 1;
  }
  std::string file_name{arguments.at(1)};
  std::ofstream output_file_stream{file_name};
  if (!output_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
  }
  Prompt();
  std::string their_favorite_movie;
  std::getline(std::cin, their_favorite_movie);
  output_file_stream << their_favorite_movie << "\n";
  std::cout << "Your secret message was saved into " << file_name << "\n";
  output_file_stream.close();

  return 0;
}
