# Makefile for building and running LuxPower SNA C++ tests

# Adjust these if your Homebrew prefix is different
GTEST_INC = /opt/homebrew/include
GTEST_LIB = /opt/homebrew/lib

CXX = g++
CXXFLAGS = -std=c++17 -I$(GTEST_INC) -Icomponents -I.
LDFLAGS = -L$(GTEST_LIB) -lgtest -lgtest_main -lpthread

TARGET = test_luxpower_sna
SRC = test_luxpower_sna.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)