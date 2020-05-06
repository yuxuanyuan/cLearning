#include<stdio.h>
#include<sys/malloc.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int *nums, int numsSize, int target, int *resultSize)
{
    int i, j;
    int *tmp = (int *)malloc(2*sizeof(int));
    if (NULL == tmp) return NULL;
    for (i = 0; i < numsSize; i++)
	{
        for (j = i + 1; j < numsSize; j ++)
        {
            if(nums[i] + nums[j] == target)
            {
                tmp[0] = i;
                tmp[1] = j;
                *resultSize = 2;
            }
        }
    }
    return tmp;
}

int main()
{
	int numsSize = 4, target = 9;
	int nums[] = {2, 7, 11, 15};
	int resultSize;
	int *tmp = twoSum(nums, numsSize, target, &resultSize);
	if (resultSize != 2)
	{
		printf("no such two elements!\n");
	}
	else
	{
		printf("[%d, %d]\n", tmp[0], tmp[1]);
	}
}
