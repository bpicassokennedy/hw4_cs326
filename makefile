hw4: driver.o
	g++ -o hw4 driver.o 
driver.o: driver.cpp 
	g++ -c driver.cpp -g
clean:
	rm *.o hw4