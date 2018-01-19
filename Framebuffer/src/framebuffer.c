#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

/* ---- CONSTANTS ----- */

#define LETTER_NUMBER 1  // first LETTER_NUMBER letters which pixels are defined in ../font/font.txt
#define ROW_NUMBER 10  // row size of every letter
#define COL_NUMBER 7  // col size of every letter

#define FILE_NAME "font.txt" // font pixels configuration file name
#define FILE_PATH "../font/" // folder where font pixels configuration file is saved

#define PIXEL '+' // character representation of a pixel

int main()
{
    /* --------------- INITIALIZATION --------------- */

    int fbfd = 0;
    struct fb_var_screeninfo vinfo;
    struct fb_fix_screeninfo finfo;
    long int screensize = 0;
    char *fbp = 0;
    int x = 0, y = 0;
    long int location = 0;

    // Open the file for reading and writing
    fbfd = open("/dev/fb0", O_RDWR);
    if (fbfd == -1) {
        perror("Error: cannot open framebuffer device");
        exit(1);
    }
    //printf("The framebuffer device was opened successfully.\n");

    // Get fixed screen information
    if (ioctl(fbfd, FBIOGET_FSCREENINFO, &finfo) == -1) {
        perror("Error reading fixed information");
        exit(2);
    }

    // Get variable screen information
    if (ioctl(fbfd, FBIOGET_VSCREENINFO, &vinfo) == -1) {
        perror("Error reading variable information");
        exit(3);
    }

    //printf("%dx%d, %dbpp\n", vinfo.xres, vinfo.yres, vinfo.bits_per_pixel);

    // Figure out the size of the screen in bytes
    screensize = vinfo.xres * vinfo.yres * vinfo.bits_per_pixel / 8;

    // Map the device to memory
    fbp = (char *)mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfd, 0);
    if ((int)fbp == -1) {
        perror("Error: failed to map framebuffer device to memory");
        exit(4);
    }
    //printf("The framebuffer device was mapped to memory successfully.\n");


    /* --------------- OPEN FILE AND READ FONT PIXELS CONFIGURATION --------------- */

    FILE* file;
    char path[100]; // file path

    strcpy(path, FILE_PATH);
    strcat(path, FILE_NAME);

    printf("%s\n",path);
    file = fopen(path, "r");

    if(file)
    {
        bool pix[LETTER_NUMBER][ROW_NUMBER][COL_NUMBER]; // store font pixels, pix[0][1][2] = 1st letter (A), 2nd row, 3rd column, true/false = pixel on/off
        
        int letter, row, col; // iterators
        char c;

        for(letter = 0; letter < LETTER_NUMBER; letter++) // for every letter
        {
            for(row = 0; row < ROW_NUMBER; row++) // for every row
            {
                for(col = 0; col < COL_NUMBER; col++) // for every col
                {
                    c = fgetc(file); // read pixel configuration

                    if(c == PIXEL) pix[letter][row][col] = true;
                    else pix[letter][row][col] = false;
                }

                c = fgetc(file); // read newline and discard it
            }
        }

        fclose(file);

        for(letter = 0; letter < LETTER_NUMBER; letter++) // for every letter
        {
            for(row = 0; row < ROW_NUMBER; row++) // for every row
            {
                for(col = 0; col < COL_NUMBER; col++) // for every col
                {
                    if(pix[letter][row][col]) printf("+");
                    else printf(" ");
                }

                printf("\n");
            }
        }

        exit(0);
    }
    else
    {
        perror("Error: failed to open file");
        exit(5);
    }


    /* --------------- READ INPUT --------------- */

    printf("----- CUSTOM FONT RENDERER -----\n\n");
    printf("Want to see our font? Check it out now!\nType anything below without whitespace, A-Z only, and max length is 50.\n\n");
    printf("Input : ");

    char in[50]; // user's input
    scanf("%s",in);

    printf("%s\n",in);


    /* --------------- RENDERING --------------- */

    x = 100; y = 100; // Where we are going to put the pixel

    // Figure out where in memory to put the pixel
    for(y = 4; y < 14; y++)
    {
        for(x = 0; x < 8; x++)
        {
            location = (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) +
                       (y+vinfo.yoffset) * finfo.line_length;

            *(fbp + location) = 255; // Blue value
            *(fbp + location + 1) = 255; // Green value
            *(fbp + location + 2) = 255; // Red value
            *(fbp + location + 3) = 0;  // Transparency value (α)
        }
    }

    munmap(fbp, screensize);
    close(fbfd);
    return 0;
}