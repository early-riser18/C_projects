#include <stdio.h>
#include "libft.h"

static int power(int base, int exponent)
{
    
    int result = 1;
    if (exponent == 0)
    {
        return 1;
    }
    while (exponent > 0)
    {
        result *= base;
        exponent--;
    }
    return result;
}

int ft_atoi(const char *string)
{

    char sign = 1;
    char parsedStr[12] = "";

    // Process first character
    if (*string == '-')
    {
        sign *= -1;
        string++;
    }
   
    size_t it = 0;
    while (*string && it < sizeof(parsedStr))
    {
        if (ft_isdigit(*string))
        {
            parsedStr[it] = *string;
        }
        else
        {
            break;
        }

        it++, string++;
    }
    
    char *pStrPtr = parsedStr;

    size_t strLen = ft_strlen(parsedStr);
    int sum = 0;
    for (size_t i = 0; i < strLen; i++, pStrPtr++)
    {
        sum += (*pStrPtr - 48) * power(10, strLen - 1 - i); //
    }
    return sum * sign;
}

// int test(int num, const char *string, char *expected)
// {
//     printf("\n-----OUTCOME TEST %d------\n Output |%d|\t Expected result: |%s|\n",
//            num,
//            ft_atoi(string),
//            &expected[0]);
//     return 0;
// }

// int main()
// {
//     test(1, "1234", "1234");
//     test(2, "12H4", "12");
//     test(3, "-1234", "-1234");
//     test(4, "-12-34", "-12");
//     test(5, "922334", "922334");
//     test(6, "022334", "22334");

//     return 0;
// }