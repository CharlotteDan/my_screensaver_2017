/*
** EPITECH PROJECT, 2017** test
** File description:
** my_screensaver2
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/framebuffer.h"

void chaos_triangle(framebuffer_t *framebuffer, point t, point r,
		    point c, point g, point random)
{
	int n = rand() %7;
	sfColor color;

	color.r = rand();
	color.g = rand();
	color.b = rand();
	color.a = rand();
	for  (int i = 0; i != 10; ++i) {
		if (n <= 2) {
			random.x = (t.x + g.x) / 2;
			random.y = (t.y + g.y) / 2;
			my_put_pixel(framebuffer, random.x, random.y, color);
			g.x = random.x;
			g.y = random.y;
		} else if (n == 3 ||  n == 4) {
			random.x = (r.x + g.x) / 2;
			random.y = (r.y + g.y) / 2;
			my_put_pixel(framebuffer, random.x, random.y, color);
			g.x = random.x;
			g.y = random.y;
		} else {
			random.x = (c.x + g.x) / 2;
			random.y = (c.y + g.y) / 2;
			my_put_pixel(framebuffer, random.x, random.y, color);
			g.x = random.x;
			g.y = random.y;
		}
		     n = rand() %7;
	}
}
