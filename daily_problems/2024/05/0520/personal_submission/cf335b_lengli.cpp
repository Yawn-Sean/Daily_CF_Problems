/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

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
    if(n>=3000){
        vector<int> cnt(26,0);
        char res;
        for(auto x:s){
            cnt[x-'a']++;
            if(cnt[x-'a']>=100) {
                res=x;
                break;
            }
        }
        cout<<string(100,res)<<endl;
        return;
    }

    vector<vector<int>> f(n+2,vector<int> (n+2,0));

    int res=1,l=1,r=1;
    for(int i=n;i>=1;i--){
        for(int j=i;j<=n;j++){
            if(i==j) f[i][j]=1;
            else if(s[i-1]==s[j-1]){
                if(i+1<j) f[i][j]=max(f[i][j],f[i+1][j-1]+2);
                else f[i][j]=max(f[i][j],2);
            }else{
                f[i][j]=max(f[i][j],f[i+1][j]);
                f[i][j]=max(f[i][j],f[i][j-1]);
            }
            if(f[i][j]>res){
                res=f[i][j];
                l=i,r=j;
            }
        }
    }

    string a="",b="";
    while(l<=r){
        if(s[l-1]==s[r-1]){
            a+=s[l-1];
            if(l!=r) b+=s[r-1];
            l++,r--;
        }else{
            if(f[l+1][r]==f[l][r]) l++;
            else r--;
        }
    }

    if(res>100 and res&1) a.pop_back();
    reverse(all(b));
    reverse(all(a));
    while(a.size()+b.size()>100) a.pop_back(),b.pop_back();
    reverse(all(a));
    cout<<a<<b<<endl;
}

signed main(){
    fastio;

    #ifndef ONLINE_JUDGE
        freopen("1.in","r",stdin);
        freopen("1.out","w",stdout);
    #endif

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
