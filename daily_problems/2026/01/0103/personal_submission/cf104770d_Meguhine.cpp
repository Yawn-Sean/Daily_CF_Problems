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

void read(auto&& e,auto&& edge,const int m){
	for(int i=0,u,v;i<m;++i){
		cin>>u>>v;
		if(u==1) edge[v]=1;
		else e[u].emplace_back(v);
		if(v==1) edge[u]=1;
		else e[v].emplace_back(u);
	}
}

void adjust(auto&& e,auto&& edge,auto&& seq,const int n){
	for(int u=2;u<n;++u){
		for(auto v:e[u]){
			if(v<u) continue;
			seq.push_back(ai3{1,u,v});
			edge[u]=edge[u]^1;
			edge[v]=edge[v]^1;
		}
	}
}


int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m1,m2;
	cin>>n>>m1>>m2;
	vector<vector<int>>e1(n+1),e2(n+1);
	vector<bool>edge1(n+1),edge2(n+1);
	read(e1,edge1,m1);
	read(e2,edge2,m2);
	vector<ai3>seq1,seq2;
	adjust(e1,edge1,seq1,n);
	adjust(e2,edge2,seq2,n);
	if(edge1!=edge2){
		cout<<"NO\n";
		return 0;
	}
	cout<<"YES\n";
	cout<<(seq1.size()+seq2.size())<<'\n';
	for(auto [x,y,z]:seq1) cout<<x<<' '<<y<<' '<<z<<'\n';
	reverse(all(seq2));
	for(auto [x,y,z]:seq2) cout<<x<<' '<<y<<' '<<z<<'\n';
	return 0;
}
