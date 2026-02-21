#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include<local/dbg.h>
#else
#define dbg(...) 42
#endif

using LL=long long;
#define ai(x) using ai##x=array<int,x>;
ai(2);ai(3);ai(4);ai(5);ai(6);ai(7);ai(8);ai(9);ai(10);ai(26);
#undef ai

#define all(x) (x).begin(),(x).end()
#define allr(x) (x).rbegin(),(x).rend()
template<class T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<class T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<class T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

int main(){
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int n,B;
    cin>>n>>B;
    vector<ai2>o(n);
    for(auto& [_,a]:o) cin>>a;
    for(auto& [b,_]:o) cin>>b;
    sort(allr(o));
    vector<int>dp(n+1,B+1);
    dp[0]=0;
    for(int c=0;auto [b,a]:o){
        for(int x=c;x>=0;--x){
            LL tmp=1ll*x*b+a+dp[x];
            if(tmp<=B) updmn(dp[x+1],int(tmp));
        }
        c+=1;
    }
    for(int x=n;x>=0;--x){
        if(dp[x]<=B){
            cout<<x<<' '<<dp[x];
            break;
        }
    }
    return 0;
}
