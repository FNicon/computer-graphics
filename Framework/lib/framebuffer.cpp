#include "framebuffer.h"

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

using namespace std;

Framebuffer::Framebuffer()
{
    fd = open("/dev/fb0", O_RDWR); // Open framebuffer device
    
    if(fd == -1)
    {
        cerr << "Failed to open framebuffer device! " << strerror(errno) << "." << endl;
        exit(1);
    }

    // Get fixed screen information
    if(ioctl(fd, FBIOGET_FSCREENINFO, &fixed_info) == -1)
    {
        cerr << "Cannot read fixed screen information! " << strerror(errno) << "." << endl;
        exit(2);
    }
    
    // Get variable screen information
    if(ioctl(fd, FBIOGET_VSCREENINFO, &var_info) == -1)
    {
        cerr << "Cannot read variable screen information! " << strerror(errno) << "." << endl;
        exit(3);
    }

    // Count the size of screen in bytes
    size = var_info.xres * var_info.yres * var_info.bits_per_pixel / 8;

    // Map framebuffer device to memory
    main_buffer = (char*) mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

    if(main_buffer == MAP_FAILED)
    {
        cerr << "Failed to map framebuffer device to memory! " << strerror(errno) << "." << endl;
        exit(4);
    }

    // Memory allocation for back buffer
    back_buffer = (char*) malloc(size);

    if(back_buffer == NULL)
    {
        cerr << "Failed to allocate memory for back buffer! " << strerror(errno) << "." << endl;
        exit(5);
    }

    // Give all buffers initial value of 0
    memset(main_buffer, 0, size);
    memset(back_buffer, 0, size);
}

Framebuffer::~Framebuffer()
{
    munmap(main_buffer, size); // Unmap main buffer
    free(back_buffer); // Free back buffer memory
    close(fd); // Close framebuffer device
}

void Framebuffer::Write(int row, int column, int color, bool main)
{
    // Count starting byte
    int start_byte = (column + var_info.xoffset) * (var_info.bits_per_pixel / 8) + (row + var_info.yoffset) * fixed_info.line_length;

    // Determine RGB from color
    int red = (color & 0xFF0000) >> 16;
    int green = (color & 0xFF00) >> 8;
    int blue = color & 0xFF;

    if(main) // Write to main buffer
    {
        *(main_buffer + start_byte) = blue;
        *(main_buffer + start_byte + 1) = green;
        *(main_buffer + start_byte + 2) = red;
        *(main_buffer + start_byte + 3) = 0;
    }
    else // Write to back buffer
    {
        *(back_buffer + start_byte) = blue;
        *(back_buffer + start_byte + 1) = green;
        *(back_buffer + start_byte + 2) = red;
        *(back_buffer + start_byte + 3) = 0;
    }
}

void Framebuffer::Flush()
{
    memcpy(main_buffer, back_buffer, size); // Copy from back buffer to main buffer and update screen
    memset(back_buffer, 0, size); // Reset back buffer
}