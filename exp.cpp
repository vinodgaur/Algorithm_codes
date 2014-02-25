//Program:

#include<iostream.h>

#include<conio.h>
using namespace std;
int start_exp(int);
int l;
string v;

int main()
{  
    cin>>v;   //   v=(a+b)*c    ab
    l=v.length();
    start_exp(0);
    
    system("pause");

}//End program


// functions
int start_exp(int s)
{
    string st;
    int sp=0;
    string result="";
    
    for(int i=s;i<l;i++)
    {
           if(v[i]=="(")
           {
                        st=st+v[i];         
                        sp++;
           }
           else if(v[i]=="+" || v[i]=="-" || v[i]=="*" || v[i]=="/")
           {
                        st=st+v[i];         
                        sp++;             
           }
           else if(v[i]=="(")
           {
                        st[sp]="";
                        sp--;     
           }
           else
           {
                    result=result+v[i];        
           }
    }
    
    cout<<"result="<<result<<endl;    
}
