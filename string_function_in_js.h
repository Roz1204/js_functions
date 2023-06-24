#ifndef STRING
#define STRING
#include <stdlib.h>
#include <stdbool.h>

int size(char* str)
{
    int size = 0;
    while(*str != '\0')
    {
        ++size;
        ++str;
    }
    return size;
}

char **split(char *str) 
{
    char **res = (char **)malloc(sizeof(char*) * 1);
    res[0] = (char *)malloc(sizeof(char) * (size(str) + 1));
    int i = 0;
    while (str[i] != '\0')
    {
        res[0][i] = str[i];
        ++i;
    }
    res[0][i] = '\0';
    return res;
}

int includes(char* str1, char* str2)
{
    if (size(str2) > size(str1))
    {
        return 0;
    }

    for (int i = 0; str1[i] != '\0'; ++i)
    {
        if (str1[i] == str2[0])
        {
            int same = 1;
            for (int j = 1; str2[j] != '\0'; ++j)
            {
                if (str1[i + j] != str2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return 1;
        }
    }
    return 0;
}

int endsWith1(char *str1, char *str2, int index)
{
    int s1 = index - 1;
    if(s1 < 0)
    {
        return 0;
    }
    for(int i = size(str2) - 1; i >= 0; --i)
    {
        if (str2[i] != str1[s1--])
        {
            return 0;
        }
    }
    return 1;
}

int endsWith(char* str1, char* str2)
{
    int s1 = size(str1) - 1;
    for(int i = size(str2) - 1; i >= 0; --i)
    {
        if (str2[i] != str1[s1--])
        {
            return 0;
        }
    }
    return 1;
}

int indexOf(char* str1, char* str2)
{
    if (size(str2) > size(str1))
    {
        return -1;
    }

    for (int i = 0; str1[i] != '\0'; ++i)
    {
        if (str1[i] == str2[0])
        {
            int same = 1;
            for (int j = 1; str2[j] != '\0'; ++j)
            {
                if (str1[i + j] != str2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}

char* replace(char* str, char* str1, char* str2)
{
    int s = size(str);
    int s1 = size(str1);
    int s2 = size(str2);

    int index = indexOf(str, str1);
    int newLength = index == -1 ? s : (s + s2 - s1);
    char* res = (char*)malloc(sizeof(char) * (newLength + 1));
    if(res == NULL)
    {
        return NULL;
    }

    int k = 0;
    for(int i = 0; i < s; ++i)
    {
        if( i == index)
        {
            for(int j = 0; str2[j] != '\0'; ++j)
            {
                res[k++] = str2[j];
            }
            i += s1 - 1;
        }
        else
        {
            res[k++] = str[i];
        }
    }
    res[k] = '\0';
    return res;
}

char* replaceAll(char* str, char* str1, char* str2)
{
    char *ans = replace(str, str1, str2); 
    int index = indexOf(str, str1);

    while (index != -1)
    {
        ans = replace(ans, str1, str2); 
        index = indexOf(ans, str1);
    }
    return ans;
}

char* concat(char* str1, char* str, char* str2)
{
    int s1 = size(str1);
    int s = size(str);
    int s2 = size(str2);
    char* res = (char*)malloc(sizeof(char) * (s1 + s + s2 + 1));
    if(res == NULL)
    {
        return NULL;
    }
    int i = 0;
    for(int j = 0; j < s1; ++j)
    {
        res[i++] = str1[j];
    }
    for(int k = 0; k < s; ++k)
    {
        res[i++] = str[k];
    }
    for(int j = 0; j < s2; ++j)
    {
        res[i++] = str2[j];
    }
    res[i] = '\0';
    return res;
}

char* trimEnd(char* str)
{
    int s = size(str);
    int count = 0;
    int k = s - 1;
    while(str[k] == ' ')
    {
        ++count;
        --k;
    }
    if(count != 0)
    {
        char* tmp = (char*)malloc(sizeof(char) * (s - count + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        int j = 0;
        for(int i = 0; i < s - count; ++i)
        {
            tmp[j++] = str[i];
        }
        tmp[j] = '\0';
        return tmp;
    }
    return str;
}

char* trimStart(char* str)
{
    int s = size(str);
    int count = 0;
    int k = 0;
    while(str[k] == ' ')
    {
        ++count;
        ++k;
    }
    if(count != 0)
    {
        char* tmp = (char*)malloc(sizeof(char) * (s - count + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        int j = 0;
        for(int i = count; i < s; ++i)
        {
            tmp[j++] = str[i];
        }
        tmp[j] = '\0';
        return tmp;
    }
    return str;
}

char* trim(char* str)
{
    char* res = (char*)malloc(sizeof(char) * (size(trimEnd(str)) + 1));
    if(res == NULL)
    {
        return NULL;
    }
    res = trimEnd(str);
    char* tmp = (char*)malloc(sizeof(char) * (size(trimStart(res)) + 1));
    if(tmp == NULL)
    {
        return NULL;
    }
    tmp = trimStart(res);
    return tmp;
}

bool startsWith(char* str1, char* str2)
{
    int s1 = size(str1);
    int s2 = size(str2);
    if(s2 < s1)
    {
        for(int i = 0; i < s2; ++i)
        {
            if(str1[i] != str2[i])
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

char* slice1(char* str, int start, int end)
{
    int s = size(str);
    if(start >= 0 && start < s && end >= 0 && end <= s && start <= end)
    {
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * (end - start + 2));
        if(tmp == NULL)
        {
            return NULL;
        }
        for(int j = start; j < end; ++i, ++j)
        {
            tmp[i] = str[j];
        }
        tmp[i] = '\0';
        return tmp;
    }

    char* tmp = (char*)malloc(sizeof(char));
    if(tmp == NULL)
    {
        return NULL;
    }
    tmp[0] = '\0';
    return tmp;
}

char* slice(char* str, int start)
{
    int s = size(str);
    if(start >= 0 && start < s)
    {
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * (s - start + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        for(int j = start; j < s; ++i, ++j)
        {
            tmp[i] = str[j];
        }
        tmp[i] = '\0';
        return tmp;
    }
    else if(start < 0 && 0 - start < s)
    {
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * (s + start + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        for(int j = s + start; j < s; ++i, ++j)
        {
            tmp[i] = str[j];
        }
        tmp[i] = '\0';
        return tmp;
    }
    char* tmp = (char*)malloc(sizeof(char));
    if(tmp == NULL)
    {
        return NULL;
    }
    tmp[0] = '\0';
    return tmp;
}

char* padStart1(char* str, int count)
{
    char chr = ' ';
    int s = size(str);
    if(s <= count)
    {
        char* tmp = (char*)malloc(sizeof(char) * (count + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        tmp[count] = '\0';

        for(int i = count - 1, j = s - 1; j >= 0; --i, --j)
        {
            tmp[i] = str[j];
        }
        for(int i = 0; i < count - s; ++i)
        {
            tmp[i] = chr;
        }
        return tmp;
    }
    return str;
}

char* padStart(char* str, int count, char chr)
{
    int s = size(str);
    if(s <= count)
    {
        char* tmp = (char*)malloc(sizeof(char) * (count + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        tmp[count] = '\0';

        for(int i = count - 1, j = s - 1; j >= 0; --i, --j)
        {
            tmp[i] = str[j];
        }
        for(int i = 0; i < count - s; ++i)
        {
            tmp[i] = chr;
        }
        return tmp;
    }
    return str;
}

char* padEnd1(char* str, int new_size)
{
    char chr = ' ';
    int s = size(str);
    if(new_size > s)
    {
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * new_size);
        if(tmp == NULL)
        {
            return NULL;
        }
        for(; i < s; ++i)
        {
            tmp[i] = str[i];
        }
        int count = new_size - s;
        while(count != 0)
        {
            tmp[i++] = chr;
            --count;
        }
        return tmp;
    }
    return str;
}

char* padEnd(char* str, int new_size, char chr)
{
    int s = size(str);
    if(new_size > s)
    {
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * new_size);
        if(tmp == NULL)
        {
            return NULL;
        }
        for(; i < s; ++i)
        {
            tmp[i] = str[i];
        }
        int count = new_size - s;
        while(count != 0)
        {
            tmp[i++] = chr;
            --count;
        }
        return tmp;
    }
    return str;
}

char* toUpperCase(char* str)
{
    int s = size(str);
    int i = 0;
    char* tmp = (char*)malloc(sizeof(char) * (s + 1));
    if(tmp == NULL)
    {
        return NULL;
    }
    for(; i < s; ++i)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            tmp[i] = str[i] - 32;
        }
        else
        {
            tmp[i] = str[i];
        }
    }
    tmp[i] = '\0';
    return tmp;
}

char* toLowerCase(char*str)
{
    int s = size(str);
    int i = 0;
    char* tmp = (char*)malloc(sizeof(char) * (s + 1));  
    if(tmp == NULL)
    {
        return NULL;
    }  
    for(; i < s; ++i)
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            tmp[i] = str[i] + 32;
        }
        else
        {
            tmp[i] = str[i];
        }
    }
    tmp[i] = '\0';
    return tmp;
}

char* substring1(char* str, int start, int end)
{
    int s = size(str);
    if(start >= 0 && start < s && end >= 0 && end <= s && start <= end)
    {
        int i = start;
        char* tmp = (char*)malloc(sizeof(char) * s - start + 1);
        if(tmp == NULL)
        {
            return NULL;
        }
        for(int j = 0; i < end; ++i, ++j)
        {
            tmp[j] = str[i];
        }
        tmp[i] = '\0';
        return tmp;
    }
    return NULL;
}

char* substring(char* str, int start)
{
    int s = size(str);
    if(start >= 0 && start < s)
    {
        int i = start;
        char* tmp = (char*)malloc(sizeof(char) * (s - start + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        for(int j = 0; i < s; ++i, ++j)
        {
            tmp[j] = str[i];
        }
        tmp[i] = '\0';
        return tmp;
    }
    return NULL;
}

char* repeat(char* str, int count)
{
    if(count >= 0)
    {
        int s = size(str);
        int i = 0;
        char* tmp = (char*)malloc(sizeof(char) * (s * count + 1));
        if(tmp == NULL)
        {
            return NULL;
        }
        while(count != 0)
        {
            for(int j = 0; j < s ; ++i, ++j)
            {
                tmp[i] = str[j];
            }
            --count;
        }
        tmp[i] = '\0';
        return tmp;
    }
    return NULL;
}

int lastIndexOf(char* str1, char* str2)
{
    if (size(str2) > size(str1))
    {
        return -1;
    }

    for (int i = size(str1) - 1; i >= 0; --i)
    {
        if (str1[i] == str2[0])
        {
            int same = 1;
            for (int j = 1; str2[j] != '\0'; ++j)
            {
                if (str1[i + j] != str2[j])
                {
                    same = 0;
                    break;
                }
            }
            if (same)
                return i;
        }
    }
    return -1;
}

char charAt(char* str, int index)
{
    int s = size(str);
    if(index >= 0 && index < s)
    {
        return *(str + index);
    }
    return 0;
}

char at(char* str, int index)
{
    int s = size(str);
    if(index >= 0 && index < s)
    {
        return *(str + index);
    }
    else if(0 - index >= 0 && 0 - index < s)
    {
        return *(str + s + index);
    }
    return 0;
}

#endif