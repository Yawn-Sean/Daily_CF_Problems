//从上到下枚举y分成若干层。
//对于每一层的点，按照x从小到大枚举。
//考虑当前枚举的某个点，我们让其对答案的贡献为，右端点不超过下一个点的所有方案，这样就不会重复计算。
//假设当前点为x1，下一个点为x2，对答案的贡献即 a*b ,a为小于x1的不同横坐标，b为>x1,<x2的不同横坐标。


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

const int N=200010;

int tr[N];
bool st[N];
void add(int x){
    if(st[x]) return;
    st[x]=1;
    for(int i=x;i<N;i+=(i&-i)) tr[i]+=1;
}
int query(int x){
    int res=0;
    for(int i=x;i;i-=(i&-i)) res+=tr[i];
    return res;
}

vector<int> hs;

void solve(){
    int n;
    cin>>n;
    vector<array<int,2>> a(n+1);
    map<int,vector<int>> q;
    for(int i=1;i<=n;i++){
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
        hs.pb(x);
    }
    sort(all(hs));
    hs.erase(unique(all(hs)),hs.end());
    auto find=[&](int x)->int{
        return lower_bound(all(hs),x)-hs.begin()+1;
    };
    for(int i=1;i<=n;i++){
        int x=find(a[i][0]),y=a[i][1];
        q[-y].push_back(x);
    }
    long long res=0;
    for(auto &[c,v]:q){
        sort(all(v));
        for(int i=0;i<v.size();i++){
            int l=v[i],r=(i==v.size()-1 ? N-1 : v[i+1]);
            add(l);
            res+=(long long)query(l)*(long long)(query(r-1)-query(l)+1ll);
        }
    }
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
