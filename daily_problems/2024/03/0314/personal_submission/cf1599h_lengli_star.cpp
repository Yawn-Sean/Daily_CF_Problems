//到某个点的曼哈顿距离相同的点，可以刻画到一条直线，那么我们先问(1,1),(1,inf),并找到交点后，便可以得到矩形左边界
//同理可以计算右边界，再根据询问可以推出上下边界，那就愉快的做完了QAQ

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

const int N=100010,inf=1e9;

void solve(){
    auto query=[&](int x,int y){
        cout<<"? "<<x<<" "<<y<<endl;
        int res;
        cin>>res;
        return res;
    };
    int a=query(1,1);
    int b=query(1,inf);
    int t=(a+b-inf+1)/2;
    t=(-t+a+1);
    int mi=query(1,t);
    int x=1+mi,y=a-mi+1;
    auto c=query(inf,1);
    c-=(y-1);
    auto d=query(inf,inf);
    int p=inf-c,q=inf-(d-c);
    cout<<"! "<<x<<" "<<y<<" "<<p<<" "<<q<<endl;

    

}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
