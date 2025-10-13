#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod =998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto &i:a)cin>>i;

    vector<int>ans;

    for(int i=n-1;i>=0;i--){
        bool flag=false;
        for(int j=i;j>=0;j--){
            if(a[j]==j+1){
                flag=true;
                ans.push_back(a[j]);
                a.erase(a.begin()+j,a.begin()+j+1);
                break;
            }
        }
        if(!flag){
            cout<<"NO";
            return ;
        }
    }
    cout<<"YES\n";
    reverse(ans.begin(),ans.end());
    for(auto i:ans)cout<<i<<" ";
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
