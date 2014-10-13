/*
         		bmp2raw

author:			Wayne.M.Zhang
email:			wayne.m.zhang@gmail.com
date added:		10-18-2011
date modified:	10-18-2011
version:		1.01
license:		BSD (revised/modified)
description:	bmp2raw is a simple tool to convert 24bit BMP file to raw data. 
	It may be useful before generating C arrays for showing a picture in 
	an embeded system.
	The color order in the output file is (B,G,R),(B,G,R), ...
*/

#include <stdio.h>
#include "EasyBMP.h"

using namespace std;

int main(int argc, char* argv[])
{
	RGBApixel* pixel;
	BMP input;
	FILE* output;
	unsigned int w;
	unsigned int h;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	if(argc != 3)
	{
		cout << "usage: bmp2raw <input_filename> <outputput_filename>"
		<< endl << endl;
		return 1;
	}

	if(! input.ReadFromFile(argv[1]) )
	{
		cout << "open file " << argv[1] << "fail" << endl;
		return 1;
	}
	
	if(24 != input.TellBitDepth())
	{
		cout << argv[1] << "is not a 24bit bmp file !" << endl;
		return 1;
	}

	output = fopen(argv[2], "w+");
	if(output == NULL)
	{
		cout << "create file" << argv[2] << "fail" << endl;
		return 1;
	}
	
	w = input.TellWidth();
	h = input.TellHeight();

	for(int j=0; j < h; j++)
	{
		for( int i=0; i < w; i++)
		{
			pixel = input(i,j);
			
			r =pixel->Red;
			g =pixel->Green;
			b =pixel->Blue;

			fwrite(&b, 1, 1, output);
			fwrite(&g, 1, 1, output);
			fwrite(&r, 1, 1, output);
		}
	}
	
	fclose(output);

	return 0;
}

