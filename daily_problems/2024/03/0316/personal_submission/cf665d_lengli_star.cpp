//1很特殊！
//如果全是1，是合法的，否则只能再加入一个数，这个数+1是质数
//一个不是1的奇数+一个偶数=质数，那么他俩也合法，多一个质数或者偶数，都会出现合数，那就不合法了
//注意，一个数也合法。
//三种情况对比取最大值即可

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

const int N=2000010;

bool is_pr[N];

vector<int> init_prime(int n){
    vector<int> prime,st(n+1,0);
    for(int i=2;i<=n;i++){
        if(!st[i]) prime.push_back(i),is_pr[i]=1;
        for(int j=0;prime[j]*i<=n;j++){
            st[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    return prime;
}

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),l,r;
    int res=0;
    vector<int> ans;
    for(auto &x:a) {
        cin>>x;
        if(x&1) l.pb(x);
        else r.pb(x);
    }
    int cnt=0;
    for(auto x:l) if(x==1) cnt++,ans.pb(1);
    res=cnt;

    for(auto x:l)
        for(auto y:r){
            if(is_pr[x+y]){
                int k=(x==1 ? cnt : 1)+1;
                if(res<k){
                    res=k;
                    ans.clear();
                    if(x==1) {
                        for(int i=1;i<=cnt;i++) ans.pb(1);
                    }else ans.pb(x);
                    ans.pb(y);
                }
            }
        }
    
    if(res==0) res=1,ans.pb(a[0]);
    cout<<res<<endl;
    for(auto x:ans) cout<<x<<" ";

}

signed main(){
    fastio;

    init_prime(2e6+1);

    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
