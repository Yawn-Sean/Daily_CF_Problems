#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int x[3],y[3];
    for(int i=0;i<3;i++)cin>>x[i]>>y[i];
    if((x[0]==x[1]&&x[1]==x[2])||(y[0]==y[1]&&y[1]==y[2])){
      cout<<1;return;
    }
    for(int i=0;i<3;i++){
      int j=(i+1)%3, k=(i+2)%3;
      if(x[i]==x[j]&&(y[k]>=max(y[i],y[j])||y[k]<=min(y[i],y[j]))){
        cout<<2;return;
      }
      if(y[i]==y[j]&&(x[k]>=max(x[i],x[j])||x[k]<=min(x[i],x[j]))){
        cout<<2;return;
      }
    }
    cout<<3;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}