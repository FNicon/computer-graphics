#pragma once

#include "lib/framebuffer.h"
class Raster {
	private :
		int sizeX;
		int sizeY;
		int offsetX;
		int offsetY;

	public:
		Raster(int _offsetX, int _offsetY, int _sizeX, int _sizeY);
		void Coloring(Framebuffer& buf, int borderColor, int inColor, bool main);
};