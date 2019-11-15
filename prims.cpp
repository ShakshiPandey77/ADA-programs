#include <bits/stdc++.h> 
using namespace std; 
int V;
int minKey(int key[], bool mstSet[]) 
{ 
	
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 


void printMST(int parent[], int **graph) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int **graph) 
{ 
	
	int parent[V]; 
	
	
	int key[V]; 
	

	bool mstSet[V]; 

	
	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 
	key[0] = 0; 
	parent[0] = -1; 
	for (int count = 0; count < V - 1; count++) 
	{ 
		int u = minKey(key, mstSet); 

		 
		mstSet[u] = true; 

		
		for (int v = 0; v < V; v++) 

		
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	
	printMST(parent, graph); 
} 
int main() 
{ 
	cout<<"enter the number of nodes: "<<endl;
	cin>>V;
	int **graph=new int*[V];
	for(int i=0;i<V;i++)
		graph[i]=new int[V];
	cout<<"\n enter the adjascency matrix: "<<endl;
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			cin>>graph[i][j];
			
	

	primMST(graph); 

	return 0; 
} 
/* output:
enter the no of nodes:5
enter adjacency matrix:
0 2 0 6 0 
2 0 3 0 5
0 3 0 0 7
6 0 0 0 0
0 5 7 0 0
edges   weight
0-1
21-2
30-3
61-4
*/
