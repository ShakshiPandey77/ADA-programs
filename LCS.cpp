#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b);
void LCS(string X,string Y,int m,int n)
{
int L[m+1][n+1];
    for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
                {
                    if(i==0 || j==0)
                        L[i][j]=0;
                    else if(X[i-1]==Y[j-1])
                        L[i][j]=L[i-1][j-1]+1;
                    else
                        L[i][j]=max(L[i-1][j],L[i][j-1]);
                }
        }
int index=L[m][n];
char lcs[index+1];
lcs[index]='\0';
int i=m,j=n;
    while(i>0&&j>0)
        {
            if(X[i-1]==Y[j-1])
                {
                    lcs[index-1]=X[i-1];
                    i--;
                    j--;
                    index--;
                }
            else if(L[i-1][j]>L[i][j-1])
                i--;
            else
                j--;
        }
        cout<<"The LCS is "<<lcs<<endl;
        }
int max(int a,int b)
{
return (a>b?a:b);
}

int main()
{
string X,Y;
cout<<"enter the string 1:";
cin>>X;
cout<<"enter the string 2:";
cin>>Y;
int m=X.length();
int n=Y.length();
LCS(X,Y,m,n);
return 0;
}

