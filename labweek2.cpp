#include <iostream>
#include <fstream>
using namespace std;

void sorting(int n,int a[],int k){
    for(int i=0;i<k-1;i++)
    {
        min=i;
    }
    for(int j=i+1;j<n;j++)
    {
        if(a[j]<a[min])
        {
            min=j;
        }
        int temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
    
}

int main()
{
    ifstream inFile;
    inFile.open("/home/bmsce/Documents/ADA/binary/input.txt");
    if(!inFile)
    {
        cout<<"error";
        return -1;
    }
    int k,ar[n];
    for(int i=0;i<n;i++)
        inFile>>a[n];
    inFile>>k;
sorting(a,n,k);
}