#include<iostream>
using namespace std;
const int n=5;
int adj[n][n]={0};
int visited[n]={0};
void dfs(int v){
cout<<v;
visited[v]=1;
for(int i=1;i<n;i++)
{
if(adj[v][i]==1 && visited[i]==0)
{
dfs(i);
}
}
}
int main()
{
cout<<"enter the adjacency matrix";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
{
cin>>adj[i][j];
}
}

for(int i=0;i<n;i++)
{
if(visited[i]==0)
{
dfs(i);
cout<<"\n";
}
}
return 0;
}

