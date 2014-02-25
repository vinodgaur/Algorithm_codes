//Program: All path shortest Algorithm implementation
// To show all shortest path


#include<stdio.h>

//defined global variables
#define max 200 // defined max value for matrix
int w[max][max]; // created maximum possible matrix
int l2[max][max],l3[max][max],l4[max][max]; // 3 more matrix
int n;  // Total number of vertices
int l[max][max];


int main()
{
	printf("program to show all shortest path....\n\n");
	printf("Enter number of vertices.....\n");
    scanf("%d",&n);

    int i,j,m;
    printf("Now enter values in matrix from left to right..\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&w[i][j]);
		}
	}

    m=2; l=w;
	l2[n][n]=extend_shortest_paths();

    m=3;  l=l2;
    l3[n][n]=extend_shortest_paths();

    m=4;  l=l3;
    l4[n][n]=extend_shortest_paths();
	
    // display l4 matrix
        for(i=1;i<=n;i++)
        {
                for(j=1;j<=n;j++)
                {
                        printf("%d   ",l4[i][j]);
                }
                printf("\n");
        }
        printf("\n");
}
// End program

// functions
int extend_shortest_paths(int m)
{
    int lt[n][n];
	int i,j,k;

    for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			lt[i][j]=222;
			for(k=1;k<=n;k++)
			{
				if( (l[i][k]+w[k][j]) < lt[i][j] )
					lt[i][j]=l[i][k]+w[k][j];
				
				printf("%d\n",l[i][j]);

			}
		}
	}	
	return lt[n][n];
}
