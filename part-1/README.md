# Finding a Palindrome
In this exercise, you will write a program that will read text from a file and identify all the [palindromes](https://en.wikipedia.org/wiki/Palindrome).

A [palindrome](https://en.wikipedia.org/wiki/Palindrome) is a word that is read the same backwards and forwards. An example is 'racecar' which when spelled backwards is 'racecar. For more examples, watch "Weird Al" Yankovic's video [Bob](https://www.youtube.com/watch?v=JUQDzj6R3p4) which is a collection of palindromes set to music.

## Reading From a File

Working with data in the computer's memory is a good starting point. We've done that with a variety of different types (int, float, string). The next challenge for us to over come is how to read and write from [files](https://en.wikipedia.org/wiki/Computer_file).

Reading from files is a great leap forward. Writing programs that can read from a file means that you are no longer limited to what a human can enter at the computer's console. Reading from a file means that you can make use of much more interesting (and larger!) data sources. The smallest and most portable computer can store Gigabytes of data. That is a lot of space to store files (and database)!

How big of a file can your fit on your computer? Is there a limit to how large or how many files you can have on your computer? How big is the smallest file?

A file is just an abstraction of some information that is stored in your computer's [file system](https://en.wikipedia.org/wiki/File_system). It's an address of sorts to help you, the programmer, locate a resource that has been stored in your computer's file system.

You can think of a path to a file kind of like a [URL](https://en.wikipedia.org/wiki/URL) to a website. If you have the right path, your computer can open up the file and read it. (And if you think about it a little bit you may ask yourself if you can read from a file, then how hard can it be to read from a website?).

The first thing we need is an abstraction of what a file is. For the programmer, a file is a stream. A stream not in the sense of a flowing body of water but a sequence that streams by. More like a train which has a beginning, middle, and end. Given a stream in C++, we want to have operations to read from it and move forward and backwards.

For starters, let's focus on opening up a file and reading it line by line. (Remember a line is terminated by the "\n" letter.)

C++ has a special type called [`ifstream`](https://en.cppreference.com/w/cpp/io/basic_ifstream) which is defined in the `fstream` header file. If we have the name of a file such as `"words_that_start_with_m.txt"`, then we can open and minupulate the file with the following code:

```c++
std::string file_name{"words_that_start_with_m.txt"};
std::ifstream input_file_stream(file_name);
```

The variable `input_file_stream` is of type `ifstream` or input file stream. It is a C++ object which is allocated and initialized with the file path `"words_that_start_with_m.txt"`. From here, we can perform operations such as checking to see if the file was successfully opened or read a line of text from the file.

To read from a input file stream line by line, we need to think of it as copying the line from the file on disk to a  [buffer](https://en.wikipedia.org/wiki/Data_buffer) in the computer's RAM. (A [buffer](https://en.wikipedia.org/wiki/Data_buffer) is temporary storage.) In other words, we will use the function `std::getline()` to read a single line (a `std::string`) from the input file stream and then assign that line to a temporary `std::string` variable (the buffer). Once we have it as a `std::string` variable we can print the line to the terminal.

We can extract a line of text from a file stream using the [`std::getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) function. The function [`getline()`](https://en.cppreference.com/w/cpp/string/basic_string/getline) is part of the `std::string` header file and it can be used to read a line of text from any input stream.

Our strategy is to first declare a `std::string` variable and then use `std::getline()` to copy the line from the file stream into the temporary variable. Let's assume the variable `input_file_stream` successfully opened `"words_that_start_with_m.txt"` and the first line of the file contains the phrase "muffins and mittens".

```c++
std::string file_name{"words_that_start_with_m.txt"};
std::ifstream input_file_stream(file_name);
std::string line_buffer;
std::getline(input_file_stream, line_buffer);
std::cout << line_buffer << "\n";
input_file_stream.close();
```

On the last line, `input_file_stream` is closed because we are no longer using it. If you open something, like a file, you must close it. Not closing a file leaves it locked and perhaps in an undefined state.

In the example above, we assumed the file existed and was opened without a problem. This is not a good practice. Whenever opening a file, always check to make sure the file was opened. This short and simple check ensures that the file is open and ready to be read from.

```c++
std::string file_name{"words_that_start_with_m.txt"};
std::ifstream input_file_stream{file_name};
if (!input_file_stream.is_open()) {
    std::cout << "Could not open the file " << file_name << ". Exiting.\n";
    return 1;
}
std::string line_buffer;
std::getline(input_file_stream, line_buffer);
std::cout << line_buffer << "\n";
input_file_stream.close();
```

We only read one line of text in the given example. What if we want to read the contents of an entire file? Consider that a file is composed of many lines of text.

To read the contents of an entire file, all one needs to do is to use `std::getline()` in a loop.

For example, to read all the lines in a file using a while loop:
```c++
std::string file_name{"words_that_start_with_m.txt"};
std::ifstream input_file_stream{filename};
while (input_file_stream.good()) {
	std::string line_buffer;
	std::getline(input_file_stream, line_buffer);
	std::cout << line_buffer << "\n";
}
input_file_stream.close();
```

Finally, if we want to know if we have been successful in reading to the end of the file, we can ask the `std::ifstream` what's happened. You can only check the status of an `std::ifstream` while it is open. You cannot check its status after you have closed it. The following if-eslse-if block can be used right before the `std::ifstream` is closed to print it's status to the terminal.

```c++
if (input_file_stream.eof()) {
  std::cout << "End of file reached successfully!\n";
} else if (input_file_stream.bad()) {
  std::cout << "I/O error while reading.\n";
  return 1;
} else if (input_file_stream.fail()) {
  std::cout << "Failure: Long line.\n";
  return 1;
}
input_file_stream.close();
```

We typically do not print a message when we successfully reach the end of a file like in the example above. In your program, you may want to print out a message like this to help yourself understand how your program works. When you've finished with your lab, make sure to comment out any extra messages that don't meet the exercise's requirements.

## Palindrome Check

Now that we can successfully read through an entire file and print each line to the terminal, our next challenge is to only print lines that are palindromes. To do this, let us define a funciton named `IsPalindrome()`.

The function `IsPalindrome()` shall take one parameters which will be a `const` reference to a `std::string`. This `std::string` is our input `word`. We'll check to see if this `word` is a palindrome. If it is a palindrome, then the function shall return `true`. If `word` is not a palindrome, then the function shall return `false`.

The function's prototype is:
```c++
bool IsPalindrome(const std::string& word);
```

The algorithm for checking if a word is a palindrome are the following steps:
1. reverse the word and store it in a variable
1. compare the reversed word to the original word to see if they are equal to one another
    return _true_ if they are the same, _false_ otherwise.

Let's imagine we have the following situation:
```c++
std::string first_word{"racecar"};
std::string second_word{"racecar"};
```

If we wanted to see if `first_word` has the same value as `second_word`, we could use the _equal to_ operator `==` to compare the two variables. For example:

```c++
if (first_word == second_word) {
    std::cout << "They are the same.\n";
} else {
    std::cout << "They are different.\n";
}
```

How do we reverse a string? There are many ways to do this. The best approach is to use the tools available in the C++ standard library.

There is a concept in programming called an [iterator](https://en.wikipedia.org/wiki/Iterator). It's a tool that allows a programmer to move forwards or backwards through a container or sequence like a string. Usually, we want to start at the beginning and move (or iterate) to the end. For `std::string`, there are the member functions [begin()](https://en.cppreference.com/w/cpp/string/basic_string/begin) and [end()](https://en.cppreference.com/w/cpp/string/basic_string/end).

To reverse a string, do we move from the beginning to the end? Consider the string "cat". The reverse of "cat" is "tac". Did you move from the beginning to the end to reverse "cat"? More than likely, you reversed "cat" by moving from the end to the beginning. In C++, there are member functions which return reverse iterators [rbegin()](https://en.cppreference.com/w/cpp/string/basic_string/rbegin) and [rend()](https://en.cppreference.com/w/cpp/string/basic_string/rend).

An example of how to reverse a string in C++ is the following:
```c++
std::string favorite_animal{"cat"};
std::string reversed_favorite_animal{favorite_animal.rbegin(), favorite_animal.rend()};
// This will print "tac"
std::cout << reversed_favorite_animal << "\n";
```

The reverse iterators are used to initialize `reversed_favorite_animal` with the letters from `favorite_animal` in reverse order.

## Requirements

Using `std::ifstream`, read the contents of a file that is specified on the command line and print all palindromes to the terminal. Print each palindrome on a line by itself. Read the contents of the file line by line using the `std::getline()` function. *Do not use the `getline()` member function from the `std::ifstream` class.*

For this exercise, a palindrome is defined as any sequence of letters that is identical to itself when reversed *and* the sequence of letters is longer than 3 letters. Ignore all words that are 3 letters long or less. That means words and sequences such as _a_, _rr_, and _pip_ are not considered palindromes.

If there are any errors, print an error message and exit. Errors include but are not limited to, not providing enough command line arguments and naming a non-existant file that cannot be opened.

Use the files 01_words.txt, 02_words.txt, 03_words.txt, 04_words.txt to help you validate that your program works as expected. Sample output is provided below.

The program takes one command line arguments other than the program's name. The first argument is the path to the input file

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
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 find_palindrome.cc \
| sed 's/\(find_palindrome\)\.o[ :]*/\1.o find_palindrome.d : /g' > find_palindrome.d; \
[ -s find_palindrome.d ] || rm -f find_palindrome.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c find_palindrome.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o find_palindrome find_palindrome.o 
$ ./find_palindrome 
Please provide a path to a file. Exiting.
$ ./find_palindrome non-existant-file
Could not open the file non-existant-file. Exiting.
$ ./find_palindrome words_1.txt 
tibbit
kook
$ ./find_palindrome words_2.txt 
stots
ululu
susus
siris
$ ./find_palindrome words_3.txt 
kinnikinnik
mallam
semes
peeweep
abba
keek
$ ./find_palindrome words_4.txt 
goog
mallam
acca
rever
hagigah
anana
arara
tirrit
$ make test
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 find_palindrome.cc \
| sed 's/\(find_palindrome\)\.o[ :]*/\1.o find_palindrome.d : /g' > find_palindrome.d; \
[ -s find_palindrome.d ] || rm -f find_palindrome.d
2022-10-23 22:41:39,754 - INFO - Start Testing Tuffy Titan tuffy@fullerton.edu @tuffy
2022-10-23 22:41:39,754 - INFO - All files: ./find_palindrome.cc
2022-10-23 22:41:39,773 - INFO - ✅ Formatting passed on ./find_palindrome.cc
2022-10-23 22:41:45,619 - INFO - ✅ Linting passed in ./find_palindrome.cc
2022-10-23 22:41:46,385 - INFO - ✅ Build passed
2022-10-23 22:41:46,385 - INFO - Test 1 - ['Empty', 'Please provide a path to a file']
2022-10-23 22:41:46,490 - INFO - Test 2 - ['foobar', 'Could not open the file foobar']
2022-10-23 22:41:46,594 - INFO - Test 3 - ['words_1.txt', 'tibbit kook']
2022-10-23 22:41:46,700 - INFO - Test 4 - ['words_2.txt', 'stots ululu susus siris']
2022-10-23 22:41:46,806 - INFO - Test 5 - ['words_3.txt', 'kinnikinnik mallam semes peeweep abba keek']
2022-10-23 22:41:46,912 - INFO - Test 6 - ['words_4.txt', 'goog mallam acca rever hagigah anana arara tirrit']
2022-10-23 22:41:47,026 - INFO - ✅ All test runs passed
2022-10-23 22:41:47,027 - INFO - End Testing Tuffy Titan tuffy@fullerton.edu @tuffy
```

## What to Do

1. With your partner, edit the `find_palindrome.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./find_palindrome` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Next Steps

After you have pushed your code, move on to part 2.


