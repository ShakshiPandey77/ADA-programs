#include <iostream> 
using namespace std;
bool isHeap(int arr[10], int n) 
{ 
	for (int i=0; i<=(n-2)/2; i++) 
	{ 
		if (arr[2*i +1] > arr[i]) 
				return false; 

		if (2*i+2 < n && arr[2*i+2] > arr[i]) 
				return false; 
	} 
	return true; 
} 

int main() 
{ 
	int n;
	cout<<"enter number of array elements";
	cin>>n;
	int arr[10];
	cout<<"enter elements";
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}

	isHeap(arr, n)? printf("Yes"): printf("No"); 

	return 0; 
} 

