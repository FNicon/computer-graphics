#pragma once

#include <linux/fb.h>

class Framebuffer
{
    public:
        // Properties

        int fd; // Framebuffer file descriptor
        int size; // Total size of framebuffer in bytes

        struct fb_fix_screeninfo fixed_info; // Fixed screen information
        struct fb_var_screeninfo var_info; // Variable screen information
        
        char* main_buffer; // Buffer to be mapped to framebuffer device (/dev/fb0)
        char* back_buffer; // Secondary buffer, for double buffering

        const bool BUF_MAIN = true; // Main buffer flag for target_buffer
        const bool BUF_BACK = false; // Secondary buffer flag for target_buffer

        // Methods

        Framebuffer(); // Framebuffer constructor
        ~Framebuffer(); // Framebuffer destructor

        // Write pixels to main buffer or back buffer with RGB color, use hex for color
        void write(int row, int column, int color, bool main);

        void flush(); // Flush secondary buffer to main buffer
};