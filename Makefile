CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

OBJS = alfabeto.o cadena.o lenguaje.o p02_strings.o

p02_strings: $(OBJS)
	$(CXX) $(CXXFLAGS) -o p02_strings $(OBJS)

%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f *.o p02_strings
