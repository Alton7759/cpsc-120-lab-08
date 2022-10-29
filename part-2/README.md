# Write to a File

Reading from a file opens up new pathways for us to write more sophisticated and interesting programs. Writing to a file enables us to have our programs communicate with people and with other programs.

Imagine that your instructor wishes to have a mechanism to remind students about deadlines. Your instructor could write a file with the name of the assignment and the date it's due, one entry per line. Then a program can look at who has turned in their work and who hasn't and generate a file with all the students who forgot to submit their assignment. Another program could use that list to send a message on Canvas. Writing files helps us track and connect pieces of information.

In this exercise, we prompt the computer user to enter a secret message from the keyboard. Our program shall take that message (as a `std::string`) and write it into a file.

Last time we used [`std::ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) to create an input file stream. This time we shall use [`std::ofstream`](https://en.cppreference.com/w/cpp/io/basic_ofstream) to create an output file stream. The `std::ofstream` object is defined in the same `fstream` header file as `std::ifstream`.

Where as reading from a file implies that the file must exist first in order for it to be read from, writing to a file does not have this requirement. If the file doesn't exist, then we will create a new file. However, if the file already exists, we have to be careful.

For our purposes, we'll just truncate (delete) the file. This is the path of least resistance yet it is a dangerous path because you could accidentally delete an important file. Be careful and remember to use git prudently to track your work.

To declare an `std::ofstream`, it is just like declaring an `std::ifstream`. Writing to an `std::ofstream` is like writing to `std::cout` (because `std::cout` is an `std::ofstream`).

```c++
std::string file_name{"my_output_file.txt"};
std::ofstream output_file_stream{file_name};
output_file_stream << "Hello World\n";
output_file_stream.close();
```

The code above will create an `std::ofstream` variable named `output_file_stream`. The variable `output_file_stream` is initialized to open the file `"my_output_file.txt"`. If the file `"my_output_file.txt"` doesn't exist, it will be created. If it already exists then it will be deleted and recreated (truncated). Using the insertion operator `<<`, the strings `"Hello World\n"` is written to the `output_file_stream`. Finally, we close the `output_file_stream` because we are done working with it.

Remembering to close our output file stream is very, very, very important. If you forget to close your output file stream you may find that nothing was written to the file. Your program will compile, run, and everything will seem to work yet the output file will have nothing in it. Remember - always close your file streams when you are done with them.

Remember, just like a `std::ifstream`, you should check to make sure the file has been opened before performing any operations.
```c++
std::string file_name{"my_output_file.txt"};
std::ofstream output_file_stream{file_name};
if (!output_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
}
output_file_stream << "Hello World\n";
output_file_stream.close();
```


The other challenge of this exercise is reading a whole line of text from the keyboard into a variable. If you think about it, so far we've never worked with a whole line. We always limited ourselves to just a word or a number using `std::cin` and the selection operator `>>`.

Reading in a line of text is a little different and we'll use the function (not the member function) [`std::getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline).

The function [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) is part of the `std::string` header file and it can be used to read a line of text from any input stream.

Let's imagine we want to prompt someone to enter their favorite movie title. Then we would first print a message to the terminal using `std::cout`, declare a `std::string` variable to store the movie title, and then use `std::getline()` to copy the data from the terminal's keyboard to the `std::string` variable.

```c++
std::cout << "What's your favorite movie?\n";
std::string their_favorite_movie;
std::getline(std::cin, their_favorite_movie);
```

In the last line, `std::getline()` shall read the values from `std::cin` up to but not including the `\n` letter and save the input into the `std::string` variable `their_favorite_movie`.

Because we're only writing one line, we do not need to use a loop. Instead, our program checks the status of the `std::ofstream` and then exits.

Just like an `std::ifstream`, once a file has been opened, you can check the status of the file.

```c++
  if (output_file_stream.bad()) {
    cout << "I/O error while reading\n";
    return 1;
  } else if (output_file_stream.fail()) {
    cout << "Encountered something crazy! Long line?\n";
    return 1;
  }
  output_file_stream.close();
```

Remember, you can only check the status of a file while it is open so make sure you check before you close the `std::ofstream`.

## Requirements

Using `std::ofstream`, write a message to a file that is specified on the command line. Read the message the computer user wishes to save by using the `std::getline()` function. *Do not use the `getline()` member function from the `std::ifstream` class.*

If there are any errors, print an error message and exit. Errors include but are not limited to, not providing enough command line arguments and naming a file that cannot be opened.


The program takes one command line arguments other than the program's name. The first argument is the path to the output file.

Close any file streams that you open and report any errors encountered.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* lint: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* header: check to make sure your files have the appropriate header
* test: run tests to help you verify your program is meeting the assignment's requirements. This does not grade your assignment.
* unittest: run unit tests to verify parts of your program performs according to the instructor supplied unit tests.
* doc: generate the project's documentation from the source files and store it in the directory named `doc`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Input and Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 save_message.cc \
| sed 's/\(save_message\)\.o[ :]*/\1.o save_message.d : /g' > save_message.d; \
[ -s save_message.d ] || rm -f save_message.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c save_message.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o save_message save_message.o 
$ ./save_message 
Please provide a path to a file.
$ ./save_message /sadfsdf
Could not open the file /sadfsdf. Exiting.
$ ./save_message my_secret.txt
What's a secret message that you'd like to write into a file?
Type your message out and when you're done press return or enter.
Hot dogs and burritos are sandwiches.
Your secret message was saved into my_secret.txt.
$ cat my_secret.txt 
Hot dogs and burritos are sandwiches.
$ make test
2022-10-23 23:03:14,099 - INFO - Start Testing Tuffy Titan tuffy@fullerton.edu @tuffy
2022-10-23 23:03:14,099 - INFO - All files: ./save_message.cc
2022-10-23 23:03:14,141 - INFO - ✅ Formatting passed on ./save_message.cc
2022-10-23 23:03:17,648 - INFO - ✅ Linting passed in ./save_message.cc
2022-10-23 23:03:18,340 - INFO - ✅ Build passed
2022-10-23 23:03:18,340 - INFO - Test 1 - ['Empty', 'Please provide a path to a file']
2022-10-23 23:03:18,445 - INFO - Test 2 - ['/foobar', 'Could not open the file /foobar']
2022-10-23 23:03:18,551 - INFO - Test 3 - ['out_1.txt', 'Practical politics consists in ignoring facts.']
2022-10-23 23:03:18,709 - INFO - Test 4 - ['out_2.txt', 'Every silver lining has a cloud around it.']
2022-10-23 23:03:18,866 - INFO - Test 5 - ['out_3.txt', "You're reasoning is excellent -- it's"]
2022-10-23 23:03:19,023 - INFO - Test 6 - ['out_4.txt', 'All of the true things I am about to tell you are shameless lies.']
2022-10-23 23:03:19,181 - INFO - ✅ All test runs passed
2022-10-23 23:03:19,181 - INFO - End Testing Tuffy Titan tuffy@fullerton.edu @tuffy
```

## What to Do

1. With your partner, edit the `save_message.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./save_message` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Next Steps

After you have pushed your code, move on to part 3.

