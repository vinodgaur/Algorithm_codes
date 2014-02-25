//Program: Implementation of "Minimum spanning tree"

#include<stdio.h>
#include<iostream>
#define maxvalue 1000
int scan_adj(int);
int display_list(int);
int mst_prim(int);
int display_edge(int);

struct list *g[maxvalue];
int w[maxvalue];
int parent[maxvalue];

struct list
{
       int data;
       int w;
       struct list *next;       
}*p,*q;
int main()
{
    int n,i;
    
    // code to take number of vertices
    printf("Enter number of vertceis\n");
    scanf("%d",&n); 
      
    // code to make adjacent list and display 
    printf("\nInstruction:\n\nfirst enter adjacent node and give one space and then enter wieght of edge \nand then do sam for next nodes and if adajcent finish \nthen enter 0 and Press Enter Key\n\n",i); 
    for(i=1;i<=n;i++)
    {
        scan_adj(i);
        //printf("adj complete\n");                
    }
    display_list(n);
    
    //code for spanning tree
    mst_prim(n);
    display_edge(n);
    
    system("pause");
    return 0;
}

int scan_adj(int i)
{
    int a;
    int wt;
    p=q=NULL;
    
    printf("Enter adjacent element of %d\n",i);
    while(1)
    {
            //printf("while\n");     
            scanf("%d",&a);
                                   
                  
                  if(p==NULL) // this is the way to ccheck pointer is null
                  {
                         if(a==0)
                         {
                                  g[i]=NULL;
                                  break;            
                         }
                         else
                         { 
                                  scanf("%d",&wt);
                                  q=(struct list*)malloc(sizeof(struct list));
                                  q->data=a;
                                  q->w=wt;
                                  q->next=NULL; 
                                  p=q;        
                                  g[i]=p;
                         }           
                  }
                  else
                  {
                      if(a==0)
                      {
                           break;
                      }
                      else
                      {
                           scanf("%d",&wt);
                           q=(struct list*)malloc(sizeof(struct list));
                           q->data=a;
                           q->w=wt;
                           q->next=NULL; 
                           p->next=q;
                           p=q;
                      }    
                  }
             
    }
    return 0;
}

int display_list(int n)
{
    int i;
    printf("\n\n");
    for(i=1;i<=n;i++)
    {
        printf("%d : ",i);
        p=g[i];    
        while(p!=NULL)
        {
               printf("-> %d (%d) ",p->data,p->w);
               p=p->next;              
        }
        printf("\n\n");
    }
}



int empty_queue(int);
int extract_min(int);
int queue[3][maxvalue];
int edge[maxvalue];
int u;

int mst_prim(int n)
{
    int i;
    
    //int m;
    //m=n+1;
    
    for(i=0;i<n;i++)
    {
        queue[0][i]=i+1;             
        queue[1][i]=100;
        queue[2][i]=1;
        parent[i]=NULL;              
    }    
    queue[1][0]=0;   // make weight of root node is 0 and first node is always root....:)
    //printf("preprocessing is done\n");
    int m;
    int j=0;
    while(empty_queue(n)!=1)
    {
          extract_min(n);
          //printf("    node extracted is %d\n",u);
          queue[2][u-1]=0;
          //printf("parent of %d=%d\n\n",u,parent[u]);
          if(parent[u]!=NULL)
          {
                 edge[j++]=parent[u]*10+u;                   
          }
          
          p=g[u];                
          while(p!=NULL)
          {
               //printf("Enter in while p=%d\n",p->data);         
               m=(p->data)-1;
               if(queue[2][m]==1 && p->w <queue[1][m])
               {
                       parent[p->data]=u;
                       queue[1][m]=p->w;   
               }
               //printf("weight of %d=%d\n",p->data,queue[1][m]);
               p=p->next;              
          }                     
    }
    //printf("mst end\n");
}

int empty_queue(int n)
{
    int i;
    int e=1;
   
    for(i=0;i<n;i++)
    {    
          
           if(queue[2][i]==1)
           {
               e=0;        
           }
    }
    return e;
}

int extract_min(int n)
{
    int i;
    int min_wt=100;
   
    for(i=0;i<n;i++)
    {    
          //printf("absence of %d in queue= %d\n\n",queue[0][i],queue[2][i]);
           if(queue[1][i]<min_wt && queue[2][i]==1)
           {
               //printf("inside if \n");
                min_wt=queue[1][i];
                u=queue[0][i];          
           }
    }
    return 0;
}


int display_edge(int n)
{
    printf("\n\nShortest path edges are \n\n");
    for(int i=0;i<(n-1);i++)
        printf("%d\n",edge[i]);    
}

