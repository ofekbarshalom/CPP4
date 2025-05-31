CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -Werror

SRC = main.cpp
HEADERS = MyContainer.hpp Iterators.hpp
TARGET = Main
TEST_TARGET = test

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

test: $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -DTESTING $(SRC) -o $(TEST_TARGET)
	./$(TEST_TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)

demo:
	g++ -std=c++20 -Wall -Wextra -Werror Demo.cpp -o demo
	./demo