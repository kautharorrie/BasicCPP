driver.exe: TagEnum.o main.o
	g++ TagEnum.o main.o -o driver.exe -std=c++20
TagEnum.o: TagEnum.cpp
	g++ -c TagEnum.cpp -o TagEnum.o -std=c++20
main.o: main.cpp
	g++ -c main.cpp -o main.o -std=c++20
clean: 
	rm *.o driver.exe
