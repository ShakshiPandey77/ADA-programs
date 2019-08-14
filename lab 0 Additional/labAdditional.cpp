#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
int find(int a[],int n,int key);
int main() {
	int sum = 0;
	int x,t,n,k,j=0;
	ifstream inFile;
    
	inFile.open("ex.txt");
	if (!inFile) {
	        cout << "Unable to open file";
	        exit(1); // terminate with error
	    }
	inFile>>x;
	t=x;
	int te=t;
	int o[te];
while(t>0){
	inFile>>x;
	n=x;
	inFile>>x;
	k=x;
	int arr[n];
	for(int i=0;i<n;i++){
	inFile>>x;
	arr[i]=x;
	}
	 ;
	o[j]=find(arr,n,k);
	j++;
	t--;
    }
	for(int y=0;y<te;y++){
	 cout<<o[y]<<endl;
}
    inFile.close();
    return 0;
}
int find(int a[],int n,int key){
int beg=0,end=n-1,mid,flag=-1;
while(beg<=end){
	mid=(beg+end)/2;
	if(a[mid]==key){
		flag=1;
		break;
	}
	else if(key<a[mid])
		end=mid-1;
	else
		beg=mid+1;
}
if(flag==1) 
	return 1;
else
	return -1;
}
