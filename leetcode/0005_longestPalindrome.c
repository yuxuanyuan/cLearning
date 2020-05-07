#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <string.h>

char * longestPalindrome(char * s) {
    int start, j, q, n;
    if (NULL == s) return NULL;
    int len = strlen(s);
    if(len <= 1) return s;
    char *str = (char *)malloc((len+1)*sizeof(char));
    for (int strLen = len; strLen >= 1; strLen--)
    {
        start = 0;
        while (start + strLen <= len)
        {
            n = 0;
            for (j = 0, q = strLen -1; j < strLen/2; j++, q--)
            {
                str[j] = s[start + j];
                str[q] = s[start + q];
                if (str[j] == str[q])
                    n++;
                else
                    break;
            }

            if (n == strLen/2)
            {
                if (strLen%2 != 0) str[j] = s[start + j];
                str[strLen] = '\0';
                return str;
            }
                
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
