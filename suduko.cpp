#include <iostream>
#include <cmath>
#define UNASSIGNED 0
using namespace std;

bool FindUnassignedLocation(int **grid, int &row, int &col, int N){
	for(row = 0; row<N; row++)
		for(col = 0; col<N; col++)
			if(grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

bool UsedInRow(int **grid, int row, int num, int N){
	for(int i=0; i<N; i++)
		if(grid[row][i] == num)
			return true;
	return false;
}

bool UsedInCol(int **grid, int col, int num, int N){
	for(int i =0; i<N; i++)
		if(grid[i][col] == num)
			return true;
	return false;
}

bool UsedInBox(int **grid, int boxStartRow, int boxStartCol, int num, int N, int SQN){
	for(int i=0; i<SQN; i++)
		for(int j=0; j<SQN;j++)
			if(grid[i+boxStartRow][j+boxStartCol] == num)
				return true;
	return false;
}

bool isSafe(int **grid, int row, int col, int num, int N){
	return !UsedInRow(grid, row, num, N) && !UsedInCol(grid,col,num, N) && !UsedInBox(grid,row-row%(int(sqrt(N))), col-col%(int(sqrt(N))),num, N, int(sqrt(N)));
}

bool solveSudoku(int **grid, int N){
	int row, col;
	if(!FindUnassignedLocation(grid,row, col,N))
		return true;
	for(int num = 1; num<=N; num++){
		if(isSafe(grid,row,col,num,N)){
			grid[row][col]=num;
			if(solveSudoku(grid,N))
				return true;
			grid[row][col] = UNASSIGNED;
		}
	}
	return false;
}

int main(){
	int **grid, N;
	cout<<"Enter size :";
	cin>>N;
	grid = new int*[N];
	for(int i =0;i<N;i++)
		grid[i] = new int[N];
	cout<<"Enter the Sudoku puzzle(0 for unfilled) :\n";
	for(int i =0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>grid[i][j];
	if(solveSudoku(grid,N)){
		for(int i =0; i<N;i++){
			for(int j=0;j<N;j++)
				cout<<grid[i][j]<<"\t";
			cout<<"\n";
		}
	}
	return 0;
}
