#include "main.h"

/**
 * main - Test _printf with integers
 *
 * Return: 0 on success
 */
int main(void)
{
        int num1 = 10;
        int num2 = 20;

        _printf("Numbers: [%d] [%i]\n", num1, num2);

        return (0);
}
