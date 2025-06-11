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
    int res=0;
    for(int i=0;i<n;i++){
        int sum=0,cnt=0;
        for(int j=i;j<n;j++){
            char c=s[j];
            if(c=='(') sum++;
            else if(c==')') sum--;
            else{
                if(sum>0) sum--,cnt++;
                else sum++;
            }
            while(sum<0 and cnt>0) sum+=2,cnt--;
            if(sum<0 and !cnt) break;
            if(sum==0) {
                res++;
            }
        }
    }
    cout<<res;
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
