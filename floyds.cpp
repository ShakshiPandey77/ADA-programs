#include<bits/stdc++.h>
using namespace std;
void floyds(vector<vector<int>> &a,int n){

  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
      }
    }
  }

  cout<<"output\n";
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<a[i][j]<<"\t";
    }
    cout<<"\n";
  }

}



int main(){
  int n,src;
  cout<<"enter number of nodes\n";
  cin>>n;
  vector<vector<int>> c;
  cout<<"enter the cost matrix\n";
  for(int i=0;i<n;i++){
    vector<int> temp;
    for(int j=0;j<n;j++){
      int ele;
      cin>>ele;
      temp.push_back(ele);
    }
    c.push_back(temp);
  }

  floyds(c,n);
  /*
  enter the number og nodes:5
  enter the cost:
0 2 999 1 8
6 0 3 2 999
999 999 0 4 999
999 999 2 0 3
3 999 999 999 0
output
0       2       3       1       4
6       0       3       2       5
10      12      0       4       7
6       8       2       0       3
3       5       6       4       0
  */


  return 0;
}
