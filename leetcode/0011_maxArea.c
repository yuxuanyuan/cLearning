#define max(a,b) (a>=b?a:b)
#define min(a,b) (a<=b?a:b)

int maxArea(int* height, int heightSize){
    int i, j, h, s, c;
    int *new = (int *)malloc((heightSize -1) *sizeof(int));
    if (heightSize == 2)
    {
        h = min(height[0], height[1]);
        return h;
    }
    
    for (i = 0; i < heightSize; i++)
    {
        for (j =  i + 1, c = i; j < heightSize; j++, c++)
        {
            h = min(height[i], height[j]);
            s = j - i;
            new[c] = max(h*s, new[c]);
        }
    }
    
    c = 0; 
    
    for (i = 0; i < heightSize -1; i++)
        c = max(c, new[i]);
    free(new);
    return c;
}
