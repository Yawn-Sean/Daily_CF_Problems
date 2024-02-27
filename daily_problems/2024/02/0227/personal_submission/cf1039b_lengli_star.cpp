//由于询问次数很大，每次位置变化却很小，考虑随机。
//每次错误的的概率哪怕0.99，4000次全错的概率也可以胡萝卜鸡(忽略不计)了QAQ
//二分调整区间，然后对区间随机一个位置询问即可，注意区间范围保证列车时刻都在询问区间内部。
/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
    int n,k;
    cin>>n>>k;
    
    auto query=[&](int l,int r)->bool{
        cout<<l<<" "<<r<<endl;
        string s;
        cin>>s;
        return s=="Yes";
    };
    if(n==1) {
        query(1,1);
        return;
    }
    
    mt19937 rd(time(0));
    
    int l=1,r=n;
    for(int i=1;i<=4500;i++){
        l=max(1ll,l-3*k);
        r=min(n,r+3*k);
        int mid=(l+r)/2;
        if(query(l,mid)) r=mid;
        else l=mid+1;
        
        if(l==r and !k){
            cout<<l<<" "<<r<<endl;
            string s;
            cin>>s;
            return;
        }
        auto t=rand()%(r-l+1)+l;
        if(l+6*k>=r){
            if(query(t,t)) return;
        }
    }
}

signed main(){
    fastio;
    srand(time(0));
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
