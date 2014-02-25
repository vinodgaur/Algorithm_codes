//Program: Implemantation of Merge sorting

#include<stdio.h>
int sorted_arr[8];
int n[8]={9,8,7,5,12,15,14,11,};
int s=sizeof(n)/4;
int main()
{
	printf("merge sort program.........\n");
//	int n[4]={9,8,7,5};
//		printf("%d",sizeof(n));
	//int s=sizeof(n)/4;
	divide(n,0,s-1);
	display(sorted_arr,s);
	return 0;
}

int  divide(int n[],int low, int high)
{
	//printf("divide called........");
	int mid=0;
	mid=(low+high)/2;
//		printf("length=%d",2*mid);
	if(low<high)
	{
		divide(n,low,mid);
		divide(n,mid+1,high);
		sort(n,low,mid,high);
	}
	
} 

int sort(int n[],int low,int mid,int high)
{
	int l=low;
	int r=mid+1;
	int i=0;
	//int limit=high-low;
	//int l_limit=mid;
	//int r_limit=high;
	
	for(i=low;i<=high;i++)
		printf("%d.........low=%d  mid=%d  high=%d\n",n[i],low,mid,high);	

	//int flag=0; // means sorted is used
//	if(flag==0)
//	{
		for(i=low;i<=high;i++)
		{
			if(l<=mid && r >high)
				sorted_arr[i]=n[l++];
			else if(r<=high && l>mid)
				sorted_arr[i]=n[r++];
			else if(n[l]>n[r])
				sorted_arr[i]=n[r++];
			else
				sorted_arr[i]=n[l++];
	
			printf("sorted_arr[%d]=%d\n",i,sorted_arr[i]);
		}
		for(i=low;i<=high;i++)
			n[i]=sorted_arr[i];
		
//	}
	display(sorted_arr,0,s);
}

display(int n[],int low,int high)
{
	int j=low;
	printf("\n\n");                       
	while(j<=high)
		printf("%d",n[j++]);
}
