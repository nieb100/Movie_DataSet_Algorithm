CXX_FLAG = --std=c++11 -g
all:runMovies

movies.o: movies.cpp
	g++ ${CXX_FLAG} movies.cpp -c

main.o: main.cpp
	g++ ${CXX_FLAG} main.cpp -c

runMovies: movies.o main.o
	g++ ${CXX_FLAG} movies.o main.o -o runMovies