#include <iostream>
using namespace std;
int partition(int a[],int low,int high);
void quick(int a[],int low,int high){
	if(low<high){
		int pivot=partition(a,low,high);
		quick(a,low,pivot-1);
		quick(a,pivot+1,high);
	}
}
int partition(int a[],int low,int high){
	int pivot=a[low];
	int i=low+1;
	int j=high;
	while(1){
		while(a[i]<=pivot && i<=high)
		{
			i++;
		}
		while(a[j]>pivot && j>=low)
		{
			j--;
		}
		if(i<j)
		{
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else{
			a[low]=a[j];
			a[j]=pivot;
			return j;
		}
	}
}
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 
int main()
{
	
	int a[]={10,5,7,9,4,6};
	int n=6;
	quick(a,0,n-1);
	cout<<"sorted array: ";
	printArray(a,n);
	
	return 0;
}

