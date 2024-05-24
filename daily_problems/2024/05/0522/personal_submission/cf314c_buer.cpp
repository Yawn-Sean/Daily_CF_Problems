#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,M=2*N,mod=1e9+7;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
int f[N];
class BitTree {
    public:
	vector<int> tree;
	int n;
    BitTree(int _n) : n(_n) {
	    tree.resize(n+1);
	    fill(tree.begin(),tree.end(),0);
	}
	inline int lowbit(int x) { return x&-x; }
	inline void Modify(int x,int v) {
		for(;x<=n;x+=lowbit(x)){
            tree[x]=((tree[x]+v)%mod+mod)%mod;
        }
	}
	inline int q(int x) {
		int ret=0;
		if(x<=0) return 0;
		for(;x;x-=lowbit(x)) ret=(ret+tree[x])%mod;
		return ret;
	}
	inline int Query(int l,int r) {
		return q(r)-q(l-1);
	}
};
int pre[N];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    BitTree tr(N);
    
    for(int i=1;i<=n;i++){
        f[i]=a[i];
        f[i]+=tr.q(a[i])*a[i]%mod;
        f[i]%=mod;
        if(pre[a[i]]) tr.Modify(a[i],-f[pre[a[i]]]),f[pre[a[i]]]=0;
        pre[a[i]]=i;
        tr.Modify(a[i],f[i]);
    }
    int res=0;
    for(int i=1;i<=n;i++){
        res=(res+f[i])%mod;
    }
    cout<<res<<"\n";
}   

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
