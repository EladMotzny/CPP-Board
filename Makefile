CXX=clang++-5.0
CXXFLAGS=-std=c++17

a.out: Board.o Square.o IllegalCharException.o IllegalCoordinateException.o
		$(CXX) $(CXXFLAGS) main_OLD.cpp *.o

Board.o: Board.h Board.cpp
		$(CXX) $(CXXFLAGS) -c Board.cpp

Square.o: Square.h Square.cpp
		$(CXX) $(CXXFLAGS) -c Square.cpp

IllegalCharException.o: IllegalCharException.h
		$(CXX) $(CXXFLAGS) -c IllegalCharException.h

IllegalCoordinateException.o: IllegalCoordinateException.hpp
		$(CXX) $(CXXFLAGS) -c IllegalCoordinateException.hpp



clean: rm *.o a.out