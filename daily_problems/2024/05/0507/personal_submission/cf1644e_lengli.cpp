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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x=1,y=1;
    for(auto c:s){
        if(c=='D') x++;
        else y++;
    }
    int dx=n-x,dy=n-y;
    bool fx=0,fy=0;
    x=0,y=0;
    int res=0;
    for(auto c:s){
        if(c=='D') fx=1;
        else fy=1;
        if(fx==0 or fy==0) res++;
        else {
            if(c=='D') x++;
            else y++;
        }
    }
    if(fx==0 or fy==0) cout<<n<<endl;
    else{
        res=res*(n-1);
        res+=x*y;
        cout<<(n*n)-res<<endl;
    }
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
