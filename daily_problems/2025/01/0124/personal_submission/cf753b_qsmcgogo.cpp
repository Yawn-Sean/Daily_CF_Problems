#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
long long a[202202],b[1102010];


signed main(){
  // ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int l,r,n,m,i,j,k;
    map<int,int>mp;
    string s;
    int tong[20]={};
    for(i=0;i<=9;i++){
      cout<<i<<i<<i<<i<<endl;
      cin>>tong[i]>>j;
      if(tong[i]==4)return 0;
    }
    for(i=0;i<10;i++)if(!tong[i])break;
    int z=i;
    for(i=0;i<10;i++){
      if(tong[i]){
        for(j=0;j<16;j++){
          int cc[4]={},cnt=0;
          for(k=0;k<4;k++){
            if(j>>k&1){
              cc[k]=i;
              cnt++;
            }
            else cc[k]=z;
          }
          if(cnt==tong[i]){
            for(k=0;k<4;k++)cout<<cc[k];
            cout<<endl;
            int x,y;
            cin>>x>>y;
            if(x==4)return 0;
            if(x==tong[i]){
              for(k=0;k<4;k++){
                if(cc[k]==i)a[k]=i;
              }
              break;
            }
          }
        }
      }
    }
    for(i=0;i<4;i++)cout<<a[i];
    cout<<endl;
    cin>>i>>i;
    return 0;
  }
  
}
