#include "raster.h"

#include <cstdlib>
#include <iostream>

using namespace std;

Raster::Raster(int _offsetX, int _offsetY, int _sizeX, int _sizeY) {
	sizeX = _sizeX;
	sizeY = _sizeY;
	offsetX=_offsetX;
	offsetY=_offsetY;
}

void Raster::Coloring(Framebuffer& buf, int borderColor, int inColor, bool main) {
	int x;
	int y;
	bool startColor;
	//printf("WOW");
	for (y = offsetY; y < sizeY; y++) {
		startColor = false;
		for (x = offsetX; x < sizeX; x++) {
			if (buf.isColor(y,x,borderColor,main) && !buf.isColor(y,x+1,borderColor,main)) {
				startColor = !startColor;
			}
			if (startColor) {
				buf.Write(y,x,inColor,main);
			}
		}
	}
}