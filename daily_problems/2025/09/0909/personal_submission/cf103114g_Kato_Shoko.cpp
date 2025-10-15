#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e6 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<int>pos(n+1);
    for(int mask=0;mask<10;mask++){
        vector<int>s;
        for(int i=1;i<=n;i++){
            if((i>>mask)&1)s.push_back(i);
        }
        if(s.empty())continue;
        cout<<s.size()<<" ";
        for(auto x:s)cout<<x<<" ";
        cout<<endl;

        int k=s.size();
        for(int i=0;i<k;i++){
            int v;cin>>v;
            pos[v]|=(1<<mask);
        }
    }
    vector<int>a(n+1);
    for(int v=1;v<=n;v++){
        int idx=pos[v];
        a[idx]=v;
    }
    cout<<"! ";
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
