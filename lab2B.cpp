#include <iostream>
#include <fstream>
using namespace std;
void bubble(int a[],int n,int k)
{
int i,j;
for(i=0;i<k;i++)
{
for(j=0;j<n-i-1;j++)
{
if(a[j+1]<a[j])
{
int temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}
cout<<a[n-i-1]<<endl;
}
}
int main()
{
ifstream inFile;
inFile.open("test1.txt");
if(!inFile)
{
cout<<"error";
return -1;
}
int k,n;
inFile>>n;
int a[n];
for(int i=0;i<n;i++)
inFile>>a[i];
inFile>>k;
bubble(a,n,k);
}
