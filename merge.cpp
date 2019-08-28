#include<iostream>
using namespace std;
void combine(int a[],int low,int mid,int high)
{
int c[high];
int i=low;
int j=mid+1;
int k=low;
while(i<=mid && j<=high)
{
if(a[i]<a[j])
c[k++]=a[i++];
else
c[k++]=a[j++];
}
if(i>mid)
while(j<=high)
c[k++]=a[j++];
if(j>high)
while(i<=mid)
c[k++]=a[i++];
for(i =low;i<=high;i++)
a[i]=c[i];
}
void split(int a[],int low,int high)
{
if(low<high)
{
int mid=(low+high)/2;
split(a,low,mid);
split(a,mid+1,high);
combine(a,low,mid,high);
}
}
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 
int main(){
int a[]={6,2,10,7,5,8};
int n=6;
split(a,0,n-1);
cout<<"sorted array: ";
printArray(a,n);
return 0;
}

