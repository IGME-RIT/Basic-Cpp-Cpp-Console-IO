/*
C++ Console IO
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>
*/



#include <string>

// The focus of this example will be on the isotream header, and its included objects.
#include <iostream>
#include <iomanip>

int main()
{
    // Primarily, we have cin and cout.
    {
        // You already know that cout can be used to write out to the console window like this:
        std::cout << "Press enter to continue.";

        // and you know that cin can be used to wait for input:
        std::cin.get();
    }



    {
        // cout is an ostream object, which means it has some other functions we can use:

        // put prints a single character, without any casting or formatting.
        std::cout.put(157);  // 157 is ¥

        std::cout.put('\n'); // new line

        // write prints out a given string up to a number of characters.
        std::cout.write("words cannot describe", 4);

        std::cin.get();
    }



    {
        // cout has some nice formatting functions too:

        // When printing floats, the decimal defaults to a large number, but it doesn't have to be that way.
        std::cout << 9.99999f << std::endl;

        std::cout.precision(3); // precision changes the maximum number of numbers to output, this will round the value before printing.
        std::cout << 9.99999f << std::endl;
 

        std::cout.width(10);    // width adds extra spaces to output to make output length uniform (if less than the width). 
        std::cout << 9.99999f << std::endl;


        std::cout.width(10);    // formatting calls have to be made every time you want to output. It's pretty bad, but that's how it works.
        std::cout.fill('-');    // fill sets the character to be used when filling the gaps made by having a width higher than 0
        std::cout << 9.99999f << std::endl;


        std::cout.width(10);
        std::cout.fill('-');
        std::cout.setf(std::ios::left); // setf can be used to change some other settings in the output stream.
                                        // it takes in a value, and depending on the value passed in, affects different things.
                                        // ios::left left justifies the output.
        std::cout << 9.99999f << std::endl;


        // these can also be written this way using manipulators from the iomanip library
        // These get applied to the stream from left to right, and each one returns std::cout
        std::cout << std::setw(10) << std::setfill('-') << std::setiosflags(std::ios::left) << 9.99999f << std::endl;
    
        // As you may have already guessed, std::endl actually falls into the category of stream manipulators.
    }
    std::cin.get();



    {
        // Now lets get some input!

        // just like you can do cout << string, we can do the opposite with cin
        std::cout << "type something:" << std::endl;

        std::string input;
        std::cin >> input;  // This reads from the input stream when you press enter.
                            // Unfortunately, it leaves the new line in the input buffer.
        std::cin.get();     // Because of this, a calls like cin.get() (which waits for a newline) automatically pass.
                            // This can seriously mess with your formatting if you don't know what's going on.
        
        // output the variable passed in.
        std::cout << "You typed: " << input << std::endl;



        // cin >> might not always bee the best way to get input though, as it ends when it reaches a space.
        // If you want to include spaces in your input, cin.get will pull all of them up to a length.

        // First we need an empty string to store our data.
        char words[64];

        std::cout << "type something:" << std::endl;
        // Next call cin.get
        std::cin.get(words, 64);    // We pass in the string we want to write to, a length, (and a optional delimiting character).
                                    // It will copy from the input stream into the given string until it reaches the given length, or a delimiting character.
                                    // The last character will automatically be a null terminator, so it actually reads 1 less character than the number you give it.
        std::cin.get();             // Just like cin >>, this also leaves the newline in the stream.
        
        std::cout << "You typed: " << words << std::endl;


        std::cout << "type something:" << std::endl;
        // if you don't want to deal with the newline in the stream, you can use getline
        std::cin.getline(words, 64);    // The parameters for getline are exactly the same as get.
                                        // the only difference is that getline removes the newline at the end.

        std::cout << "You typed: " << words << std::endl;

    }
    std::cin.get();



    {
        // cin also supports storing data into non strings:

        int x;
        std::cout << "input a number: ";
        std::cin >> x;  // This isn't great though, because this can bug out if the user inputs something that isn't a number.
                        // What cin actually does, is read until it finds something that doesn't make sense, and thens stop.

                        // If you input a string like "foo", it will just stop and leave foo in the stream.
                        // If you input "500BC", it will get the "500" and leave "BC" in the stream.

        std::cin.get(); // cin also still has the problem of leaving the newline in the stream.
                        // unfortunately, we can't getline into an int.
        std::cout << "you input: " << x << std::endl;
        // or can we?

        std::cout << "input a number: ";
        
        // get input as a string:
        char input[256];
        std::cin.getline(input, 256);

        // atoi converts an ascii string to an integer
        int y = atoi(input);    // (if the string can't be converted to a number, it just returns 0)

        std::cout << "doubled: " << y * 2 << std::endl;
        
        // There are several other coversion functions similar to atoi for different string and value types as well.
        // For more of this, see https://msdn.microsoft.com/en-us/library/0heszx3w.aspx
    }
    std::cin.get();
}