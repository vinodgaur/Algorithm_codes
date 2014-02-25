




//Program: Sort an array using insertion sort method

#include<stdio.h>

void swapArr(int n[], int a, int b); // to swap two values into an array
void display(int [], int );          // to display an array

int main()
{
    printf("insertion sort program..........\n");

	int n[5]={12,2,5,0,1}; // input array
	int i,j;
	int sz=sizeof(n)/sizeof(int);
	printf("s=%d\n",sz);
	for(i=0;i<sz;i++)
	{
		for(j=i+1;j>0;j--)
		{
			if(n[j]>n[j-1])
				swapArr(n,j,j-1);
		}	
		printf("s=%d\n",sz);
	}
	//printf("s=%d",s);
	printf("s = %d\n", sz);
	display(n,5);
	
	return 0;
}//End program

//functions
void swapArr(int n[],int a,int b)
{
	printf("swaped called..........\n");
	int temp;
	temp=n[a];
	n[a]=n[b];
	n[b]=temp;
}

void display(int n[],int s)
{
		printf("Display called.........and s=%d\n",s);
	int i;
	for(i=0;i<s;i++)
		printf("\n%d",n[i]);
}
