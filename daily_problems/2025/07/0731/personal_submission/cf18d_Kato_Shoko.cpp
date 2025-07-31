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
    int n;
    cin>>n;
    vector<int>lastwin(2005);
    vector<bitset<2005>>dp(n+1);
    for(int i=1;i<=n;i++){
        string op;
        int x;
        cin>>op>>x;
        dp[i]=dp[i-1];
        if(op[0]=='w'){
            lastwin[x]=i;
        }else{
            int j=lastwin[x];
            if(j){
                auto old=dp[j-1];
                old.set(x);
                //取最大
                for(int k=2000;k>=0;k--){
                    if(old[k]!=dp[i][k]){
                        if(old[k])dp[i]=old;
                        break;
                    }
                }
            }
        }
    }
    string ans="0";
    for(int k=2000;k>=0;k--){
        int c=0;
        for(int i=ans.size()-1;i>=0;i--){
            int v=(ans[i]-'0')*2+c;
            ans[i]=char(v%10+'0');
            c=v/10;
        }
        if(c)ans.insert(ans.begin(),'0'+c);

        if(dp[n].test(k)){
            c=1;
            for(int i=ans.size()-1;i>=0&&c;i--){
                int v=ans[i]-'0'+c;
                ans[i]='0'+v%10;
                c=v/10;
            }
            if(c)ans.insert(ans.begin(),'0'+c);
        }
    }
    int pos=0;
    while(pos+1<ans.size()&&ans[pos]=='0')pos++;
    cout<<ans.substr(pos);
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
