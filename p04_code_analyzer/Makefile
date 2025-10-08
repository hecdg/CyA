CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2
SRCS = main.cc code_analyzer.cc code_structure.cc variable.cc loop.cc comment.cc
OBJS = $(SRCS:.cc=.o)
TARGET = p04_code_analyzer

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
