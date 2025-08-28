#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    int n;
    cin>>n;
    vector<int>cnt(1001);
    for(int i=1;i<=n*n;i++){
        int x;cin>>x;
        cnt[x]++;
    }
    vector<pair<int,pair<int,int>>>p;
    for(int i=0;i<(n+1)/2;i++){
        for(int j=0;j<(n+1)/2;j++){
            if(i!=n-i-1&&j!=n-j-1){
                p.push_back({4,{i,j}});
            }else if((i!=n-i-1)^(j!=n-j-1)){
                p.push_back({2,{i,j}});
            }else{
                p.push_back({1,{i,j}});
            }
        }
    }

    vector<vector<int>>ans(n+1,vector<int>(n+1));

    for(auto cur:{4,2,1}){
        int now=1;
        for(auto [x,y]:p){
            if(x!=cur)continue;
            auto [i,j]=y;
            while(now<=1000&&cnt[now]<cur){
                now++;
            }
            if(now==1001){
                cout<<"NO";
                return ;
            }
            ans[i][j]=ans[n-i-1][j]=ans[i][n-j-1]=ans[n-i-1][n-j-1]=now;
            cnt[now]-=cur;
        }
    }
    cout<<"YES\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" \n"[j==n-1];
        }
    }
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
