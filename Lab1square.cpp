#include <iostream>
#include <fstream>
using namespace std;

int sqroot(int x)
{ 
if(x<2)
    return x;
int result;
int start=1;
int end=x/2;
while(start<=end)
{
    int mid=(start+end)/2;
    int sqr=mid*mid;
    if(sqr==x)
        return mid;
    else if(sqr<x)
    {
        start=mid+1;
        result=mid;
    }
    else{
        end=mid-1;
    }
        
}
return result;
}
int main(){
    ifstream inFile;
    inFile.open("/home/bmsce/Documents/ADA/binary/test.txt");
    if(!inFile)
    {
        cout<<"error";
        return -1;
    }
    int num;
    while(inFile>>num)
    {
        cout<<"square root of "<<num<<" : "<<sqroot(num)<<endl;
    }
    return 0;
}


