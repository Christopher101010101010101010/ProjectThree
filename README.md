# ProjectThree

# In Project Three, I am presented with the scenario of a Grocery Store that needs software to track it's inventory 
#  by tracking the number of purchases of each item purchased in a given day. To accomplish this I developed the outer shell of the program
#  that consists of a main menu written in C++ with three separate branches that call Python coded functions; the first outputs a comprehensive list of all items
#  purchased and the number of times each item was purchased, the second allows the user to search for the number of times a specified item was purchased in
#  a given day, and the third Python coded function presents a text-based histogram listing the items purchased in a given day counted by ouputing an asterisk
#  for each purchase of an item.

# In this assignment I excelled at refining the functionality of my C++ and Python code, while maintaining consistent commenting to allow for others to follow
#  the logical processes.

# This code could be improved in several ways, I could add a try-catch block when accessing the Input_File.txt to avoid create a smooth termination should
#  Input_File.txt be curropt or in the improper directory and I could implement a test function to ensure the user does not attempt to input a double, string
#  or char when choosing the main menu option, that is restricted to integers 1, 2, 3 and 4. These alterations would prevent memory leaks, looping complications 
#  and other bugs within the C++ code.

# The most difficult section to code in this program is the Input_File.txt access code and the read file to list code. When developing this program
#  I had constant issue accessing the Input_File.txt file by the ./ or current directory prefix, that should have directed the open function to the Release
#  directory where the executable is located along but the result was inconsistent access to the Input_File.txt file. This bug was corrected by replacing
#  the ./ prefix with the ../Release/ Parent directory followed by Release directory prefixes. When reading the file to a list I had complications with read()
#  that produced a single string and readlines() that produced a list with each line being an individual element but each element's all character was the newline
#  symbol that made equivalency comparisons between equivalent elements return false on occasion. To simplify the elements of the list for improved comparisons
#  I had the text document processed by .read().splitlines() to return a list with each element being a line from the file excluding the newline character.

# The greatest complication I encountered during the development of this program was a time-crunch. I procrastinated until I had only two days till the deadline
#  and due to this procrastination I had to develop solutions and process my frustration regarding bugs much faster than is desirable. Therefore in future projects
#  I will choose to work through the development cycle before the deadline of the project is looming overhead. During the development of this program I learned
#  how to implement Python code within a C++ program that will prove an important skill in future developments.

# This program is maintainable, readable and adaptable due to the module nature of it's design. Each branch of this program, written in Python code, acts
#  as independent functions/modules that can be copied from this program and repurposed into another program that requires comparable functionality. I also
#  employ consistent white spacing and constant commenting to ensure the flow of the program understandable.
