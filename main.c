#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define RESET "\033[0m"

#define TEST(func, input, format) printf("Original %s(" format "): %d, ft_%s(" format "): %d %s\n", #func, input, func(input), #func, input, ft_##func(input), func(input) == ft_##func(input) ? GREEN "✓" RESET : RED "✗" RESET)

int main() {
    // Test ft_isalpha
    TEST(isalpha, 'a', "'%c'");
    TEST(isalpha, '1', "'%c'");

    // Test ft_isdigit
    TEST(isdigit, '1', "'%c'");
    TEST(isdigit, 'a', "'%c'");

    // Test ft_isalnum
    TEST(isalnum, '1', "'%c'");
    TEST(isalnum, 'a', "'%c'");
    TEST(isalnum, '#', "'%c'");

    // Test ft_isascii
    TEST(isascii, 127, "%d");
    TEST(isascii, 128, "%d");

    // Test ft_isprint
    TEST(isprint, 32, "%d");
    TEST(isprint, 31, "%d");

    // Test ft_strlen
    char *str = "Hello, world!";
    printf("Original strlen(\"%s\"): %zu, ft_strlen(\"%s\"): %zu %s\n", str, strlen(str), str, ft_strlen(str), strlen(str) == ft_strlen(str) ? GREEN "✓" RESET : RED "✗" RESET);

    // Test ft_toupper
    TEST(toupper, 'a', "'%c'");

    // Test ft_tolower
    TEST(tolower, 'A', "'%c'");

    // Test ft_memcpy
    char src[50] = "Hello, world!";
    char dest[50];
    char dest2[50];
    memcpy(dest, src, strlen(src) + 1);
    ft_memcpy(dest2, src, strlen(src) + 1);
    printf("Original memcpy(dest, src, strlen(src)): %s, ft_memcpy(dest2, src, strlen(src)): %s %s\n", dest, dest2, strcmp(dest, dest2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);

    // Test ft_memset
    memset(dest, 'x', 5);
    ft_memset(dest2, 'x', 5);
    printf("Original memset(dest, 'x', 5): %s, ft_memset(dest2, 'x', 5): %s %s\n", dest, dest2, strcmp(dest, dest2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);

    // Test ft_bzero
    bzero(dest, 5);
    ft_bzero(dest2, 5);
    printf("Original bzero(dest, 5): %s, ft_bzero(dest2, 5): %s %s\n", dest, dest2, strcmp(dest, dest2) == 0 ? GREEN "✓" RESET : RED "✗" RESET);

    return 0;
}