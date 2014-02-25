//Program: To findout strongly connected component in graph

#include<stdio.h>

struct node 
{
	int info;
	struct arc *nextarc;
};

struct arc
{
	struct node *ndptr;
	struct arc *nextarc;
};

int top;

void visit(int i, struct node *array[], int time, int color[], int parent[], int d[], int f[], int stack[])
{
	color[i] = 1;
	d[i] = ++time;
	if(array[i]->nextarc == NULL)
	{
		color[i] = 2;
		f[i] = ++time;
		stack[++top] = i;
		return;
	}
	struct arc *temp = array[i]->nextarc;
	while(temp != NULL)
	{
		if(color[temp->ndptr->info-1] == 0)
		{
			parent[temp->ndptr->info-1] = i+1;
			visit(temp->ndptr->info-1, array, time, color, parent, d, f, stack);
		//	stack[++top] = temp->ndptr->info-1;
		}
		temp = temp->nextarc;
	}
	color[i] = 2;
	f[i] = ++time;
	stack[++top] = i;
}

void visit1(int i, struct node *array[], int time, int color[], int parent[], int d[], int f[])
{
	color[i] = 1;
	d[i] = ++time;
	if(array[i]->nextarc == NULL)
	{
		color[i] = 2;
		f[i] = ++time;
		return;
	}
	struct arc *temp = array[i]->nextarc;
	while(temp != NULL)
	{
		if(color[temp->ndptr->info-1] == 0)
		{
			parent[temp->ndptr->info-1] = i+1;
			visit1(temp->ndptr->info-1, array, time, color, parent, d, f);
		}
		temp = temp->nextarc;
	}
	color[i] = 2;
	f[i] = ++time;
}

void insert_edge(struct node *array[], int start, int end)
{
	start--;
	end--;
	struct arc *temp;
	temp = malloc(sizeof(struct arc));
	temp->ndptr = array[end];
	temp->nextarc = NULL;
	if(array[start]->nextarc == NULL)
	{
		array[start]->nextarc = temp;
		return;
	}
	struct arc *t = array[start]->nextarc;
	while(t->nextarc != NULL)
		t = t->nextarc;
	t->nextarc = temp;
}
int main()
{
	int n;
	scanf("%d", &n);
	struct node *array[n];
	struct node *arrayt[n];
	int i;
	int color[n];
	int connected[n];
	int parent[n];
	int d[n];
	int f[n];
	int time;
	top = -1;
	int stack[n];
	for(i = 0; i<n ; i++)
	{
		array[i] = malloc(sizeof(struct node));
		arrayt[i] = malloc(sizeof(struct node));
		array[i]->info = i+1;
		arrayt[i]->info = i+1;
		color[i] = 0;
// 0 = white
// 1 = gray
// 2 = black
		parent[i] = -1;
		connected[i] = -1;
		d[i] = -1;
		f[i] = -1;
	}
	int start, end;
	while(scanf("%d %d",&start, &end) != EOF)
	{
		insert_edge(array, start, end);
		insert_edge(arrayt, end, start);
	}

// print graph
	printf("Graph nodes and edges.\n");
	for(i = 0; i<n; i++)
	{
		printf("%d->",array[i]->info);
		struct arc *temp;
		temp = array[i]->nextarc;
		while(temp != NULL)
		{
			printf("%d->",temp->ndptr->info);
			temp = temp->nextarc;
		}
		printf("NULL\n");
	}
	while(top < n-1)
	{
		for(i = 0; i < n ; i++)
		{
			if(color[i] == 0)
			{
				visit(i, array, time, color, parent, d, f, stack);
			//	stack[++top] = i;
			}
		}
	}
	for(i = 0; i<n ; i++)
	{
		color[i] = 0;
		parent[i] = -1;
		connected[i] = -1;
		d[i] = -1;
		f[i] = -1;
	}
	int j = 0;
	while(top > -1)
	{
		i = stack[top--];
		if(color[i] == 0)
		{
			visit1(i, arrayt, time, color, parent, d, f);
			int k;
			connected[i] = j;
			for(k = 0 ; k<n ; k++)
			{
				if(connected[k] == -1 && parent[k] != -1)	
				{
					connected[k] = j;
					int temp = 0;
					while(temp <= top)
					{
						if(stack[temp] == k)
						{
							while(temp <= top)
							{
								stack[temp] = stack[++temp];
							}
							break;
						}
						temp++;						
					}
				}
			}
			j++;
		}

	}
	printf("\nConnected components are \n");
	for(i = 0 ; i<j ; i++)
	{
		printf(" { ");
		int k;
		for(k = 0 ; k<n ; k++)	
		{
			if(connected[k] == i)
				printf(" %d ",k+1);
		}
		printf(" } \n");
	}
}
