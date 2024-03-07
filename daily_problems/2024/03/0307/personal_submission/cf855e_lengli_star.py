//就是数位dp的模板，只不过要转换为b进制下，多开一维记录b即可。
//详细题解可以参考小羊QAQ

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

int f[11][63][1<<10][2];
int a[63],idx;

int dfs(int pos,int mask,int b,bool limit,bool zero){
    if(!pos){
        return !zero and mask==0;
    }
    auto &ans=f[b][pos][mask][zero];
    if(!limit and ans!=-1) return ans;
    int ma=(limit ? a[pos] : b-1);
    int res=0;
    for(int i=0;i<=ma;i++){
        res+=dfs(pos-1,zero and !i ? mask : mask^(1<<i),b,limit and i==ma,zero and !i);
    }
    return !limit ? ans=res : res;
}

int cal(int b,int x){
    idx=0;
    while(x){
        a[++idx]=x%b;
        x/=b;
    }
    return dfs(idx,0,b,1,1);
}

void solve(){
    int n;
    cin>>n;
    memset(f,-1,sizeof f);
    for(int i=1;i<=n;i++){
        int b,l,r;
        cin>>b>>l>>r;
        cout<<cal(b,r)-cal(b,l-1)<<endl;
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
