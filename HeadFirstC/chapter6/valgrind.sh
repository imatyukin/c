gcc -g spies.c -o spies
valgrind --leak-check=full ./spies
