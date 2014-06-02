CC = g++
objects = scanner.o parser.o public.o
parser : $(objects)
	$(CC) -o parser $(objects)
scanner.o : scanner.cpp scanner.h public.h parser.hpp
	$(CC) -c scanner.cpp
parser.o : parser.cpp public.h scanner.h
	$(CC) -c parser.cpp
public.o : public.cpp public.h
	$(CC) -c public.cpp
clean:
	del $(objects)
	del parser.exe
ly:
	flex -o scanner.cpp scanner.l
	bison -o parser.cpp parser.y