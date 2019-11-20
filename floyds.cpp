#include <iostream>
#include <cmath>
using namespace std;

void floyds(int **D,int n){	
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				D[i][j] = min(D[i][j],D[i][k]+D[k][j]);
				
	cout<<"\nAll Pairs Shortest Paths:\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cout<<D[i][j]<<"\t";
		cout<<endl;
	}//end of loop
}//end of method

int main(){
	int **D, n;
	cout<<"Enter the number of nodes : ";
	cin>>n;
	
	D = new int*[n];
	for(int i =0; i<n; i++)
		D[i] = new int[n];
	
	cout<<"Enter cost matrix :\n";	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>D[i][j];
			
	floyds(D,n);
	return 0;
}//end of main

/*
OUTPUT:
Enter the number of nodes : 5
Enter cost matrix :
0 2 999 1 8
6 0 3 2 999
999 999 0 4 999
999 999 2 0 3
3 999 999 999 0
All Pairs Shortest Paths:
0	2	3	1	4	
6	0	3	2	5	
10	12	0	4	7	
6	8	2	0	3	
3	5	6	4	0	
*/
