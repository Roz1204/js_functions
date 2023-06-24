#include <stdio.h>
#include "string_function_in_js.h"

int main()
{
    //
    char *str = "hello world hello world";
    char** res = split(str);
    printf("%s\n", res[0]);

    // char* str = "Hello World";
    // char* res = slice1(str, 5, 8);
    // printf("%s", res);

    // char* str1 = "hello world hello world";
    // char* str2 = "hello";
    // printf("%s\n", replaceAll(str1, str2, "barev"));

    // char* str1 = "hello world hello world";
    // char* str2 = "hello";
    // printf("%s\n", replace(str1, str2, "barev"));

    // char* str1 = "herldllo world";
    // char* str2 = "rld";
    // printf("%d\n", lastIndexOf(str1, str2));

    // char* str1 = "herldllo world";
    // char* str2 = "rld";
    // printf("%d\n", indexOf(str1, str2));

    // char* str1 = "herldllo world";
    // char* str2 = "rld";
    // printf("%d\n", includes(str1, str2));

    // char* str1 = "hello world";
    // char* str2 = "world";
    // printf("%d\n", endsWith1(str1, str2, 4));

    // char* str1 = "hello world";
    // char* str2 = "world";
    // printf("%d\n", endsWith(str2, str1));

    // char* str1 = "hello world";
    // char* str2 = "world";
    // printf("%d", endsWith(str1, str2));

    // char* str1 = "hello";
    // char* str2 = "world";
    // printf("%s", concat(str1, ", ", str2));

    // char* str = "     hello   ";
    // char* res = trim(str);
    // printf("%s \n", res);
    // printf("%d\n", size(res));

    // char* str = "hello   ";
    // char* res = trimEnd(str);
    // printf("%s \n", res);
    // printf("%d \n", size(res));

    // char* str = "   hello";
    // char* res = trimStart(str);
    // printf("%s \n", res);

    // char* str = "Hello World";
    // char* res = slice(str, -4);
    // printf("%s", res);

    // char* str1= "hello world";
    // char* str2 = "llo";
    // printf("%d\n", startsWith(str1, str2));

    // char* str = "Hello";
    // char* res = padStart1(str, 15);
    // printf("%s", res);

    // char* str = "Hello";
    // char* res = padStart(str, 15, '?');
    // printf("%s", res);

    // char* str = "Hello";
    // char* res = padEnd1(str, 8);
    // printf("%s", res);

    // char* str = "Hello";
    // char* res = toLowerCase(str);
    // printf("%s", res);

    // char* str = "Hello";
    // char* res = toUpperCase(str);
    // printf("%s", res);

    // char* str = "hello";
    // char* res = substring1(str, 1, 3);
    // printf("%s", res);

    // char* str = "hello";
    // char* res = substring(str, 5);
    // printf("%s", res);

    // char* str = "hello";
    // printf("%s", repeat(str, -3));

    // char* str = "hell   o";
    // printf("%d\n", charCodeAt(str, 3));

    // char* str = "hello";
    // printf("%c\n", charAt(str, 13));

    // char* str = "hello";
    // printf("%c\n", at(str, -3));
    return 0;
}