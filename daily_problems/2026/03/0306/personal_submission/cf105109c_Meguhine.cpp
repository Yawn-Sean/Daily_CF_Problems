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

template<typename T> // Cartesian-Tree, index: 1~n
int CT(const vector<T>& a,const int& n,vector<int>& ls,vector<int>& rs){
	ls.resize(n+1),rs.resize(n+1);
	vector<int>stk(n+1);
	for(int i=1,top=0,k=0;i<=n;i++,k=top){
		while(k && a[stk[k]]<a[i]) k--;
		if(k) rs[stk[k]]=i;
		if(k<top) ls[i]=stk[k+1];
		stk[top=++k]=i;
	}
	return stk[1]; // root
}

void solve(){
    int n; cin>>n;
    vector<int>a(n+1);
    vector<LL>sum(n+1);
    for(int i=1;i<=n;++i){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
    }
    vector<int>ls,rs;
    const int rt=CT<int>(a,n,ls,rs);
    LL ans=0;
    auto dfs=[&](auto&& self,const int u,const int l,const int r)->void {
        if(ls[u]) self(self,ls[u],l,u-1);
        if(rs[u]) self(self,rs[u],u+1,r);
        if(u-l<=r-u){  // iterate left
            for(int i=u;i>=l;--i){
                const LL lsum=sum[u-1]-sum[i-1];
                if(lsum>=a[u]) break;
                int L=u+1,R=r,mid,opt=u;
                while(L<=R){
                    mid=(L+R)>>1;
                    const LL rsum=sum[mid]-sum[u];
                    if(lsum+rsum<a[u]){
                        opt=mid;
                        L=mid+1;
                    }
                    else R=mid-1;
                }
                ans+=opt-u+1;
            }
        }
        else{  // iterate right
            for(int i=u;i<=r;++i){
                const LL rsum=sum[i]-sum[u];
                if(rsum>=a[u]) break;
                int L=l,R=u-1,mid,opt=u;
                while(L<=R){
                    mid=(L+R)>>1;
                    const LL lsum=sum[u-1]-sum[mid-1];
                    if(lsum+rsum<a[u]){
                        opt=mid;
                        R=mid-1;
                    }
                    else L=mid+1;
                }
                ans+=u-opt+1;
            }
        }
    };
    dfs(dfs,rt,1,n);
    cout<<ans<<'\n';
}
int main(){
#ifndef LOCAL
    cin.tie(nullptr)->sync_with_stdio(false);
#endif
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
