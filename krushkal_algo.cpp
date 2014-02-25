//Program: Implementation of "Krushkal Algorithm"

#include<stdio.h>
#include<iostream>

using namespace std;
#define maxvalue 1000
int input_edge();
int display_g();
int sort_by_wt();
int combine_tree();
int display_path();
int up_rep(int);

struct list
{
    int a;
    int b;
    int w;
    struct list *next;
    int rep;       
}*p,*q,*s;

struct list *x[maxvalue]={};

/*
1 2 4
1 3 8
2 3 11
2 4 8
3 6 1
3 5 7
5 6 6
4 5 2
6 8 2
4 8 4
4 7 7
7 9 9
8 9 10
7 8 14
0
*/
int arr_rep[maxvalue];
int color[10];

int main()
{
  printf("Implementation of kruskal algorithm\n\n");
 
  printf("enter number of vertices....\n");
  int n;
  scanf("%d",&n);
  
  for(int i=1;i<=n;i++)
  {
       arr_rep[i]=i;    
  }
  
  printf("Enter edges.....\n");
  input_edge();
  display_g();
  
  sort_by_wt();
  display_g();
  
  combine_tree();
  display_path();
  system("pause");
}

// combine tree using krushkal algorithm
int combine_tree()
{
      p=s;
      int i=0;
      while(p!=NULL)
      {
           if(arr_rep[p->a] != arr_rep[p->b])
           {
                 x[i]=p; i++;                 
           }      
           
            for(int j=1;j<=9;j++)
            {
              color[j]=0;        
            }
                      
           if(arr_rep[p->a] < arr_rep[p->b])
           {
               //arr_rep[p->b] = arr_rep[p->a];
               up_rep(p->a);                 
           }
           else
           {
               //arr_rep[p->a] = arr_rep[p->b];
               up_rep(p->b);                 
           } 
           p=p->next;     
      }
      return 0;
}

int up_rep(int t)
{
    //printf("up called...%d\n",t);
     int i=0;
     
    
     while(x[i]!=NULL)
     {
           if(x[i]->a == t && color[x[i]->b]==0)
           {
               arr_rep[x[i]->b]=arr_rep[x[i]->a];
               color[x[i]->a]=1;
               //printf("from if   color of 3=%d\n",color[x[i]->a]);
               up_rep(x[i]->b);           
           }                 
           else if(x[i]->b == t && color[x[i]->a]==0)
           {
               arr_rep[x[i]->a]=arr_rep[x[i]->b];
               color[x[i]->b]=1;
              // printf("from else\n");
               up_rep(x[i]->a);           
           }   
           i++;
     }
     return 0;
}

int display_path()
{
   int i=0;
   while(x[i]!=NULL)
   {
         printf("%d %d\n",x[i]->a,x[i]->b);
         i++;   
   }    
}


// sort by weight
int sort_by_wt()
{
    p=s;
    q=p->next;
    while(q!=NULL)
    {
                  p=s;
         while(p!=q)
         {
              if((p->w) > (q->w))
              {
                      swap(p->a, q->a);
                      swap(p->b, q->b);
                      swap(p->w, q->w);
                      swap(p->rep, q->rep);
              }    
              p=p->next;          
         }       
         q=q->next;       
    }        
}

// input graph.......
int input_edge()
{
     int a,b,wt;
     p=NULL;
     while(scanf("%d",&a) && a!=0 && scanf("%d",&b) && scanf("%d",&wt))
     {
       //printf("adj=%d\n",adj);
       q=(struct list*)malloc(sizeof(struct list)); //  remember this step
       //q=(struct list*)malloc(sizeof(struct list)); //  remember this step
       q->a=a;
       q->b=b;
       //printf("if exe2.\n");
       q->w=wt;
       q->next=NULL;
       if(a<b)
              q->rep=a;
       else
              q->rep=b;
                                  
      if(p==NULL)
      {     
       p=s=q;
      }
      else
      {
           p->next=q;      
           p=p->next;    
      }
       
     }// while end
}

int display_g()
{
               p=s;
            while(p!=NULL)
            {
               printf("%d-%d( %d ) rep=%d\n",p->a,p->b,p->w,p->rep);
               p=p->next;                  
            }  
            printf("\n");      
}
