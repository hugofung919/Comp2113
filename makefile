main_12.o: main_12.cpp header_12.h
	g++ -c main_12.cpp
make_matrix_12.o: make_matrix_12.cpp header_12.h
	g++ -c make_matrix_12.cpp
print_cards_12.o: print_cards_12.cpp header_12.h
	g++ -c print_cards_12.cpp
main_12: main_12.o make_matrix_12.o print_cards_12.o
	g++ main_12.o make_matrix_12.o print_cards_12.o -o main_12
