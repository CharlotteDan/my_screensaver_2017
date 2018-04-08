/*
** EPITECH PROJECT, 2017** test
** File description:
** my_screensaver3
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/framebuffer.h"

void draw_rectangle(framebuffer_t *framebuffer, point a, point b,
		    point c, point d, point l, point  random)
{
	int n = rand() %8;
	sfColor color;
	color.r = rand();
	color.g = rand();
	color.b = rand();
	color.a = rand();

	for  (int i = 0; i != 10; i++) {
		if (n <= 2) {
			random.x = (a.x + l.x) / 2;
			random.y = (a.y + l.y) / 2,
			my_put_pixel(framebuffer, random.x, random.y, color);
			l.x = random.x;
			l.y = random.y;
		} else if (n == 3 ||  n == 4) {
			random.x = (b.x + l.x) / 2,
			random.y = (b.y + l.y) / 2;
			my_put_pixel(framebuffer, random.x, random.y, color);
			l.x = random.x;
			l.y = random.y;
		} else if (n == 5 || n == 6) {
			random.x = (c.x + l.x) / 2;
			random.y = (c.y + l.y) / 2;
			my_put_pixel(framebuffer, random.x, random.y, color);
			l.x = random.x;
			l.y = random.y;
		} else {
				random.x = (d.x + l.x) / 2;
				random.y = (d.y + l.y) / 2;
				my_put_pixel(framebuffer, random.x, random.y, color);
				l.x = random.x;
				l.y = random.y;
			}
		n = rand() %8;
	}
}
