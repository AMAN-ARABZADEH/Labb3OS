# Labb3OS
I created this program to allocate a chunk of memory based on user input in either GiB or KiB. The program starts by displaying a menu and asking the user to select their choice. Once the user enters their choice, the program uses a switch statement to call the ByteSize() function passing in the appropriate value for the selected choice.

Inside the ByteSize() function, the program creates a dynamic array of int64_t to allocate memory. The function checks the user's choice, and based on that, it allocates memory either in GiB or KiB using a while loop that runs indefinitely until the program is terminated. The function also keeps track of the total memory allocated and the number of GiBs or KiBs used.

Finally, the program measures the total time taken to allocate the memory and displays it. The code is written in C++ and utilizes the <iostream> and <chrono> libraries.
