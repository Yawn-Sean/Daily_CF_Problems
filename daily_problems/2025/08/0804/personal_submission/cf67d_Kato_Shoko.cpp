#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 6e5 + 5, mod = 1e9+7, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<int>a(n+1),b(n+1);
    vector<int>pos_a(n+1),pos_b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pos_a[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        pos_b[b[i]]=i;
    }
    vector<int>num(n);
    for(int i=1;i<=n;i++){
        num[pos_a[i]-1]-=pos_b[i];
    }
    vector<int>dp={num[0]};
    for(int i=1;i<n;i++){
        if(num[i]>dp.back()){
            dp.push_back(num[i]);
        }else{
            auto it=lower_bound(dp.begin(),dp.end(),num[i]);
            *it=num[i];
        }
    }
    cout<<dp.size();
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
