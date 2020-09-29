RM=/bin/rm -f
#calling 'make all' will ensure that every feature of the program is compiled
all: main

#create object file for header
run.o: header.h admin.h list.h password.h user.h main.cpp
	g++ -c main.cpp

#create the executable
run:run.o
	g++ -c -o run run.o

#to clean files generated during compilations.
#call 'make clean'
clean:
	${RM} *.o run main
