#define MAX_INT (int)0x7FFFFFFF
#define MIN_INT (int)0x80000000

int myAtoi(char * str){
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
                return INT_MAX;
        }else{
            if(-result<INT_MIN)
                return INT_MIN;
        }
        str++;
    }
    return (int)flag*result;
}
