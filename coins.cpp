#include<bits/stdc++.h> 
using namespace std;
int mincoins(int coins[],int m,int V)
{
int table[V+1];
table[0]=0;
for(int i=1;i<=V;i++)
{
table[i]=INT_MAX;
}
for(int i=1;i<=V;i++)
{
for(int j=0;j<m;j++)
if(coins[j]<=i)
{
int res=table[i-coins[j]];
if(res!=INT_MAX && res+1<table[i])
table[i]=res+1;
}
}
return table[V];
}

int main()
{
int n;
cout<<"enter the number of coins in array";
cin>>n;
int c[n];
cout<<"enter the coins";
for(int i=0;i<n;i++)
{
cin>>c[i];
}
int V;
cout<<"enter the sum";
cin>>V;
cout<<mincoins(c,n,V)<<endl;
return 0;
}
