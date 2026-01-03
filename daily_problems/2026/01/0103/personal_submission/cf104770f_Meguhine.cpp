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

/*
origin array contains of distinct integers
which simplifies the problem
assume node->lson_value <= node->rson_value
assign values like fenwick tree
*/
void dfs(int u,int x,int l,int r,vector<int>& buc){
	if(l==r){
		buc[l-1]=x;
		return;
	}
	int mid=(l+r)>>1;
	dfs(u<<1,x+1,l,mid,buc);
	dfs(u<<1|1,1,mid+1,r,buc);
}
int lowbit(int x){ return x&(-x); }

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	map<int,int>cnt;
	for(int i=0,x;i<n;++i){
		cin>>x;
		++cnt[x];
	}
	const int p=__lg(n+1);
	const int m=1<<(p-1);
	vector<int>buc(m);
	dfs(1,1,1,m,buc);
	vector<vector<int>>e(m);
	for(int u=1;u<m;++u){
		e[u-lowbit(u)].emplace_back(u);
	}
	vector<vector<int>>q(p+1);
	q[p]={0};
	vector<int>ans(m);
	for(auto& [x,c]:cnt){
		if(c>p || q[c].empty()){
			cout<<"-1\n";
			exit(0);
		}
		const int u=q[c].back();
		q[c].pop_back();
		ans[u]=x;
		for(auto v:e[u]){
			q[buc[v]].emplace_back(v);
		}
	}
	for(auto x:ans) cout<<x<<' ';
	return 0;
}
