#include "printf.h"
/**
 * print_int - this is a function that prints an integer
 * @num: integer to print
 * Return: len of the printed integer
 */

int print_int(int num){
    char reversed_str[15] = "", number_str[15] = "";
    char dummy_str[2] = "D";
    int is_negative = 0, i, len = 0;

    if (num < 0){
        is_negative = 1;
        num = -num;
        
    }
    
    while ((num / 10) > 0)
        {
            dummy_str[0] = (num % 10) + '0';
            strcat(reversed_str, dummy_str);
            num /= 10;
        }
    
    if (num == INT_MIN){
        num = INT_MAX;

        while ((num / 10) > 0)
            {
                dummy_str[0] = (num % 10) + '0';
                if (strlen(reversed_str) == 0){
                    dummy_str[0] = (num % 10) + 1 + '0';
                }
                strcat(reversed_str, dummy_str);
                num /= 10;
            }
    }

    
    dummy_str[0] = num + '0';
    strcat(reversed_str, dummy_str);
    if(is_negative){
        len += _printf("-");
    }
    
    for (i = strlen(reversed_str) - 1; i >= 0; i--)
        {
            if (reversed_str[i] != '\0'){
                number_str[strlen(reversed_str) - i - 1] = reversed_str[i];
            }
            else{
                break;
            }
        }
    len += _printf(number_str);
    return len;
}



/**
 * print_unsigned - this is a function that prints an integer
 * @num: integer to print
 * Return: len of the printed integer
 */

int print_unsigned(unsigned int num){
    char reversed_str[15] = "", number_str[15] = "";
    char dummy_str[2] = "D";
    int i, len = 0;


    while ((num / 10) > 0)
        {

            dummy_str[0] = (num % 10) + '0';
            strcat(reversed_str, dummy_str);
            num /= 10;
        }


    dummy_str[0] = num + '0';
    strcat(reversed_str, dummy_str);
    
    for (i = strlen(reversed_str) - 1; i >= 0; i--)
        {
            if (reversed_str[i] != '\0'){
                number_str[strlen(reversed_str) - i - 1] = reversed_str[i];
            }
            else{
                break;
            }
        }
    len += _printf(number_str);
    
    return len;
}
