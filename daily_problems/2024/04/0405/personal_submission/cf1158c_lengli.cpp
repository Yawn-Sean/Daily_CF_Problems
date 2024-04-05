/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back
#pragma GCC optimize(fast)

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=500010;

int n;

struct segment_tree_graph{
	int cnt=0,cntin=0;
	int root_in,root_out;
	int in[N],out[N];
    array<int,2> tr[N*10];
	int h[N*10],e[N*20],ne[N*20],idx;
    int rd[N*10],st[N*10];

    void add_edge(int a,int b,int c){
        e[idx]=b,ne[idx]=h[a],h[a]=idx++;
        rd[b]++;
    }
    void build_in_tree(int u,int l,int r){
        if(l==r){
            in[l]=u;
            st[u]=1;
            cnt=max(cnt,u);
            return;
        }
        int mid=(l+r)/2;
        build_in_tree(u*2,l,mid);
        build_in_tree(u*2+1,mid+1,r);
        tr[u]={u*2,u*2+1};
        add_edge(u*2,u,0);
        add_edge(u*2+1,u,0);
    }
    void build_out_tree(int u,int l,int r){
        if(l==r){
            out[l]=u;
            return;
        }
        int mid=(l+r)/2;
        int ls=++cnt,rs=++cnt;
        build_out_tree(ls,l,mid);
        build_out_tree(rs,mid+1,r);
        tr[u]={ls,rs};
        add_edge(u,ls,0);
        add_edge(u,rs,0);
    }
	void build(int l,int r){
        root_in=++cnt;
		build_in_tree(root_in,l,r);
        cntin=cnt,root_out=++cnt;
        build_out_tree(root_out,l,r);
        for(int i=1;i<=n;i++) add_edge(out[i],in[i],0);
	}
	
	void link(int u,int l,int r,int pl,int pr,int x,int w,int flag){
		if(l>=pl and r<=pr){
			if(flag) add_edge(x,u,0);
			else add_edge(u,x,0);
			return;
		}
		int mid=(l+r)/2;
		if(pl<=mid) link(tr[u][0],l,mid,pl,pr,x,w,flag);
		if(pr>mid) link(tr[u][1],mid+1,r,pl,pr,x,w,flag);
	}
	
	void modify(int l1,int r1,int l2,int r2,int w){
		int nt=++cnt;
        link(root_in,1,n,l1,r1,nt,w,0);
		link(root_out,1,n,l2,r2,nt,w,1);
		
	}
	void clear(){
		for(int i=0;i<=cnt;i++){
			tr[i]={0,0};
			in[i]=out[i]=0;
			h[i]=-1;
            rd[i]=0,st[i]=0;
		}
		idx=0,cnt=0;root_in=root_out=0;
	}
}tr;

int ne[N];

void solve(){
    cin>>n;
    tr.build(1,n);
    for(int i=1;i<=n;i++) cin>>ne[i];
    for(int i=1;i<=n;i++){
        if(ne[i]==-1) continue;
        if(ne[i]>i+1) tr.modify(i,i,i+1,ne[i]-1,0);
        if(ne[i]<=n) tr.modify(ne[i],ne[i],i,i,0);
    }
    queue<int> q;
    int k=n;
    vector<int> res(n+1);
    for(int i=1;i<=tr.cnt;i++){
        if(!tr.rd[i]) q.push(i);
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        if(tr.st[t]) tr.st[t]=k--;
        for(int i=tr.h[t];~i;i=tr.ne[i]){
            int x=tr.e[i];
            tr.rd[x]--;
            if(!tr.rd[x]) q.push(x);
        }
    }
    if(k!=0) cout<<-1;
    else for(int i=1;i<=n;i++) cout<<tr.st[tr.in[i]]<<" ";
    cout<<endl;
    tr.clear();
}

signed main(){
    fastio;
    for(int i=0;i<N*8;i++) tr.h[i]=-1;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
