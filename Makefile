# defines compiler
CC = gcc
# defines executable name 
EXEC_NAME = CY-Shop

# get all c files
SRC=$(wildcard *.c) # src/main.c

# build the executable
exec: $(SRC)
	$(CC) $^ -o $(EXEC_NAME)