#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=998244353;
#define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int>;
int n,m,k;
int a[N];
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
		for(;x<=n;x+=lowbit(x)) tree[x]+=v;
	}
	inline int q(int x) {
		int ret=0;
		if(x<=0) return 0;
		for(;x;x-=lowbit(x)) ret+=tree[x];
		return ret;
	}
	inline int Query(int l,int r) {
	   
		return q(r)-q(l-1);
	}
};
vector<int> num;
int find(int x){
    return lower_bound(num.begin(),num.end(),x)-num.begin()+1;
}
void solve()
{
    cin>>n;
    num.clear();
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) num.push_back(a[i]);
    sort(num.begin(),num.end());
    num.erase(unique(num.begin(),num.end()),num.end());
    m=num.size();
    BitTree tr(m);
    int res=0;
    for(int i=1;i<=n;i++){
        a[i]=find(a[i]);
        tr.Modify(a[i],1);
    }
    for(int i=n;i>=1;i--){
        tr.Modify(a[i],-1);
        int x=tr.q(a[i]-1);
        int y=tr.Query(a[i]+1,m);
        res+=min(x,y);
    }
    cout<<res<<"\n";
}

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
    cin>>t;
    while(t--) solve();
    return 0;
}
