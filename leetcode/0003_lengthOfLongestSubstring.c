#include <stdio.h>
#include <stdlib.h>
#include <sys/malloc.h>
#include <string.h>
#include <stdbool.h>

int lengthOfLongestSubstring(char * s) {
    char ch;
    char tmp;
    int start, j, n, cnt, sum = 0;
    int len = strlen(s);
    char str[len+1];
    if (len <= 1)
        return len;
    for (int strLen = len; strLen >= 2; strLen--)
    {
        start = 0;
        while (start + strLen <= len)
        {
            for (j = 0; j < strLen; j++)
                str[j] = s[start + j];
            str[j] = '\0';
            n = 0;
            cnt = 0;
            while (n < strLen)
            {
                tmp = str[n];
                for (int i = 0; i <strLen; i++)
                {
                    if(str[i] == tmp) cnt++;
                }
                sum += cnt;
                cnt = 0;
                n++;
            }
            if (sum == strLen)
                return strLen;
            else
            {
                sum = 0;
                start++;
            }
        }
    }
    return 1;
}

int main()
{
    char s[] = "abcdefgaabbcceeddffggssabcderg";
    int ret = lengthOfLongestSubstring(s);
    printf("%d\n", ret);

