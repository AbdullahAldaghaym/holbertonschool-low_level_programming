#include "main.h"
#include <stdlib.h>
#include <stdio.h>

int is_digit(char *s)
{
    if (!s || !*s) return (0);
    while (*s) if (*s < '0' || *s++ > '9') return (0);
    return (1);
}

int _strlen(char *s)
{
    int len = 0;
    while (s[len]) len++;
    return (len);
}

char *multiply(char *s1, char *s2)
{
    int l1 = _strlen(s1), l2 = _strlen(s2), total = l1 + l2;
    char *res = malloc(total + 1), *final;
    int i, j, carry, n1, n2, sum;

    if (!res) return (NULL);
    for (i = 0; i < total; i++) res[i] = '0';
    res[total] = '\0';

    for (i = l1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = s1[i] - '0';
        for (j = l2 - 1; j >= 0; j--)
        {
            n2 = s2[j] - '0';
            sum = n1 * n2 + (res[i + j + 1] - '0') + carry;
            carry = sum / 10;
            res[i + j + 1] = (sum % 10) + '0';
        }
        if (carry) res[i] += carry;
    }

    i = 0;
    while (i < total - 1 && res[i] == '0') i++;

    final = malloc(total - i + 1);
    if (!final) { free(res); return (NULL); }
    for (j = 0; j < total - i; j++) final[j] = res[i + j];
    final[total - i] = '\0';
    free(res);
    return (final);
}

int main(int argc, char *argv[])
{
    char *res;

    if (argc != 3 || !is_digit(argv[1]) || !is_digit(argv[2]))
    {
        printf("Error\n");
        return (98);
    }

    if (argv[1][0] == '0' || argv[2][0] == '0')
    {
        printf("0\n");
        return (0);
    }

    res = multiply(argv[1], argv[2]);
    if (!res)
    {
        printf("Error\n");
        return (98);
    }

    printf("%s\n", res);
    free(res);
    return (0);
}
