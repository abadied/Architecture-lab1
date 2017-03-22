#format is target-name: target dependencies
#{-tab-}actions

# All Targets
all: encoder

# Tool invocations
# Executable "main" depends on the files hello.o and run.o.
encoder: encoder.o
	gcc -g -m32 -Wall -o encoder encoder.o

# Depends on the source and header files
encoder.o: encoderC.c
	gcc -m32 -g -Wall -ansi -c -std=c11 -Iinclude -o encoder.o encoderC.c 
 


#tell make that "clean" is not a file name!
.PHONY: clean

#Clean the build directory
clean: 
	rm -f *.o encoder