/* #include<iostream>
using namespace std;
int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
 for(i = 1; i <= n; i++)
 if(a[v][i] && !visited[i])
 q[++r] = i;
 if(f <= r) {
 visited[q[f]] = 1;
 bfs(q[f++]);
 }
}

int main() {
 int v;
 cout<<"\n Enter the number of vertices:";
 scanf("%d", &n);
 
 for(i=1; i <= n; i++) {
 q[i] = 0;
 visited[i] = 0;
 }
 
 cout<<"\n Enter graph data in matrix form:\n";
 for(i=1; i<=n; i++) {
 for(j=1;j<=n;j++) {
 cin>>a[i][j];
 }
 }
 
 cout<<"\n Enter the starting vertex:";
cin>>v;
 bfs(v);
 cout<<"\n The node which are reachable are:\n";
 
 for(i=1; i <= n; i++) {
 if(visited[i])
 cout<<i;
 else {
 cout<<"\n Bfs is not possible. Not all nodes are reachable";
 break;
 }
 }
return 0;
} */

//
#include <iostream>
#include <queue> // STL queue
using namespace std;

queue<int> q;

void BFS(int k,int **adj,bool *visited, int n){
  cout<<k+1<<" ";
  visited[k] = true;
  q.push(k);
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    for(int i =0; i<n;i++){
      if(adj[curr][i] && !visited[i]){
        q.push(i);
        visited[i] = true;
        cout<<i+1<<" ";
      }
    }
  }
}

int main(){
  int **adj, k, n;
  bool *visited;
  cout<<"Enter the number of nodes :\n";
  cin>>n;
  visited = new bool[n];
  adj = new int*[n];
  for(int i=0; i<n;i++)
    adj[i] = new int[n];
  cout<<"Enter Adjacency Matrix :\n";
  for(int i=0; i<n;i++)
    for(int j =0; j<n;j++)
      cin>>adj[i][j];
  cout<<"Enter the source vertex :";
  cin>>k;
  BFS(k-1,adj,visited,n);
  return 0;
}



