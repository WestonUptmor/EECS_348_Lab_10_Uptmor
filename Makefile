CXX      = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET   = Lab5
SRC      = Lab_5.cpp

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

.PHONY: clean