#include <iostream>
#include <stdio.h>
#include <unistd.h>

#include "lib/framebuffer.h"
#include "lib/line.h"
#include "raster.h"

using namespace std;

int main()
{
	Framebuffer buf;

	int x1 = 55;
	int y1 = 147;
	int x2 = 550;
	int y2 = 80;
	int phase = 0;

	Line line(x1, y1, x2, y2);
	Line line2(550,80,478,569);
	Line line3(478,569,387,216);
	Line line4(387,216,64,492);
	Line line5(64,492,55,147);
	Raster raster(0,0,600,600);
	int t = 1;
	
	/*for(int t=1;t<=5;t++)
	{
		int cnt = 800;

		while(cnt--)
		{*/
			line.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			line2.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			line3.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			line4.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			line5.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// if (buf.isColor(10,10,0x534200,buf.BUF_MAIN)) {
			// 	line.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// 	line2.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// 	line3.Draw(buf, 0x534200, t, buf.BUF_MAIN);
			// }
			sleep(3);
			raster.Coloring(buf, 0x534200,0xFFFFFF,buf.BUF_MAIN);


			/*line.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			line2.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			
			/*if (phase == 0)
			{
				line.x1 += 1;
				if (line.x1 >= 200) phase = 1;
			}
			else if (phase == 1)
			{
				line.y1 += 1;
				if (line.y1 >= 200) phase = 2;
			}
			else if (phase == 2)
			{
				line.x1 -= 1;
				if (line.x1 <= 0) phase = 3;
			}
			else if (phase == 3)
			{
				line.y1 -= 1;
				if (line.y1 <= 0) phase = 0;
			}
			if (buf.isColor(100,100,0x5342f4,buf.BUF_BACK)) {
				//printf("AAAAAAAAAAAAAAAAAAAAAAAAa\n");
				line2.x1 = line2.x1 + 1;
				//line2.Draw(buf, 0x5342f4, t, buf.BUF_BACK);
			}
			buf.Flush();
			usleep(10000);*/
		/*}

		sleep(2);
	}*/

	return 0;
}