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


        // Methods

        void init(); // Initialize framebuffer
        void cleanup(); // Cleanup framebuffer

        void set(int row, int col, int red, int green, int blue, int alpha); // Set pixels (static, no animation)
        void write(int row, int col, int red, int green, int blue, int alpha); // Write pixels (dynamic, for animation)
};