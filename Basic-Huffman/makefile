CXX		:=g++
CXXFLAGS	:=-std=c++17 -g -Wall
INCLUDES	:=-I./Src
OUTPUT		:=./Output/Huffman.out

default: $(OUTPUT)
clean:
	rm -f $(OUTPUT)

$(OUTPUT):./Src/main.cpp
	g++ $(CXXFLAGS) $(INCLUDES) $^ -o $@
