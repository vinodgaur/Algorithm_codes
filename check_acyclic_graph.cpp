//program: To check wheather the input graph is acyclic or not

#include<iostream>
#include<conio.h>

#define max_vertices 1000 // maximum possible vertices
int dfs(int);             // defined depth first search function
int display(int);         // display graph is acyclic or not
int scan_tree(int);       // take tree values as an input from user


int up[max_vertices];                   // queue for pushing same level tree nodes
int visited[max_vertices];              // 1=white,2=gray,3=black
int graph[max_vertices][max_vertices];  // defined graph with maximum vertices
//int graph[6][6]={{0,1,0,0,0,0},{0,0,1,1,0,0},{0,0,0,0,0,0},{0,0,0,0,1,1},{0,0,0,0,0,1},{0,0,1,0,0,0}};
int n;        // total number of nodes
int org=0;
int flag=0;
 
int main()
{
    printf("program to check Acyclic or not a directed graph\n\n");   
    printf("Enter number of vertices\n");
    scanf("%d",&n);
    scan_tree(n); // function to take tree values as an input from user

    int i,j;
    for(j=0;j<n;j++)
    {
      if(flag==0)
      {
          for(i=0;i<n;i++)
              visited[i]=0;        
         dfs(j);
      }
    }

    if(flag==0)
       display(0);

} // End program


// functions
int dfs(int i)
{ 
    visited[i]=1;
    int j=0;
    if(graph[i][i]==1)  // check cycle on yourself
    {
       flag=1;
       display(1); 
    }
                      
    for(j=0;j<n;j++)
    {
          // printf("i=%d   j=%d\n",i,j);
          if(graph[i][j]==1 && visited[j]!=2)
          {
               if(visited[j]==1)
               {
                    flag=1;
                    display(1);
                    break;
               }
               up[j]=i;
               dfs(j);
               visited[j]=2;
               dfs(up[j]);
          } 
          //system("pause");        
    }
    
}


int scan_tree(int n)
{
   printf("Enter tree elements from left to right in matrix\n");
    for(int i=0;i<n;i++)
    {
         for(int j=0;j<n;j++)
         {
                 scanf("%d",&graph[i][j]);
            //printf("%d  ",graph[i][j]);
          //      cout<<"color of node="<<i<<"is "<<color[i]<<"  ud="<<endl;    
         }printf("\n");            
    } printf("\n\n");             
}

int display(int a)
{
    
    if(a==1)
           printf("cyclic\n");
    else
           printf("A cyclic\n"); 

    system("pause");
}
