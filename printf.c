#include "printf.h"

/**
 * _printf - this is a function that format string
 * @str: string to format
 * @...: list of arguments
 */


int _printf(char *str, ...)
{
    int int_value;
    char* str_value;
    unsigned int unsigned_value;
    int total_strlen = 0;
    long unsigned int i = 0;
    va_list list;
    va_start(list, str);

    if (str == NULL)
        return (0);

    while(i < strlen(str) && str[i] != '\0')
    {
        if (str[i] == '%')
        {
            ++i;
            if (str[i] == '%'){
                total_strlen += write(1, &str[i], 1);
                i++;
                continue;
            }
            else{
                switch(str[i]){

                    case 'i':
                    case 'd':
                        int_value = va_arg(list, int);
                        total_strlen += print_int(int_value);
                        if (sizeof(int_value) != sizeof(int))
                            {
                                return (0);
                            }
                        i++;
                        break;
                    
                    case 'u':
                        unsigned_value = va_arg(list, unsigned int);
                        total_strlen += print_unsigned(unsigned_value);
                        i++;
                        break;
                    
                    case 'c':
                        int_value = va_arg(list, int);
                        total_strlen += write(1, &int_value, 1);
                        i++;
                        break;

                    case 's':
                        str_value = va_arg(list, char*);
                        total_strlen += write(1, str_value, strlen(str_value));
                        i++;
                        break;

                    default:
                        total_strlen += write(1, "%", 1);
                        total_strlen += write(1, &str[i], 1);
                        i++;
                        break;
                }
                continue;
            }
        }
        total_strlen += write(1, &str[i], 1);
        i++;
    }

    va_end(list);
    return (total_strlen);
}
