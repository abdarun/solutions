#include<bits/stdc++.h>

using namespace std;

bool check(char a[10][10],int *row,int *col)
{
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            if(a[i][j]=='x')
            {
                *row=i;
                *col=j;
                return false;
            }
        }
    }
    return true;
}

bool issafe(char a[10][10],char n,int row,int col)
{
    int i,j;
    //column checking
    for(i=0;i<9;i++)
    {
        if(a[row][i]==n) {
            return false;
        }
    }
    //row checking
    for(i=0;i<9;i++)
    {
        if(a[i][col]==n)
        {
            return false;
        }
    }
    return true;
}


bool sudoku(char a[10][10],int row,int col)
{
   int i;
   if(check(a,&row,&col))
   {
       return true;
   }

   for(i=1;i<=9;i++)
   {
       if(issafe(a,i+'0',row,col))
       {
           a[row][col]=i+'0';
           printf("change %c\n", a[row][col]);
           if(sudoku(a,row,col))
           {
               return true;
           }
           else
           {
                 a[row][col]='x';
           }
       }
   }
   return false;
}


int main()
{
    int i,j;
    char a[10][10];
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cin>>a[i][j];
        }
    }

    sudoku(a,0,0);

    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        {
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}
