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
	bool startColor = false;
	//printf("WOW");
	for (y = offsetY; y < sizeY; y++) {
		for (x = offsetX; x < sizeX; x++) {
			if (startColor) {
				buf.Write(y,x,inColor,main);
			}
			if (buf.isColor(y,x,borderColor,main)) {
				startColor = !startColor;
			}
		}
	}
}