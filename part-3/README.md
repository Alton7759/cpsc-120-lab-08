# ANSI & ASCII Animation

```
                             @@@
                             @@@
                              @@@                       H A P P Y
                              @@@
                      @@@@@@@@@@@@@@@@@@@@@@         H A L L O W E E N
                    @@@@@@@@@@@@@@@@@@@@@@@@@@
                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                @@@@@@@@ @@@@@@@@@@@@@@@@ @@@@@@@@
              @@@@@@@@@   @@@@@@@@@@@@@@   @@@@@@@@@
            @@@@@@@@@@     @@@@@@@@@@@@     @@@@@@@@@@
           @@@@@@@@@@       @@@@  @@@@       @@@@@@@@@@
           @@@@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@@@@@
           @@@@@@@@@@@@@@@@@@        @@@@@@@@@@@@@@@@@@
           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
           @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
           @@@@@@@@@ @@@@@@@@@@@@@@@@@@@@@@@@ @@@@@@@@@
            @@@@@@@@  @@ @@ @@ @@ @@ @@ @@ @  @@@@@@@@
              @@@@@@@                        @@@@@@@
                @@@@@@  @@ @@ @@ @@ @@ @@ @ @@@@@@
                  @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
                    @@@@@@@@@@@@@@@@@@@@@@@@@@
                      @@@@@@@@@@@@@@@@@@@@@@

```

In the 1980s and 1990s, computers did not have graphics displays. Everything was just text on a screen. And not everyone had fancy, expensive software so everyone used plain text to exchange information.

When you have a computer an no graphics and a burning desire to create some visual art, you may just decide to try your hand at [ASCII art](https://en.wikipedia.org/wiki/ASCII_art).

ASCII stands for American Standard Code for Information Interchange. It is a standards creation body which established in 1963 a 7-bit (not 8-bit!) encoding for 128 different symbols used on [teletype](https://en.wikipedia.org/wiki/Teleprinter) machines and later on early computers. Of the 128 symbols, 95 of the symbols are printable symbols, a-z, A-Z, 0-9, punctuation, etc.

ASCII evolved into ANSI, American National Standards Institute. ANSI created a number of other standards, one of which is [ANSI X3.64](https://en.wikipedia.org/wiki/ANSI_escape_code) which is the ANSI escape codes.

The ANSI escape codes meant that terminals could display text, colored text, and have some rudimentary control of the cursor to create sophisticated textual displays.

With a little time and a pinch of creativity, you could create a nice little piece of [art](http://textfiles.com/art/) or even piece together an animation.

What we can do is use our knowledge of reading from a file and printing to a screen to play the animations on our Linux computers. Unfortunately, our modern computers are so fast that the animations do not play correctly so we will have to intentionally slow down our computers by putting them to sleep.

In the C++ standard library there is a `chrono` header file which defines [duration of time](https://en.cppreference.com/w/cpp/chrono/duration) and a `thread` header file which defines a function `std::this_thread::sleep_for()` that pauses the program's execution.

If I want to stop my program for 2,000 microseconds (2 milliseconds or 0.002 seconds), then I just need to call `sleep_for()` with that value as a parameter. The `chrono` header file defines how to convert it to microseconds when you place the `us` next to the value 2,000. (The letter `u` represent the Greek letter mu or µ.)

```c++
std::this_thread::sleep_for(2000us);
```

Most computer only need a 2,000 microsecond pause to ensure smooth animations. Start by putting your program to sleep for 2,000 microseconds after reading a line of text from the input file. Adjust the value up or down to make the animations play smoothly on your computer. If the animation is too fast, increase 2,000 microseconds to 4,000 microseconds. If the animation is too slow, decrease 2,000 microseconds to 1,000 microseconds.

Because the needs of this program is to print the data in the animation input file one letter at a time, we will use the member function [get()](https://en.cppreference.com/w/cpp/io/basic_istream/get) to read one character out of the input file stream and then immediately print it to the terminal. Doing this repeatedly in a while loop will display the animation.

(This exercise is uncannily similar to part-1. In part-1, the input file is read one line at a time. In this exercise, the input is read one letter at a time.)

A `char` is a data type that is used to represent a single byte (8 bits). To put this in perspective, an `int` is 4 bytes which means you can fit 4 `char` variables inside of every `int` variable. And although the name is `char` and we readily imagine that `char` represents a letter, a  `char` is just a series of bits that represents a number.

```c++
char letter{0};
while (input_file_stream.get(letter)) {
    std::cout << letter;
    std::this_thread::sleep_for(2000us);
}
```

As in previous exercises, the `ifstream` variable `input_file_stream` will signal to the loop when there are no more letters to read from the file and exit the loop.

If your terminal gets messed up or doesn't behave correctly, try resetting it with the `reset` command. If that doesn't fix the problem, close and open a new terminal window.

## Requirements

Using `ifstream`, read the contents of an ANSI animation file and print it to the terminal one character at a time such that the animation playsback smoothly. Use the `get()` method to read one `char` value from the file at a time and print out the char to the terminal. Use `sleep_for()` to pause execution of your program.

The default delay is 2,000 microseconds however you may adjust the value depending on the performance of your computer.


The program takes one command line arguments other than the program's name. The first argument is the path to the input file.

To fetch animation files for your use, use the `make fetchanimations` command. The `make cleananimations` command will delete the files that are downloaded.

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
* *fetchanimations*: download sample animation files from textfiles.com (do this only once)
* *cleananimations*: remove sample animation files that were downloaded

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
$ ls
animation_urls.txt  Makefile  play_animation.cc  README.md
$ make
set -e; clang++ -MM -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 play_animation.cc \
| sed 's/\(play_animation\)\.o[ :]*/\1.o play_animation.d : /g' > play_animation.d; \
[ -s play_animation.d ] || rm -f play_animation.d
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -D LINUX -D AMD64 -c play_animation.cc
clang++ -g -O3 -Wall -pedantic -pipe -std=c++17 -o play_animation play_animation.o 
$ make fetchanimations
for i in http://www.textfiles.com/art/bambi.vt http://www.textfiles.com/art/beer.vt http://www.textfiles.com/art/bomb.vt http://www.textfiles.com/art/cartwhee.vt http://www.textfiles.com/art/dont-wor.vt http://www.textfiles.com/art/firework.vt http://www.textfiles.com/art/fireworks.vt http://www.textfiles.com/art/fishy2.vt http://www.textfiles.com/art/glass.vt http://www.textfiles.com/art/globe.vt http://www.textfiles.com/art/juanspla.vt http://www.textfiles.com/art/jumble.vt http://www.textfiles.com/art/nasa.vt http://www.textfiles.com/art/paradise.vt http://www.textfiles.com/art/prey.vt http://www.textfiles.com/art/snowing.vt http://www.textfiles.com/art/tetris.vt http://www.textfiles.com/art/trek.vt http://www.textfiles.com/art/turkey.vt http://www.textfiles.com/art/tv.vt http://www.textfiles.com/art/twilight.vt http://www.textfiles.com/art/valentin.vt http://www.textfiles.com/art/wineglas.vt http://www.textfiles.com/art/xmas.vt; do \
	wget -nc $i; \
done
--2022-10-23 23:22:38--  http://www.textfiles.com/art/bambi.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 12818 (13K)
Saving to: ‘bambi.vt’

bambi.vt            100%[===================>]  12.52K  --.-KB/s    in 0.001s  

2022-10-23 23:22:38 (11.8 MB/s) - ‘bambi.vt’ saved [12818/12818]

--2022-10-23 23:22:38--  http://www.textfiles.com/art/beer.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 14415 (14K)
Saving to: ‘beer.vt’

beer.vt             100%[===================>]  14.08K  --.-KB/s    in 0.08s   

2022-10-23 23:22:38 (184 KB/s) - ‘beer.vt’ saved [14415/14415]

--2022-10-23 23:22:38--  http://www.textfiles.com/art/bomb.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 2649 (2.6K)
Saving to: ‘bomb.vt’

bomb.vt             100%[===================>]   2.59K  --.-KB/s    in 0s      

2022-10-23 23:22:39 (19.9 MB/s) - ‘bomb.vt’ saved [2649/2649]

--2022-10-23 23:22:39--  http://www.textfiles.com/art/cartwhee.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 17418 (17K)
Saving to: ‘cartwhee.vt’

cartwhee.vt         100%[===================>]  17.01K  --.-KB/s    in 0.08s   

2022-10-23 23:22:39 (222 KB/s) - ‘cartwhee.vt’ saved [17418/17418]

--2022-10-23 23:22:39--  http://www.textfiles.com/art/dont-wor.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 15305 (15K)
Saving to: ‘dont-wor.vt’

dont-wor.vt         100%[===================>]  14.95K  --.-KB/s    in 0.08s   

2022-10-23 23:22:39 (193 KB/s) - ‘dont-wor.vt’ saved [15305/15305]

--2022-10-23 23:22:39--  http://www.textfiles.com/art/firework.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 34801 (34K)
Saving to: ‘firework.vt’

firework.vt         100%[===================>]  33.99K   223KB/s    in 0.2s    

2022-10-23 23:22:39 (223 KB/s) - ‘firework.vt’ saved [34801/34801]

--2022-10-23 23:22:39--  http://www.textfiles.com/art/fireworks.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 6727 (6.6K)
Saving to: ‘fireworks.vt’

fireworks.vt        100%[===================>]   6.57K  --.-KB/s    in 0s      

2022-10-23 23:22:40 (14.2 MB/s) - ‘fireworks.vt’ saved [6727/6727]

--2022-10-23 23:22:40--  http://www.textfiles.com/art/fishy2.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 211945 (207K)
Saving to: ‘fishy2.vt’

fishy2.vt           100%[===================>] 206.98K   272KB/s    in 0.8s    

2022-10-23 23:22:41 (272 KB/s) - ‘fishy2.vt’ saved [211945/211945]

--2022-10-23 23:22:41--  http://www.textfiles.com/art/glass.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 11620 (11K)
Saving to: ‘glass.vt’

glass.vt            100%[===================>]  11.35K  --.-KB/s    in 0.001s  

2022-10-23 23:22:41 (15.1 MB/s) - ‘glass.vt’ saved [11620/11620]

--2022-10-23 23:22:41--  http://www.textfiles.com/art/globe.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 29696 (29K)
Saving to: ‘globe.vt’

globe.vt            100%[===================>]  29.00K  --.-KB/s    in 0.08s   

2022-10-23 23:22:41 (377 KB/s) - ‘globe.vt’ saved [29696/29696]

--2022-10-23 23:22:41--  http://www.textfiles.com/art/juanspla.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 41773 (41K)
Saving to: ‘juanspla.vt’

juanspla.vt         100%[===================>]  40.79K   268KB/s    in 0.2s    

2022-10-23 23:22:41 (268 KB/s) - ‘juanspla.vt’ saved [41773/41773]

--2022-10-23 23:22:41--  http://www.textfiles.com/art/jumble.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 28816 (28K)
Saving to: ‘jumble.vt’

jumble.vt           100%[===================>]  28.14K  --.-KB/s    in 0.08s   

2022-10-23 23:22:41 (361 KB/s) - ‘jumble.vt’ saved [28816/28816]

--2022-10-23 23:22:41--  http://www.textfiles.com/art/nasa.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 19159 (19K)
Saving to: ‘nasa.vt’

nasa.vt             100%[===================>]  18.71K  --.-KB/s    in 0.08s   

2022-10-23 23:22:42 (240 KB/s) - ‘nasa.vt’ saved [19159/19159]

--2022-10-23 23:22:42--  http://www.textfiles.com/art/paradise.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 24788 (24K)
Saving to: ‘paradise.vt’

paradise.vt         100%[===================>]  24.21K  --.-KB/s    in 0.08s   

2022-10-23 23:22:42 (312 KB/s) - ‘paradise.vt’ saved [24788/24788]

--2022-10-23 23:22:42--  http://www.textfiles.com/art/prey.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 9010 (8.8K)
Saving to: ‘prey.vt’

prey.vt             100%[===================>]   8.80K  --.-KB/s    in 0s      

2022-10-23 23:22:42 (18.2 MB/s) - ‘prey.vt’ saved [9010/9010]

--2022-10-23 23:22:42--  http://www.textfiles.com/art/snowing.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 10334 (10K)
Saving to: ‘snowing.vt’

snowing.vt          100%[===================>]  10.09K  --.-KB/s    in 0.001s  

2022-10-23 23:22:42 (11.6 MB/s) - ‘snowing.vt’ saved [10334/10334]

--2022-10-23 23:22:42--  http://www.textfiles.com/art/tetris.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 9176 (9.0K)
Saving to: ‘tetris.vt’

tetris.vt           100%[===================>]   8.96K  --.-KB/s    in 0.001s  

2022-10-23 23:22:42 (15.5 MB/s) - ‘tetris.vt’ saved [9176/9176]

--2022-10-23 23:22:42--  http://www.textfiles.com/art/trek.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 21075 (21K)
Saving to: ‘trek.vt’

trek.vt             100%[===================>]  20.58K  --.-KB/s    in 0.08s   

2022-10-23 23:22:43 (267 KB/s) - ‘trek.vt’ saved [21075/21075]

--2022-10-23 23:22:43--  http://www.textfiles.com/art/turkey.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 13183 (13K)
Saving to: ‘turkey.vt’

turkey.vt           100%[===================>]  12.87K  --.-KB/s    in 0.001s  

2022-10-23 23:22:43 (19.0 MB/s) - ‘turkey.vt’ saved [13183/13183]

--2022-10-23 23:22:43--  http://www.textfiles.com/art/tv.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 63909 (62K)
Saving to: ‘tv.vt’

tv.vt               100%[===================>]  62.41K   204KB/s    in 0.3s    

2022-10-23 23:22:43 (204 KB/s) - ‘tv.vt’ saved [63909/63909]

--2022-10-23 23:22:43--  http://www.textfiles.com/art/twilight.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 64272 (63K)
Saving to: ‘twilight.vt’

twilight.vt         100%[===================>]  62.77K   207KB/s    in 0.3s    

2022-10-23 23:22:44 (207 KB/s) - ‘twilight.vt’ saved [64272/64272]

--2022-10-23 23:22:44--  http://www.textfiles.com/art/valentin.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 3702 (3.6K)
Saving to: ‘valentin.vt’

valentin.vt         100%[===================>]   3.62K  --.-KB/s    in 0s      

2022-10-23 23:22:44 (111 MB/s) - ‘valentin.vt’ saved [3702/3702]

--2022-10-23 23:22:44--  http://www.textfiles.com/art/wineglas.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 9749 (9.5K)
Saving to: ‘wineglas.vt’

wineglas.vt         100%[===================>]   9.52K  --.-KB/s    in 0.001s  

2022-10-23 23:22:44 (18.4 MB/s) - ‘wineglas.vt’ saved [9749/9749]

--2022-10-23 23:22:44--  http://www.textfiles.com/art/xmas.vt
Resolving www.textfiles.com (www.textfiles.com)... 208.86.224.90
Connecting to www.textfiles.com (www.textfiles.com)|208.86.224.90|:80... connected.
HTTP request sent, awaiting response... 200 OK
Length: 45723 (45K)
Saving to: ‘xmas.vt’

xmas.vt             100%[===================>]  44.65K   294KB/s    in 0.2s    

2022-10-23 23:22:44 (294 KB/s) - ‘xmas.vt’ saved [45723/45723]

$ ./play_animation 
Please provide a path to a file.
$ ./play_animation /non-existant-file
Could not open the file /non-existant-file. Exiting.
$ ./play_animation xmas.vt 
$ make test
2022-10-23 23:26:03,556 - INFO - Start Testing Tuffy Titan tuffy@fullerton.edu @tuffy
2022-10-23 23:26:03,556 - INFO - All files: ./play_animation.cc
2022-10-23 23:26:03,593 - INFO - ✅ Formatting passed on ./play_animation.cc
2022-10-23 23:26:07,894 - INFO - ✅ Linting passed in ./play_animation.cc
2022-10-23 23:26:08,728 - INFO - ✅ Build passed
2022-10-23 23:26:08,729 - INFO - Test 1 - ['Empty', 'Please provide a path to a file']
2022-10-23 23:26:08,833 - INFO - Test 2 - ['/foobar', 'Could not open the file /foobar']
2022-10-23 23:26:08,939 - INFO - This may take a while: Test 3 - ['Makefile']
2022-10-23 23:26:16,817 - INFO - ✅ All test runs passed
2022-10-23 23:26:16,817 - INFO - End Testing Tuffy Titan tuffy@fullerton.edu @tuffy
```

## What to Do

1. With your partner, edit the `play_animation.cc` source file using VS Code. Add the required header. Replace all the TODO comments with working code.
1. Compile your program with the `$ make` shell command. Use the **debug compile error** procedure to debug any compile errors.
1. Run your program with the `$ ./play_animation` shell command.
1. Test that your program passes all of the test cases in the test suite above. If your program suffers a runtime error, use the **debug runtime error** procedure to debug the error. If your program does not produce the expected output, use the **debug logic error** procedure to debug the error.
1. Test your program against automated test with the `$ make test` command. Debug any runtime errors or logic errors using the same procedures.
1. Check your header with the `$ make header` shell command. Correct any errors.
1. Check for format errors with the `$ make format` shell command. Correct any errors.
1. Check for lint errors with the `$ make lint` shell command. Correct any errors.
1. After your program passes all of these tests and checks, push your code to GitHub. Use the usual trio of commands: `git add`, `git commit`, and `git push`.

## Next Steps

After you have pushed your code, you are done with this lab. You may ask your TA for permission to sign out and leave.

