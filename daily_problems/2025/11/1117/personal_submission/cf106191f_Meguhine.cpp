#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
namespace __rb_tree{
	using namespace __gnu_pbds;
	template<class Key,class Mapped=null_type,class Cmp=std::less<Key>>
	using rb_tree=tree<Key,Mapped,Cmp,rb_tree_tag,tree_order_statistics_node_update>;
}
using __rb_tree::rb_tree;

namespace __multi_rb_tree{
	using namespace __gnu_pbds;
	template<class T,class Cmp=std::less<T>>
	struct CmpWrapper{
		bool operator()(const std::pair<T,int>& a,const std::pair<T,int>& b) const{
			if(Cmp{}(a.first,b.first)) return 1; // a.T < b.T
			if(Cmp{}(b.first,a.first)) return 0; // b.T < a.T
			return a.second<b.second; // a.T == b.T
		}
	};
	template<class Key,class Mapped=null_type,class Cmp=std::less<Key>>
	class multi_rb_tree{
		rb_tree<std::pair<Key,int>,Mapped,CmpWrapper<Key,Cmp>>rbt;
		int count;
	public:
		multi_rb_tree():count(0){}
		void insert(const Key& x){
			rbt.insert({x,count++});
		}
		void erase(const Key& x){
			auto it=rbt.lower_bound({x,0});
			while(it!=rbt.end() && it->first==x){
				it=rbt.erase(it);
			}
		}
		void extract(const Key& x){
			auto it=rbt.lower_bound({x,0});
			if(it!=rbt.end() && it->first==x){
				rbt.erase(it);
			}
		}
		int order_of_key(const Key& x){
			return rbt.order_of_key({x,0});
		}
		Key find_by_order(int x){
			
		}
		bool empty(){ return rbt.empty(); }
		std::size_t size(){ return rbt.size(); }
	};
}
using __multi_rb_tree::multi_rb_tree;

#include<ext/pb_ds/assoc_container.hpp>
namespace __hash_table{
	using namespace __gnu_pbds;
	template<class Key,class Mapped=null_type,class Hash=std::hash<Key>>
	using hash_table=gp_hash_table<Key,Mapped,Hash>;
}
using __hash_table::hash_table;

using namespace std;
using __gnu_pbds::null_type;

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
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n; cin>>n;
	LL s=0; int t=0;
	hash_table<LL,multi_rb_tree<int>>mp;
	mp[0].insert(0);
	LL ans=0;
	for(int i=0,x;i<n;++i){
		cin>>x;
		s+=x;
		if(x>0) --t;
		else ++t;
		dbg(s,t,mp[s].order_of_key(t+1));
		ans+=mp[s].order_of_key(t+1);
		mp[s].insert(t);
	}
	cout<<ans;
	return 0;
}
