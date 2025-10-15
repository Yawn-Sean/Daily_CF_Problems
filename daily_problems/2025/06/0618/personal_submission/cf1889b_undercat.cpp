#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
   int n,c;cin>>n>>c;
   vector<int>a(n);
   vector<pair<int,int>>b;
   for(auto&i:a)cin>>i;
   for(int i=1;i<n;i++){
    pair<int,int>t;
    t.first=(i+1)*c-a[i];
    t.second=i;
    b.push_back(t);
   }
   sort(b.begin(),b.end());
   int now=a[0];
   for(int i=0;i<n-1;i++){
    if(b[i].first>now){
        cout<<"NO\n";return;
    }
    now+=a[b[i].second];
   }
   cout<<"Yes\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;while(t--)
    solve();
}