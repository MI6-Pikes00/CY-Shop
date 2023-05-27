# defines compiler
CC = gcc

#Repository
SRC_DIR := src

# defines executable name 
EXEC_NAME = CY-Shop

# get all c files
SRC=$(wildcard $(SRC_DIR)/*.c) # src/main.c

# build the executable
exec: $(SRC)
	$(CC) $^ -o $(EXEC_NAME)