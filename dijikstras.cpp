#include <iostream>
#include <climits>

using namespace std;

void djikstra(int **cost, int n, int src){
	int dist[n], vis[n], min, u, count;
	
	for(int j = 1; j<n; j++) dist[j] = cost[src][j];
	
	for(int j = 0; j<n; j++) vis[j] = 0;
	
	dist[src] = 0;
	vis[src] = 1;
	count = 1;
	
	while( count != n){
		min = INT_MAX;
		for(int j = 0; j<n; j++){
			if(dist[j]<min && !vis[j]){
				min = dist[j];
				u = j;
			}//end of if
		}//end of loop
		vis[u] = 1;
		count++;
		for(int j = 0; j<n; j++)
			if(min + cost[u][j] < dist[j] && !vis[j])
				dist[j] = min+cost[u][j];
	}//end of loop
	
	cout<<"Shortest Distance :\n";
	for(int j=0; j<n ; j++)
		if(j!=src)
			cout<<src<<" - "<<j<<" -> "<<dist[j]<<endl;
}//end of method

int main(){
	int **cost, n, src;
	cout<<"Enter the number of nodes :";
	cin>>n;
	cost = new int*[n];
	for(int i =0; i<n; i++) cost[i] = new int[n];
	cout<<"Enter the cost matrix :\n";
	for(int i =0; i<n;i++)
		for(int j =0; j<n; j++)
			cin>>cost[i][j];
	cout<<"Enter souce vertex :";
	cin>>src;
	djikstra(cost, n, src);
	return 0;
}//end of main

/*
OUTPUT:
Enter the number of nodes :5
Enter the cost matrix :
0 3 1 999 999
3 0 7 5 1
1 7 0 2 999
999 5 2 0 7
999 1 999 7 0
Enter souce vertex :0
Shortest Distance :
0 - 1 -> 3
0 - 2 -> 1
0 - 3 -> 3
0 - 4 -> 4
*/
/* output:

Enter the no. of nodes :9

Enter the adjacency matrix :
999 4  999 999 999 999 999 8 999
  4 999 8 999 999 999 999 11 999
  999 8 999 7 999 4 999 999 2
  999 999 7 999 9 14 999 999 999
  999 999 999 9 999 10 999 999 999
  999 999 4 14 10 999 2 999 999
  999 999 999 999 999 2 999 1 6
  8 11 999 999 999 999 1  999 7
  999 999 2 999 999 999 6 7 999
source vertex: 0 
Vertex 		 Distance from Source
0 		 0
1 		 4
2 		 12
3 		 19
4 		 21
5 		 11
6 		 9
7 		 8
8 		 14
*/
