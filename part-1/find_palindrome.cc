
// TODO: Insert your header

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// A function to check to see if the input is a palindrome. Returns true if
// word is a palindrome.
// See https://en.wikipedia.org/wiki/Palindrome for more information about what
// a palindrome is.
bool IsPalindrome(const std::string& word) {
  // TODO: write a function which will return true if and only if
  // 'word' is the same as the reverse of 'word'. For example,
  // if word is "cat", then the function will return False because
  // "cat" is not the same as "tac".
  // If on the other hand, 'word' is "racecar", then the function
  // will return True because "racecar" is the same as "racecar".
  // To reverse a string use the reverse iterator.
  // For example, if you have the variable 'word', then you
  // can create a reversed copy of 'word' by declaring a new
  // std::string variable useing rbegin() and rend().
  // std::string revered_word{word.rbegin(), word.rend()};
  // See https://en.cppreference.com/w/cpp/string/basic_string/rbegin
  // and https://en.cppreference.com/w/cpp/string/basic_string/rend
}

int main(int argc, char const* argv[]) {
  // TODO: Convert argv to a vector of arguments.
  // TODO: Check if the number of arguments is enough to continue.
  // If there are too few arguments, print a descriptive error message
  // and exit.
  // TODO: Declare a std::string variable named input_file_name.
  // Initialize this variable to the first command line argument.
  // TODO: Declare a std::ifstream variable named input_file_stream.
  // Initialize the variable using the variable input_file_name.
  // TODO: Check to see if input_file_stream is open. If input_file_stream
  // is not open, then print a descriptive error message and exit.
  // See https://en.cppreference.com/w/cpp/io/basic_ifstream/is_open

  // TODO: Using a loop, read from input_file_handle one line at a time.
  // TODO: Declare a std::string variable named line_buffer to store
  // the line read from the file. Each line in the input file will only
  // contain a single word.
  // TODO: Use the function std::getline() to read from input_file_stream.
  // See https://en.cppreference.com/w/cpp/string/basic_string/getline
  // TODO: Check to see if the word that was just read is a palindrome.
  // Use the function IsPalindrome() to check. If the word in line_buffer
  // is a palindrome, then print the word using std::cout.
  // See https://en.wikipedia.org/wiki/Palindrome to learn more about what
  // a palindrome is.
  // TODO: Close the input_file_stream.
  return 0;
}
