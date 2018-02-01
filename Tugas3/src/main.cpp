#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "framebuffer.h"
#include "line.h"

using namespace std;

int main(){
	Framebuffer buf;

	int x1 = 0;
	int y1 = 0;
	int x2 = 100;
	int y2 = 100;
	int phase = 0;

	Line line(x1, y1, x2, y2);
	int cnt = 800;

	while(cnt--) {
	line.draw(buf, 0x5342f4, buf.BUF_BACK);
	if (phase == 0) {
		line.x1 = line.x1 + 1;
		if (line.x1 >= 200) {
			phase = 1;
		}
	} else if (phase == 1) {
		line.y1 = line.y1 + 1;
		if (line.y1 >= 200) {
			phase = 2;
		}
	} else if (phase == 2) {
		line.x1 = line.x1 - 1;
		if (line.x1 <= 0) {
			phase = 3;
		}
	} else if (phase == 3) {
		line.y1 = line.y1 -1;
		if (line.y1 <= 0) {
			phase = 0;
		}
	}
	buf.flush();
	usleep(10000);
	}

	return 0;
}