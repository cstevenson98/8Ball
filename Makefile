#!/bin/bash

CC=g++
INCLUDE=-Iinclude
LDFLAGS=-lGLEW -lGLU -lGL -lglfw
DEBUG=-g

OBJ=src/Debug.o src/GameEngine.o src/stb_image.o src/App.o src/linear.o src/Ball.o src/CueSports.o src/openGLutils.o src/main.o
all: $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) $(DEBUG) -o main

%.o: %.cpp
	$(CC) $(INCLUDE) $(LDFLAGS) $(DEBUG) -c $< -o $@

%.o: %.cu
	$(CC) $(INCLUDE) $(LDFLAGS) $(DEBUG) -c $< -o $@

clean:
	rm -v src/*.o
