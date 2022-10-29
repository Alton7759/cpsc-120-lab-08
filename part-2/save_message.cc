
// TODO: Insert your header

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void Prompt() {
  // TODO: Write a function that prints to std::cout the following prompt and
  // instructions: "What's a secret message that you'd like to write into a
  // file?\n" "Type your message out and when you're done press return or
  // enter.\n";
}

int main(int argc, char* argv[]) {
  // TODO: Convert argv to a vector of arguments.
  // TODO: Check if the number of arguments is enough to continue.
  // If there are too few arguments, print a descriptive error message
  // and exit.
  // TODO: Declare a std::string variable named output_file_name.
  // Initialize this variable to the first command line argument.
  // TODO: Declare a std::ofstream variable named output_file_stream.
  // Initialize the variable using the variable output_file_name.
  // TODO: Check to see if output_file_stream is open. If output_file_stream
  // is not open, then print a descriptive error message and exit.
  // See https://en.cppreference.com/w/cpp/io/basic_ofstream/is_open
  // TODO: Declare a std::string variable named secret_message.
  // TODO: Call the function Prompt() to print out the prompt and instructions.
  // TODO: Use std::getline() to read from std::cin and store the line into
  // the variable secret_message.
  // TODO: Use the insertion operator (<<) to send the value of secret_message
  // to
  //  output_file_stream. Remember to end the line that is written to
  //  output_file_stream
  // with a new line ("\n").
  // TODO: Print a message that the secret message was saved into
  // output_file_name. Make sure your output matches the sample output in the
  // README.
  // TODO: Close output_file_stream.
  return 0;
}
