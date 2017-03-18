#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: main

# Tool invocations
# Executable "main" depends on the files hello.o and run.o.
main: main.o add.o numbers.o
	gcc -g -m32 -Wall -o numbers numbers.o main.o add.o

# Depends on the source and header files
numbers.o: numbers.c
	gcc -m32 -g -Wall -ansi -c -std=c11 -Iinclude -o numbers.o numbers.c 
 
main.o: main.c 
	gcc -m32 -g -Wall -ansi -c -std=c11 -Iinclude -o main.o main.c
	
add.o: add.s
	nasm -g -f elf -w+all -o add.o add.s


#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o main