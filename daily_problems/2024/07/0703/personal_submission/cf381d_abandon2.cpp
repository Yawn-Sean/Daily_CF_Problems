#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;
using PII=pair<int,int>;
#define x first
#define y second

int c[N],a[N];
void solve(){
    int n,m;cin>>n>>m;
    std::vector<PII> v;
    int x=1e9;
    for(int i=1;i<=m;i++){
        int l,r;cin>>l>>r;
       x=min(x,r-l+1);
    }   
    cout<<x<<"\n";

    for(int i=0;i<n;i++){
        cout<<i%x<<" ";
    }
   
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
