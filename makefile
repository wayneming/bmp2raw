CC = g++
CFLAGS = -O3 -pipe -fomit-frame-pointer -funroll-all-loops -s

bmp2raw:
	g++ -o bmp2raw bmp2raw.cpp EasyBMP.cpp

clean: 
	rm bmp2raw
	rm -f *.o
