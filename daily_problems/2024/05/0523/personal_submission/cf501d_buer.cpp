#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2*N,mod=1e9+7;
 #define int long long
#define uLL unsigned long long
const long long inf=1e18;
typedef pair<int,int> PII;
typedef long long LL;
using node=tuple<int,int,int,int>;
int n,m,k;
int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
int a[N];
int fact[N];
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
class segment{
    #define lson (u << 1)
    #define rson (u << 1 | 1)
    public:
    int n;
    vector<int> sum;
    segment(int _n) : n(_n) {
        sum.resize(n*4);
        build(1,1,n);
    }
    void pushup(int u){
        sum[u]=sum[lson]+sum[rson];
    }
    void build(int u, int l, int r){
        if (l == r)
        {
            sum[u]=1;
            return ;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(u);
    }
    void pushdown(int u,int l,int r){

    }
    void modify(int u, int l, int r, int pos, int val){
        if (l==r)
        {
            sum[u]+=val;
            return;
        }
        pushdown(u,l,r);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify(lson, l, mid,pos, val);
        else modify(rson, mid + 1, r,pos, val);
        pushup(u);
    }
    int query(int u,int l,int r,int k)
    {
        if(l==r){
            return l;
        }
        pushdown(u,l,r);
        LL res=0;
        int mid=l+r>>1;
        if(k<=sum[lson]) return query(lson,l,mid,k);
        else return query(rson,mid+1,r,k-sum[lson]);
        //if(L<=mid) res+=query(lson,l,mid,L,R);
        //if(R>mid) res+=query(rson,mid+1,r,L,R);
        return res;
    }
};
int prem[N];
void solve()
{
    cin>>n;
    BitTree tr(n+10);
    for(int i=1;i<=n;i++) tr.Modify(i,1);
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i]++;
        tr.Modify(a[i],-1);
        prem[i]+=tr.q(a[i]);
    }
    // for(int i=1;i<=n;i++)
    // cout<<prem[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++) tr.Modify(i,1);
    for(int i=1;i<=n;i++){
        cin>>a[i];a[i]++;
        tr.Modify(a[i],-1);
        prem[i]+=tr.q(a[i]);
    }
    for(int i=n,j=0;i>=1;j++,i--){
        prem[i-1]+=prem[i]/(j+1),prem[i]%=(j+1);
    }
    // for(int i=1;i<=n;i++)
    // cout<<prem[i]<<" ";
    // cout<<"\n";
    segment tree(n);
    for(int i=1;i<=n;i++)
    {
        int k=tree.query(1,1,n,prem[i]+1);
        cout<<k-1<<" ";
        tree.modify(1,1,n,k,-1);
    }
}   

signed main(){
    cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
    int t=1;
   // cin>>t;
    while(t--) solve();
    return 0;
}
