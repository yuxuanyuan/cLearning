#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <string.h>

char * longestPalindrome(char * s) {
    int start, j, p, q, n;
    if (NULL == s) return NULL;
    int len = strlen(s);
    if(len <= 1) return s;
    char *str = (char *)malloc((len+1)*sizeof(char));
    for (int strLen = len; strLen >= 1; strLen--)
    {
        start = 0;
        while (start + strLen <= len)
        {
            for (j = 0; j < strLen; j++)
                str[j] = s[start + j];
            str[j] = '\0';
            n = 0;
            for (p = 0, q = strLen -1;p < strLen/2; p++, q--)
            {
                if (str[p] == str[q])
                    n++;
            }
            if (n == strLen/2)
                return str;
            else
                start++;
        }
    }
    return NULL;
}

int main()
{
    char *s = "abccdeabcdde";
    char *ret = longestPalindrome(s);
    printf("%s\n", ret);
    return 0;
}
