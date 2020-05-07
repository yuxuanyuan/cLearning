#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int newArr[nums1Size+nums2Size];
    int i, j, n;
    for (i = 0; i < nums1Size; i++)
    {
        newArr[i] = nums1[i];
    }
    for (j = 0; j < nums2Size; j++)
    {
        newArr[i+j] = nums2[j];
    }

    for (i = 0; i < nums1Size+nums2Size; i++)
    {
        for (j = i+1; j < nums1Size+nums2Size; j++)
        {
            if (newArr[j]<newArr[i])
            {
                n = newArr[j];
                newArr[j] = newArr[i];
                newArr[i] = n;
            }

        }
    }

    i = nums1Size+nums2Size;
    n = i % 2;
    if (n != 0)
    {
        return (double)newArr[(i+1)/2-1];
    }
    else
    {
        return (double)((newArr[(i-1)/2]+newArr[(i+1)/2])/2.0);
    }

}

int main()
{
    int nums1[] = {1,2,3};
    int nums2[] = {2,3,4};
    double ret = findMedianSortedArrays(nums1, 3, nums2, 3 );
    printf("%lf\n", ret);
}
