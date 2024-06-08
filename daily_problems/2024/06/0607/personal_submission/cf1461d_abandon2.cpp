#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef long long LL;
#define int long long
int a[N],b[N];
void solve(){
    int n,q;cin>>n>>q;
    int s=0;
    std::vector<LL>sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];

    map<LL,int>mp;
    auto fen=[&](auto &&fen,int l,int r){
        if(l>r)return;
        int s=sum[r]-sum[l-1];
        //cout<<l<<" "<<r<<"  "<<s<<"\n";
        mp[s]++;
        int mx=a[r];
        int mn=a[l];
        //if(mx<=(mx+mn)/2)return;
        //cout<<mx<<" "<<mn<<"s\n";
        int c=(mx+mn)/2;
        int t=upper_bound(a+1,a+1+n,c)-a;
        if(t==r+1)return;
        //cout<<t<<" dd\n";
        //cout<<c<<"  xxx\n";
        fen(fen,l,t-1);fen(fen,t,r);
    }; 
    fen(fen,1,n);
    // for(auto [x,y]:mp){
    //     cout<<x<<" "<<y<<"\n";
    // }
   while(q--){
        int x;cin>>x;
        if(mp.count(x)){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;cin>>tt;
    while(tt--)
        solve();
    return 0;
}
