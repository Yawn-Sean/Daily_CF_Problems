/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#define int long long

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>> f(n+2,vector<int> (n+2,0));
    vector<int> res(n+2);
    for(int i=1;i<=n;i++) f[i][i]=1,res[1]++;
    for(int len=2;len<=n;len++){
        for(int i=1,j=i+len-1;j<=n;i++,j++){
            if(s[i-1]!=s[j-1] or i+1<=j-1 and f[i+1][j-1]==0) f[i][j]=0;
            else f[i][j]=f[i][i+len/2-1]+1;
            res[f[i][j]]+=(f[i][j]>0);
        }
    }
    for(int i=n;i>=1;i--) res[i]+=res[i+1];
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
