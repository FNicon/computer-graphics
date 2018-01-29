#include "framebuffer.h"

#include <iostream>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>

using namespace std;

void Framebuffer::init()
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

    // Todo : malloc for double buffering!
}

void Framebuffer::cleanup()
{
    munmap((void*) &fd, size); // Unmap memory
    close(fd); // Close framebuffer device
}

void Framebuffer::set(int row, int col, int red, int green, int blue, int alpha)
{
    // Count starting byte
    int start_byte = (col + var_info.xoffset) * (var_info.bits_per_pixel / 8) + (row + var_info.yoffset) * fixed_info.line_length;

    *(main_buffer + start_byte) = blue;
    *(main_buffer + start_byte + 1) = green;
    *(main_buffer + start_byte + 2) = red;
    *(main_buffer + start_byte + 3) = alpha;
}

void Framebuffer::write(int row, int col, int red, int green, int blue, int alpha)
{
    // Todo : double buffering!
}