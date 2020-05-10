#define INT_MAX 2147483647
#define INT_MIN -2147483648

int strToInt(const char* str){
    long long result=0; 
    int flag=1;
    if (str==NULL)
        return 0;
    while(isspace(*str)){
        ++str;
    }
    if(*str=='-'){
        flag=-1;
        str++;
    }else if(*str=='+')
        str++;
    while(*str<='9' && *str>='0'){
        result=result*10+*str-'0';
        if(flag==1){ 
            if(result>INT_MAX)
                return 0;
        }else{ 
            if(-result<INT_MIN)
                return 0;
        }
        str++;
    }
    return (int)flag*result;
}

int reverse(int x){
    int a = x;
    int i = 0, p, q = 12, s;
    
    if(a <= INT_MIN || a >= INT_MAX)
        return 0;   
    char *arr=(char *)malloc(q*sizeof(char));
    if (a < 0)
    {
        arr[i] = '-';
        i++;
        a = -1 * a;
    }
    while(a != 0)
    {
        p = a % 10;
        a = a / 10;
        arr[i] = p + '0';
        i++;
    }
    arr[i] = '\0';
    s = strToInt(arr);
    free(arr);
    return s; 
}
