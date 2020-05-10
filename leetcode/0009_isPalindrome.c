bool isPalindrome(int x){
    int i = 0, j = 0, a, p;
    if (x < 0)
        return false;
    a = x;
    while (a != 0)
    {
        a = a / 10;
        i++;
    }
    char *arr=(char *)malloc(i*sizeof(char));
    i = 0;
    a = x;
    while(a != 0)
    {
        p = a % 10;
        a = a / 10;
        arr[i] = p + '0';
        i++;
    }

    for (j = 0, p = i; j < i/2; j++, p--)
    {
        if (arr[j] != arr[p-1]){
            return false;
        }
    }
    return true;
}
