/*
** EPITECH PROJECT, 2017** test
** File description:
** my_screensaver1
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/framebuffer.h"

framebuffer_t *framebuffer_create(unsigned int width, unsigned int height)
{
	framebuffer_t *fb;

	if ((fb = malloc(sizeof(framebuffer_t))) == NULL)
		return NULL;
	fb->width = width;
	fb->height = height;
	if ((fb->pixels = malloc(sizeof(sfUint8*) * width * height)) == NULL)
		return NULL;
	return (fb);
}

void my_put_pixel(framebuffer_t *framebuffer,
		  unsigned int  x, unsigned int y, sfColor color)
{
	framebuffer->pixels[(framebuffer->width * y + x) * 4] = color.r;
	framebuffer->pixels[(framebuffer->width * y + x) * 4 + 1] = color.g;
	framebuffer->pixels[(framebuffer->width * y + x) * 4 + 2] = color.b;
	framebuffer->pixels[(framebuffer->width * y + x) * 4 + 3] = color.a;
}

void draw_line(framebuffer_t *framebuffer, unsigned int y)
{
	y = 800;
	int p;
	sfColor color;

	for (int x = 0; x < 799; x++) {
		color.r = rand() %76;
		color.g = rand() %145;
		color.b = rand() %255;
		color.a = rand() %256;
		p = x / y + 78;
		my_put_pixel(framebuffer, x, p, color);
	}
	for (int x = 0; x < 799; x++) {
		color.r = rand();
		color.g = rand();
		color.b = rand();
		color.a = rand();
		p = x / y + 500;
		my_put_pixel(framebuffer, x, p, color);
	}
}

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
void framebuffer_destroy(framebuffer_t *framebuffer)
{
	free(framebuffer->pixels);
	free(framebuffer);
}

int screensaver1(char **av)
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	framebuffer_t *framebuffer = framebuffer_create(800, 600);
	sfTexture* texture = sfTexture_create(framebuffer->width, framebuffer->height);
	sfSprite* sprite = sfSprite_create();;
	sfEvent event;
	point a = {50, 100};
	point b = {750, 100};
	point c = {750, 500};
	point d = {50, 500};
	point t = {400, 100};
	point r = {50, 500};
	point g = {400, 100};
	point l = {50, 100};
	int y = 800;
	point random = {1, 1};

	window = sfRenderWindow_create(mode, "my_screensaver", sfResize | sfClose, NULL);
	if (!window)
		return 0;
	if (!framebuffer)
		return 0;
	if (!texture)
		return 0;

	sfSprite_setTexture(sprite, texture, sfFalse);
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		switch (av[1][0]) {
		case '1':
			draw_line(framebuffer, y);
			break;
		case '2':
			chaos_triangle(framebuffer, t, r, c, g,random);
			break;
		case '3':
			draw_rectangle(framebuffer, a,
				       b, c, d, l, random);
			break;
		}
		sfTexture_updateFromPixels(texture,
					   framebuffer->pixels,
					   framebuffer->width,
					   framebuffer->height, 0, 0);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	sfTexture_destroy(texture);
	sfSprite_destroy(sprite);
	framebuffer_destroy(framebuffer);
	sfRenderWindow_destroy(window);
	return EXIT_SUCCESS;
}
