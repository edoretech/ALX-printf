#include "printf.h"
/**
 * print_bin - this is a function that prints an integer
 * @num: integer to print
 * Return: len of the printed integer
 */

char *print_bin(int num){
    char *binary_str = malloc(sizeof(char) * 33);
    int x;

    for(x = 31; x>= 0; x--)
    {
        if (((num >> x) & 1))
        {
            strcat(binary_str, "1");
        }
        else if (binary_str[0] == '1'){
            strcat(binary_str, "0");
        }
    }
    return (binary_str);    
}