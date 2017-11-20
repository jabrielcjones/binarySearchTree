a.out: driver.o
	c++ driver.o

driver.o: driver.cpp binary-search-tree01.cpp
	c++ -c driver.cpp

