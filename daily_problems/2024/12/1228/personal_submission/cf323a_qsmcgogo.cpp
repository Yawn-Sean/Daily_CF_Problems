#include<bits/stdc++.h>
using namespace std;

signed main(){
  int n,i,j,k;
  cin>>n;
  string c="bw";
  if(n&1)return cout<<-1,0;
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
        cout<<c[i+(j/2)+(k/2)&1];
      }
      cout<<'\n';
    }
    cout<<'\n';
  }
}
