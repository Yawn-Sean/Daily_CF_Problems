#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll N = 1e5 + 5, mod = 1e9+7, inf = 2e18;

il int find(ll x,ll n,int p,vector<int>&a){
    int ans=0;
    while(1){
        if(x<=n*2){
            ans^=a[x];
            break;
        }
        ans^=p;
        if((x/2-n)%2==0){
            break;
        }
        x>>=1;
    }
    return ans;
}

il void solve() {
    ll n,l,r;
    cin>>n>>l>>r;
    vector<int>a(n+1),per(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        per[i]=per[i-1]+a[i];
    }

    if(n%2==0){
        n++;
        int temp=per[n/2]&1;
        a.push_back(temp);
        per.push_back(per.back()+temp);
    }

    for(int i=n+1;i<=2*n;i++){
        a.push_back(per[i/2]&1);
        per.push_back(per[i-1]+a[i]);
    }

    int p=per[n]&1;

    cout<<find(l,n,p,a)<<'\n';

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
