#include<iostream>
using namespace std; 
int max(int a, int b) 
{ 
  return (a > b)? a : b;
} 
int knapSack(int W, int wt[], int val[], int n) 
{ 
   int i, w; 
   int K[n+1][W+1]; 

   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++) 
       { 
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
  int n,val[10],wt[10];
  cout<<"enter the total items in array";
  cin>>n;
  cout<<"enter values";
  for(int i=0;i<n;i++)
  {
    cin>>val[i];
  }
  cout<<"enter weight";
  for(int i=0;i<n;i++)
  {
    cin>>wt[i];
  }
  int W=50;
    cout<<"Max weight set:"<< knapSack(W, wt, val, n)<<endl; 
    return 0; 
} 