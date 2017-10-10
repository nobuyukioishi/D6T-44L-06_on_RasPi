all: i2c_functions.o i2c_d6t.o d6t_fluent_test finish

i2c_functions.o: i2c_functions.c
	gcc -c i2c_functions.c -o i2c_functions.o

i2c_d6t.o: i2c_d6t.cpp
	g++ -c i2c_d6t.cpp -o i2c_d6t.o

d6t_fluent_test: main.cpp i2c_functions.o i2c_d6t.o
	g++ main.cpp -o d6t_fluent i2c_d6t.o i2c_functions.o -std=c++11 -lfluent

finish:
	echo "Finished compiling! Execute ./d6t_fluent !"
