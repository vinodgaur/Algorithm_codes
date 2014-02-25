//Program: To reverse a link list

#include<stdio.h>
struct list
    {
           int data;
           struct list *next;
    }*start,*r_start;

struct list *reverse(struct list*);
int main()
{
    
           
    struct list *ptr,*temp;
    int n=5,i=0;
    ptr=NULL;
    //printf("in starting = %u",&temp);
    while(i++<n)
    {
                temp=malloc(sizeof(struct list));
                //printf("in loop = %u\n",&temp);
                scanf("%d",&temp->data);
                temp->next=NULL;
                   if(ptr==NULL)
                   {       
                         ptr=temp;    
                         start=ptr;
                   }
                   else
                   {
                         ptr->next=temp;
                         ptr=temp;
                   }
                   
                }// end of while
    
    r_start=reverse(start);
    
    
    i=0;
    temp=r_start;
    //printf("in end = %u",&temp);
    while(i++<n)
    {
                printf("%d\t",temp->data);
                temp=temp->next;
                }// end of while
    system("pause");
    return 0;
    } // end of main


struct list *reverse(struct list *p)
{
    struct list *p1,*p2,*p3;
    p1=p;
    p2=p1->next;
    p3=p2->next;
    
    p1->next=NULL;
    p2->next=p1;
    while(p3!=NULL)
    {
                   printf("loop working");
               p1=p2;
               p2=p3;
               p3=p3->next;
               
               p2->next=p1;
               //p3->next=p3;    
    }
    //r_start=p2;
    return (p2);    
}
