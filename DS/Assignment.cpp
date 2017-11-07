#include<iostream>
#include<string.h>
using namespace std;

struct TERM
{
    int coeff;
    int x,y,z;
    TERM *next;
    TERM *sub;
};

int i=0;

TERM* input(char arr[])
{
    int len=strlen(arr);
    TERM *start=new TERM;
    start->next=NULL;
    start->sub=NULL;
    while(i<len)
    {
        char temp=arr[i];
        cout << temp << " " << i << endl ;
        if(temp>= 48 && temp <= 57)
        {
            start->coeff=temp-48;
            i++;
        }
        else
        {
            switch(temp)
            {
                case 'x':   start->x=arr[i+2]-48;
                            i+=3;
                            break;
                case 'y':   start->y=arr[i+2]-48;
                            i+=3;
                            break;
                case 'z':   start->z=arr[i+2]-48;
                            i+=3 ;
                            if(arr[i]!='+'&&arr[i]!='(')
                            {
                                return start;
                            }
                            break;
                case '(':   i++;
                            start->sub=input(arr);
                            break;
                case '+':   i++;
                            start->next=input(arr);
                            break;
                case ')':   i++;
                            return start;
                            break;
            }
        }
    }
    return start;
}

void display(TERM* start)
{
    if(start==NULL)
    {
        return ;
    }
    cout<<start->coeff<<"x^"<<start->x<<"y^"<<start->y<<"z^"<<start->z;
    if(start->sub!=NULL)
    {
        cout<<"(";
        display(start->sub);
        cout<<")";
    }
    if(start->next!=NULL)
    {
        cout<<"+";
        display(start->next);
    }
}

int main()
{
    char *s=new char[1000];
    cout<<"Enter the expression:\n";
    cin>>s;
    TERM *start=input(s);
    display(start);
    return 0;
}
