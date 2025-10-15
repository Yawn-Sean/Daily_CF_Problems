#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=0;
    vector<vector<int>>lcp(n+1,vector<int>(n+1,0));
    auto check=[&](char a,char b){
        return a==b||a=='?'||b=='?';
    };

    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(check(s[i],s[j])){
                lcp[i][j]=lcp[i+1][j+1]+1;
            }else{
                lcp[i][j]=0;
            }
            if(lcp[i][j]>=j-i){
                ans=max(ans,j-i);
            }
        }
    }
    cout<<ans*2<<'\n';
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
