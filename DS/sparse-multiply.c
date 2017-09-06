#include<stdio.h>

struct sparse
{
    int row,col,val;
};

void input(struct sparse a[],int r,int c,int nz)
{
    int i;
    a[0].row=r;
    a[0].col=c;
    a[0].val=nz;
    for(i=1;i<=nz;i++)
    {
        scanf("%d",&a[i].row);
        scanf("%d",&a[i].col);
        scanf("%d",&a[i].val);
    }
    printf("\n\n");
}

void transpose(struct sparse a[],struct sparse b[])
{
    int i,m,n,nz,c[a[0].val],t[a[0].val];
    m=a[0].row;
    n=a[0].col;
    nz=a[0].val;

    b[0].row=m;
    b[0].col=n;
    b[0].val=nz;

    for(i=0;i<nz;i++)
    {
        c[i]=0;
    }

    for(i=1;i<=nz;i++)
    {
        c[a[i].col]++;
    }

    t[0]=1;

    for(i=1;i<nz;i++)
    {
        t[i]=t[i-1]+c[i-1];
    }

    for(i=1;i<=nz;i++)
    {
        b[t[a[i].col]].row=a[i].col;
        b[t[a[i].col]].col=a[i].row;
        b[t[a[i].col]].val=a[i].val;
        t[a[i].col]++;
    }

}

void display(struct sparse a[],int k)
{
    int i;
    for(i=0;i<k;i++)
    {
        printf("%d ",a[i].row);
        printf("%d ",a[i].col);
        printf("%d\n",a[i].val);
    }
    printf("\n\n");

}

int multiply(struct sparse a[],struct sparse b[],struct sparse c[])
{
    int count=0,k1=1,k2=1,k3=1,sum=0,g=0,flag=0,i,j;
    struct sparse x;
    c[0].row=a[0].row;
    c[0].col=b[0].col;
    c[0].val=0;

    while(k1<a[0].val+2)
    {
        if(a[k1].col==b[k2].row)
        {
            c[k3].row=a[k1].row;
            c[k3].col=b[k2].col;
            c[k3].val=a[k1].val*b[k2].val;
            k3++;
            count++;
        }
        k2++;
        if(k2==b[0].val+1)
        {
            k2=1;
            k1++;
        }
    }

    for(i=1;i<count;i++)
    {
        for(j=i+1;j<=count;j++)
        {
            if(c[i].row==c[j].row&&c[i].col==c[j].col)
            {
                sum=c[i].val+c[j].val;
                c[j].val=0;
                c[i].val=sum;
            }
        }
    }

    for(i=1;i<=count;i++)
    {
        for(j=1;j<=count-1;j++)
        {
            if(c[j].val==0)
            {
                x=c[j];
                c[j]=c[j+1];
                c[j+1]=x;
                flag=1;
            }

        }
        if(flag==1)
        {
            g++;
            flag=0;
        }
    }
    printf("%d\n\n",g);
    count=count-g;
    return count;

}




int main()
{
    int i,j,k,R,C,NZ,k1=1;
   struct sparse a[10],b[10],c[10],d[10];

   printf("Enter 1st Sparse Matrix\n");
   scanf("%d%d%d",&R,&C,&NZ);
   input(a,R,C,NZ);
   printf("Enter 2nd Sparse Matrix\n");
   scanf("%d%d%d",&R,&C,&NZ);
   input(b,R,C,NZ);
   if(a[0].col==b[0].row)
   {
       /*transpose(b,c);
       printf("Transpose of 2nd Matrix\n");
       display(c,NZ+1);*/
       k=multiply(a,b,d);
       d[0].val=k;
       printf("Product of 2 Matrix In Sparse Form\n");
       display(d,k+1);
       printf("Product of 2 Matrix In Normal Form\n");
       for(i=0;i<d[0].row;i++)
       {
           for(j=0;j<d[0].col;j++)
           {
               if(i==d[k1].row&&j==d[k1].col)
               {
                   printf("%d ",d[k1].val);
                   k1++;
               }
               else
               {
                   printf("%d ",0);
               }
           }
           printf("\n");
       }
   }
   else
   {
       printf("Multiplication Not Possible\n");
   }

   return 0;
}
