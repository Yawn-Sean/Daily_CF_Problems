#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    
    vector<int>dp(n,1e18);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='.') break;
        if(s[i]>='5') dp[i]=1;
        if(i<=n-2&&s[i]=='4') dp[i]=min(dp[i],dp[i+1]+1);
    }

    int t=1e18;
    for(int i=0;i<=n-1;i++){
        if(dp[i]<=k){
            t=i;
            break;
        }
    }
    // cout<<t<<endl;
    if(t!=1e18){
        string ss="";
        int d=1;
        for(int i=t-1;i>=0;i--){
            if(s[i]=='9'&&d) s[i]='0';
            else if(s[i]!='.'&&d) s[i]++,d=0;
            ss+=s[i];
        }
        if(d) ss+='1';
        reverse(all(ss));
        for(int i=0;i<ss.size();i++){
            if(i==ss.size()-1&&ss[i]=='.') break;
            cout<<ss[i];
        }
    }
    else cout<<s<<endl;
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
