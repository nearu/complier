CC = g++
objects = scanner.o parser.o public.o main.o
main : $(objects)
	$(CC) -o main $(objects)
main.o : main.cpp public.h
	$(CC) -c main.cpp
scanner.o : scanner.cpp scanner.h public.h parser.hpp
	$(CC) -c scanner.cpp
parser.o : parser.cpp public.h scanner.h
	$(CC) -c parser.cpp
public.o : public.cpp public.h
	$(CC) -c public.cpp
clean:
	del $(objects)
	del main.exe
ly:
	flex -o scanner.cpp scanner.l
	bison -o parser.cpp parser.y