#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int>num(n),parity(m+1);
    for(auto &v:num){
        cin>>v;
        parity[v]^=1;
    }
    vector<ll>nex(m+1,inf);
    for(int v=1;v<=m;v++){
        if(parity[v])nex[v]=0;
    }

    for(int i=m;i>0;i--){
        nex[i-1]=min(nex[i-1],nex[i]+1);
    }
    nex[m]=min(nex[m],nex[0]);
    for(int i=m;i>0;i--){
        nex[i-1]=min(nex[i-1],nex[i]+1);
    }

    ll s=0;
    while(q--){
        int op;
        cin>>op;
        if(op==1){
            s++;
        }else{
            int idx;cin>>idx;
            int x=num[idx-1];

            int step=nex[x]==inf?s:min(s,nex[x]);
            cout<<((x-1+step)%m)+1<<'\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
