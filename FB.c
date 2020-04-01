#include <stdlib.h>
#include <stdio.h>

// Fibonacci sequence 
// A simple version if you don't consider the efficiency 
unsigned int FB(const unsigned int i)
{
	if (i<=1)
	{
		return i;
	}
	else{
		return FB(i-1)+FB(i-2);
	}
}

int main()
{
	unsigned int i;
	int abrt = 0;
	char decn;
	
	printf("================ The program starts ================\n");
	while (i)
	{
		if (abrt != -1)
		{
			printf("Please enter a number: ");
			scanf("%d", &i); 
			printf("FB(%d) = %d\n", i, FB(i));
		}
		else 
		{
			printf("================= The program ends =================\n");
			break;
		}
		getchar();
		printf("Would you like to try it again [y|n] ");
		scanf("%c", &decn);
		//printf("decn = %c\n", decn);

		if (decn == 'n')
		{
			printf("================= The program ends =================\n");
			break;
		}

		while (decn != 'y' && decn != 'n' && abrt != -2)
		{
			getchar();
			printf("Wrong selection! Please try 'y' or 'n' : ");
			scanf("%c", &decn); 
			//printf("Des = %c\n", decn);
			if (decn == 'n')
			{ 
				abrt = -1;
			}
			else if (decn == 'y')
			{
				abrt = -2;
			}
		}
		
	}

	return 0;
}
