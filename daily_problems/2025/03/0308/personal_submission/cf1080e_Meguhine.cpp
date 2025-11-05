#ifdef __FUCK_GCC
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("inline","fast-math","unroll-loops")
#endif
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
template<typename T>inline bool updmx(T& x,const T& y){return x<y?x=y,1:0;}
template<typename T>inline bool updmn(T& x,const T& y){return y<x?x=y,1:0;}
template<typename T>inline void clr(T& x){T().swap(x);}

mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());
LL rand(LL l,LL r){return rng()%(r-l+1)+l;}

// 0-based-index, dx[i]=radius, which is [i to right]
// d1, i is center
// d2, between (i-1) and i is center
void manacher(auto&& s,auto&& d1,auto&& d2){
	const int& n=s.size();
	d1.assign(n,0);
	for(int i=0,l=0,r=-1;i<n;++i){
		int k=(i>r)?1:min(d1[l+r-i],r-i+1);
		while(i-k>=0 && i+k<n && s[i-k]==s[i+k]){
			++k;
		}
		d1[i]=k--;
		if(i+k>r){
			l=i-k,r=i+k;
		}
	}
	d2.assign(n,0);
	for(int i=0,l=0,r=-1;i<n;++i){
		int k=(i>r)?0:min(d2[l+r-i+1],r-i+1);
		while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]){
			++k;
		}
		d2[i]=k--;
		if(i+k>r){
			l=i-k-1,r=i+k;
		}
	}
}

using ALH=array<LL,2>; // array-LL-Hash
namespace HC{ // Hash Const
	const int MOD[4]={(int)(1e9+7),998244353};
}
ALH operator +(const ALH& A,const ALH& B){
	static ALH res;
	for(int i=0;i<2;i++){
		res[i]=(A[i]+B[i])%HC::MOD[i];
	}
	return res;
}
ALH operator -(const ALH& A,const ALH& B){
	static ALH res;
	for(int i=0;i<2;i++){
		res[i]=((A[i]-B[i])%HC::MOD[i]+HC::MOD[i])%HC::MOD[i];
	}
	return res;
}

ALH tab[26];
using B=bitset<26>;
struct Row{
	B b;
	ALH h;
	Row(){init();}
	void init(){
		b.reset();
		h=ALH{0,0};
	}
	void add(const char& c){
		const int& x=c-'a';
		b.flip(x);
		h=h+tab[x];
	}
	void del(const char& c){
		const int& x=c-'a';
		b.flip(x);
		h=h-tab[x];
	}
	bool ok() const{
		return b.count()<=1;
	}
};

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	for(int i=0;i<26;++i){
		for(int j=0;j<2;++j){
			tab[i][j]=rng()%HC::MOD[j];
		}
	}
	int n,m;
	cin>>n>>m;
	vector<string>s(n);
	for(auto& t:s) cin>>t;
	vector<Row>opt(n);
	vector<vector<ALH>>t;
	vector<int>d1,d2;
	LL ans=0;
	for(int len=1;len<=m;++len){
		for(int i=0;i<n;++i){
			opt[i].init();
			for(int j=0;j<len;++j){
				opt[i].add(s[i][j]);
			}
		}
		for(int r=len-1;;){
			t={{}};
			const int l=r-len+1;
			for(int i=0;i<n;++i){
				if(opt[i].ok()){
					t.back().emplace_back(opt[i].h);
				}
				else{
					if(t.back().size()){
						t.push_back({});
					}
				}
			}
			for(auto& v:t){
				if(v.empty()) continue;
				manacher(v,d1,d2);
				const int& k=v.size();
				for(int i=0;i<k;++i){
					ans+=d1[i]+d2[i];
				}
			}
			if(++r<m);
			else break;
			for(int i=0;i<n;++i){
				opt[i].del(s[i][l]);
				opt[i].add(s[i][r]);
			}
		}
	}
	cout<<ans;
	return 0;
}
