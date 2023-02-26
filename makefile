driver.exe: TagEnum.o driver.o
	g++ TagEnum.o driver.o -o driver.exe -std=c++20
TagEnum.o: TagEnum.cpp
	g++ -c TagEnum.cpp -o TagEnum.o -std=c++20
driver.o: driver.cpp
	g++ -c driver.cpp -o driver.o -std=c++20
clean: 
	rm *.o driver.exe
