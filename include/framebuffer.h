/*
** EPITECH PROJECT, 2017
** include
** File description:
** frame buffer
*/

#ifndef FRAMEBUFFER_H_
#define FRAMEBUFFER_H_

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/System/Export.h>

struct framebuffer {
	unsigned int width;
	unsigned int height;
	sfUint8 *pixels;
};
typedef struct framebuffer framebuffer_t;

struct point {
	int x;
	int y;
};
typedef struct point point;

int my_printf(char *str, ...);
void my_putchar(char c);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_putnbr_base(long int nb, char *base);
int my_strlen(char const *str);
framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
void my_put_pixel(framebuffer_t *framebuffer,
		  unsigned int x, unsigned int y, sfColor color);
void framebuffer_destroy(framebuffer_t *framebuffer);
int screensaver1(char  **av);
void draw_rectangle(framebuffer_t *framebuffer, point a, point b,
		    point c, point d, point l, point random);
void chaos_triangle(framebuffer_t *framebuffer, point t, point r,
		     point c, point g, point random);
#endif
