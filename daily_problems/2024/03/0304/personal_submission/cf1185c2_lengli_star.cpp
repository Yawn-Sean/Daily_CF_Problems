//假设前i-1个人总共需要b分钟进行考试
//那么第i个人能通过考试，说明至少要将考试时间缩短时间t=m-(b+x)
//即从前面选出最少的数字，使得时间综合>=t
//发现 100>=t_i>=1 所以直接暴力即可 

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
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x:a) cin>>x;

    vector<int> cnt(110,0);
    for(int i=1,b=0;i<=n;i++){
        int x=a[i-1];
        int sum=(b+x)-m,res=0;
        for(int i=100;i>=0 and sum>0;i--){
            if(!cnt[i]) continue;
            if(sum>=cnt[i]*i) sum-=cnt[i]*i,res+=cnt[i];
            else{
                int nd=(sum+(i-1))/i;
                sum=0,res+=nd;
            }
        }
        cnt[x]++;
        b+=x;
        cout<<res<<" ";
    }
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
