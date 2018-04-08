/*
** EPITECH PROJECT, 2017
** printf
** File description:
** lib
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
	return (0);
}

int my_put_nbr(int nb)
{
	int i = 1;
	int n;

	n = nb;
	if (n < 0) {
		my_putchar('-');
		my_put_nbr(nb * -1);
		return (0);
	}
	while (n > 9){
		n = n / 10;
		i = i * 10;
	}
	while (i >= 1){
		my_putchar(((nb / i) % 10) + '0');
		i = i / 10;
	}
	return (0);
}

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i = i + 1;
	}
	return (i);
}

int my_putnbr_base(long int nb, char *base)
{
	if (nb < 0) {
		nb = nb * -1;
		my_putchar('-');
	}
	if (nb >= my_strlen(base))
		my_putnbr_base(nb / my_strlen(base), base);
	my_putchar(base[nb % my_strlen(base)]);
	return (0);
}
