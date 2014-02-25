//Program: To count tototal number of path from source to //destination

//Input: user will input adjacent elements to create list //corresponding to each vertices.

// Algorithm: Depth first search to find all shortest path

#include<stdio.h>

#define maxvalue 1000 //max. possible nodes of a tree
int create_list(int); // function to create list by taking adjacent element as an input from user
int display_list(int);
int display(int);     // color of node
int node[maxvalue];   // array for current node
int pre[maxvalue];    // array to maintain precedor of a node
int color[maxvalue];  // white=1,gray=2,black=3

struct list
{
	int data;
	struct list *next;
}*p,*q;

int main()
{
	int tnode;
	int i;
	printf("Enter number of vertices\n");
	scanf("%d",&tnode);

    printf("\n\n To create list enter adjacent elements\n\n");

    for(i=0;i<tnode;i++)
	{		
        color[i]=1;
        pre[i]="NULL"; 
		create_list(i);	
	}
	display_list(tnode);

	printf("\n\nProgram to count path between two node\n\n");
	for(i=0;i<tnode;i++)
	{
       if(color[i]==1)
        {
             dfs(i);
             color[i]=3;
        }                    
    }
	display(tnode);
	system("pause");
	return 0;

}// End program


// functions
int dfs(int i)
{
    
    p=node[i]; // address of node 1
    q=node[p->data]; // address of it's adjacent node
    printf("In dfs i = %d and p=%d\n",i,p->data);
    if(q!="NULL" && color[i]==1 )
    {
          color[i]=2;
          printf(" color %d= %d\n",i,color[i]);      
          pre[p->data]=i;   
          printf("p=%d\n",p->data);          
          dfs(p->data);
          color[q->data]=3;
          dfs(pre[q->data]);                   
    }   
}

// to display color of nodes
int display(int tnode)
{
    int j=0;
     for(j=0;j<tnode;j++)
     {
          printf("color[ %d ]= %d\n",j,color[j]);
     }    
}

// function to create list
int create_list(int index)
{
    printf("Enter adjacent nodes of %d and enter -1 to end the list\n",index);
	int n=0;
	struct list *temp;
	p="NULL";
	node[index]="NULL"; // if there is no adjacent then insert NULL
	//temp=(struct list)malloc(sizeof(struct list));
	//p=temp;
	//node[index]=p;
	while(1)
	{
        //printf("j=%d and n=%d\n",j++,n);        
		//printf("scan\n");
        scanf("%d",&n);
		if((n+1)==0)
		{
              if(p!="NULL")      
                   p->next="NULL";
              break;         
        }
        
		//if(j==9) break;
		
		temp=(struct list*)malloc(sizeof(struct list));
		
        if(p=="NULL")
		{
            //printf("n=%d\n",n);
			temp->data=n;
			p=temp;
			p->next="NULL";
			node[index]=p;
		}
		else
		{
			temp->data=n;
			
			p->next=temp;
			p=temp;
		}
		
	}
	return 0;
}

int display_list(int tnode)
{
    
	struct list *temp;
	temp=(struct list*)malloc(sizeof(struct list));
	int i;
    
    for(i=0;i<tnode;i++)
	{
		printf("\n\n%d : ",i);
		if(node[i]==0)
		{
		           continue;
        }
        temp=node[i];
    	while(temp!="NULL") 
		{
			printf("-> %d",temp->data);
			temp=temp->next;
		}
		
	}
	return 0;

}



