/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

const int N=500010;

int root[N],idx;
int a[N];
struct Node{
	int ls,rs;
	int v;
}tr[N*30];

int build(int l,int r){
	int u=++idx;
	tr[u]={-1,-1,0};
	if(l==r) return u;
	int mid=(l+r)/2;
	tr[u].ls=build(l,mid);
	tr[u].rs=build(mid+1,r);
	return u;
}

int update(int p,int x,int c,int l,int r){
	int u=++idx;
	tr[u]=tr[p];
	if(l==r) {
        tr[u].v=std::max(tr[u].v,c);
        return u;
    }
	int mid=(l+r)/2;
	if(x<=mid) tr[u].ls=update(tr[u].ls,x,c,l,mid);
	else tr[u].rs=update(tr[u].rs,x,c,mid+1,r);
    tr[u].v=std::max(tr[tr[u].ls].v,tr[tr[u].rs].v);
	return u;
}

int query(int p,int l,int r,int pl,int pr){
    if(l>=pl and r<=pr) return tr[p].v;
    int mid=(l+r)>>1;
    int res=0;
    if(pl<=mid) res=std::max(res,query(tr[p].ls,l,mid,pl,pr));
    if(pr>mid) res=std::max(res,query(tr[p].rs,mid+1,r,pl,pr));
    return res; 
}

void solve(){
    int n;
    std::cin>>n;
    idx=0;
    root[0]=build(0,n);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::stack<int> stk;
    for(int i=1;i<=n;i++){
        int res=query(root[i-1],0,n,0,a[i])+1;
        while(stk.size() and a[stk.top()]<=a[i]) stk.pop();
        if(stk.size()) res=std::max(res,query(root[stk.top()],0,n,0,a[i])+2);
        stk.push(i);
        root[i]=update(root[i-1],a[i],res,0,n);
    }
    std::cout<<tr[root[n]].v<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
