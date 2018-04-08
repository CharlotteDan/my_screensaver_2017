/*
** EPITECH PROJECT, 2017
** -d
** File description:
** my_screensaver
*/

#include "../include/framebuffer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int ac, char **av)
{
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'd')
		{
			my_printf("%d%s", 1, ": two lignes");
			my_printf("%s\n", " with random pixel.");
			my_printf("%d%s", 2, ": chaos game, ");
			my_printf("%s\n","triangle whith random pixels.");
			my_printf("%d%s\n", 3, ": square with pixels animation");
		} else if (av[1][0] == '-' && av[1][1] == 'h') {
			my_printf("%s", "animation rendering in a ");
			my_printf("%s\n\n", "CSFML window.");
			my_printf("%s\n", "USAGE");
			my_printf("%s", "./my_screensaver ");
			my_printf("%s\n", "[OPTIONS] animation_id");
			my_printf("%s\n", " animation_id    ID of the animation");
			my_printf("%s", "to process (between 1 and 3)");
			my_printf("%s\n\n", "OPTIONS");
			my_printf("%s", "-d\t\t print the description");
			my_printf("%s\n", "of all the animations and quit.");
			my_printf("%s\n\n", "-h\t\t print the usage and quit.");
			my_printf("%s\n", "USER INTERACTIONS");
			my_printf("%s", "we can't use switch to the ");
			my_printf("%s\n\n", "previous animation");
		} else {
			screensaver1(av);
		}
	} else {
		my_printf("%s", "./my_screensaver: bad arguments:");
		my_printf("%d%s%d%s\n", 0,"given but", 1, "is required");
		my_printf("%s\n", "retry with -h");
		my_printf("%d\n", 84);
	}
	return (0);
}
