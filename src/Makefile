all: run valgrind valgrindleak run_new

run:
	clear
	g++ -o main main.cpp
	./main

valgrind:
	clear
	g++ -g -o main main.cpp -Wall
	valgrind --track-origins=yes ./main

valgrindleak:
	clear
	g++ -g -o main main.cpp -Wall
	valgrind --leak-check=full ./main

run_new:
	clear
	g++ -o new_main new_main.cpp -Wall
	./new_main
