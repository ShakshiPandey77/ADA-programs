#include<iostream>
#define r 3
#define c 5
using namespace std;
void dfs(int ro,int col);
int isSafe(int ro,int col);
int M[r][c]={0};
int visited[r][c]={0};
int islands()
{
int count=0;
for(int i=0;i<r;++i)
{
for(int j=0;j<c;++j)
{
if(M[i][j]&&!visited[i][j]){
dfs(i,j);
++count;
}
}
}
return count;
}
void dfs(int ro,int col)
{
static int rownum[]={-1,-1,-1,0,0,1,1,1};
static int colnum[]={-1,0,1,-1,1,-1,0,1};
visited[ro][col]=1;
for(int k=0;k<8;++k)
{
if(isSafe(ro+rownum[k],col+colnum[k]))
{
dfs(ro+rownum[k],col+colnum[k]);
}
}
}
int isSafe(int ro,int col)
{
	return ((ro>=0)&&(ro<r)&&(col>=0)&&(col<c)&&(M[ro][col]&& !visited[ro][col]));
}

int main()
{

cout<<"enter the matrix\n";
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
cin>>M[i][j];
}
}
cout<<islands()<<"\n";
return 0;
}


