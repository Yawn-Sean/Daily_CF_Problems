#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  ios::sync_with_stdio(false);cin.tie(0);
  int _=1;
//  cin>>_;
  while(_--){
    int i,j,x,y,z,n;
    cin>>n;
    map<int,int>mp;
    int c=n;
    int mi=1e9,ma=-1e9;
    for(i=1;i<=n;i++){
      cin>>x;
      mp[x]++;
      mi=min(mi,x);
      ma=max(ma,x);
    }
    if(ma-mi==2){
      int cnt=min(mp[mi],mp[ma]);
      if(cnt*2<mp[mi+1]/2*2){
        c-=mp[mi+1]/2*2;
        mp[mi]+=mp[mi+1]/2;
        mp[ma]+=mp[mi+1]/2;
        mp[mi+1]%=2;
      }
      else{
        c-=cnt*2;
        mp[mi+1]+=cnt*2;
        mp[mi]-=cnt;
        mp[ma]-=cnt;
      }
    }
    cout<<c<<'\n';
    for(auto &[x,y]:mp){
      while(y--)cout<<x<<" ";
    }
    
  }

  
}
