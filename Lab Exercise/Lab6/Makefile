CC=clang++

all: main++14 -o $@ $^

main.o: main.cpp stock_management.h
    $(CC) -std=c++14 -c $<

stock_management.o: stock_management.cpp stock_management.h
    $(CC) -std=c++14 

main: main.o stock_management.o
    $(CC) -std=c-c $<