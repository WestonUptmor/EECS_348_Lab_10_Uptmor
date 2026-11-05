CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
TARGET   = Lab10
SRC      = Lab_10.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)

.PHONY: all clean