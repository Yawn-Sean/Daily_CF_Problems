#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 5e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>a(n+1,vector<char>(m+1,'.'));
    auto b=a;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    struct Node{
        int x,y,z;
    };
    vector<Node>ans;
    for(int i=2;i<n;i++){
        for(int j=2;j<m;j++){
            if(a[i][j]=='.')continue;
            int x=0;
            while(i+x<=n&&i-x>=1&&j+x<=m&&j-x>=1){
                if(a[i+x][j]=='*'&&a[i-x][j]=='*'&&a[i][j+x]=='*'&&a[i][j-x]=='*'){
                    x++;
                }else{
                    break;
                }
            }
            x--;
            if(x>0){
                for(int k=i-x;k<=i+x;k++){
                    b[k][j]='*';
                }
                for(int k=j-x;k<=j+x;k++){
                    b[i][k]='*';
                }
                ans.push_back({i,j,x});
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i]){
            cout<<-1;
            return ;
        }
    }
    cout<<ans.size()<<'\n';
    for(auto [x,y,z]:ans){
        cout<<x<<" "<<y<<" "<<z<<'\n';
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
