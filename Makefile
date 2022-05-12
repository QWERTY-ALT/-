a.exe:main.o e.o 
	wg++ -fno-elide-constructors -std=c++11 -fopenmp e.o main.o  
main.o: main.cpp e.h
	wg++ -fno-elide-constructors -std=c++11 -fopenmp main.cpp -c
e.o: e.cpp e.h
	wg++ -fno-elide-constructors -std=c++11 -fopenmp e.cpp -c