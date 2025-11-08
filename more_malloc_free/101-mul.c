#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

/**
 * is_digit - checks if a string contains only digits
 * @s: string to check
 *
 * Return: 1 if only digits, 0 otherwise
 */
int is_digit(char *s)
{
    int i = 0;

    while (s[i])
    {
        if (s[i] < '0' || s[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

/**
 * _strlen - returns the length of a string
 * @s: string to measure
 *
 * Return: length of string
 */
int _strlen(char *s)
{
    int len = 0;

    while (s[len])
        len++;
    return (len);
}

/**
 * errors - handles errors for main
 */
void errors(void)
{
    printf("Error\n");
    exit(98);
}

/**
 * multiply - multiplies two positive numbers
 * @s1: first number
 * @s2: second number
 *
 * Return: pointer to result string
 */
char *multiply(char *s1, char *s2)
{
    int len1, len2, total_len, i, j, carry, n1, n2, sum;
    char *result;
    char *final_result;

    len1 = _strlen(s1);
    len2 = _strlen(s2);
    total_len = len1 + len2;
    result = malloc(total_len + 1);
    if (result == NULL)
        errors();

    /* Initialize result with zeros */
    for (i = 0; i < total_len; i++)
        result[i] = '0';
    result[total_len] = '\0';

    /* Multiply each digit and add to result */
    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        n1 = s1[i] - '0';

        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = s2[j] - '0';
            sum = (n1 * n2) + (result[i + j + 1] - '0') + carry;
            carry = sum / 10;
            result[i + j + 1] = (sum % 10) + '0';
        }
        if (carry > 0)
            result[i] += carry;
    }

    /* Remove leading zeros */
    i = 0;
    while (result[i] == '0' && result[i + 1] != '\0')
        i++;

    /* If all zeros, return "0" */
    if (result[i] == '0' && result[i + 1] == '\0')
    {
        final_result = malloc(2);
        final_result[0] = '0';
        final_result[1] = '\0';
        free(result);
        return (final_result);
    }

    /* Create new string without leading zeros */
    final_result = malloc(total_len - i + 1);
    if (final_result == NULL)
    {
        free(result);
        errors();
    }

    for (j = 0; j < total_len - i; j++)
        final_result[j] = result[i + j];
    final_result[total_len - i] = '\0';

    free(result);
    return (final_result);
}

/**
 * main - multiplies two positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
    char *result;

    if (argc != 3)
        errors();

    if (!is_digit(argv[1]) || !is_digit(argv[2]))
        errors();

    result = multiply(argv[1], argv[2]);
    printf("%s\n", result);
    free(result);

    return (0);
}
