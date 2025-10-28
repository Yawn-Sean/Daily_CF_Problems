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

int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n;
	cin>>n;
	vector<ai2>a;
	if(n&1){
		/*
		4 3
		-20 21
		0 0
		*/
		a={{4,3},{-20,21},{0,0}};
		if(n>=5){
			int l=1,x=0,y=0;
			x+=3,y-=4;
			a.push_back({x,y});
			if(n>5){
				for(int t=(n-5)/2;t--;){
					++l;
					x-=4,y-=3;
					a.push_back({x,y});
					x+=3,y-=4;
					a.push_back({x,y});
				}
			}
			x+=4*l,y+=3*l;
			a.push_back({x,y});
		}
	}
	else{
		/*
		(0,0)
		(3,4)
		(-1,7)
		(-4,3)
		*/
		a={{0,0},{3,4}};
		int l=1,x=3,y=4;
		for(int t=(n-4)/2;t--;){
			++l;
			x+=4,y-=3;
			a.push_back({x,y});
			x+=3,y+=4;
			a.push_back({x,y});
		}
		x-=4*l,y+=3*l;
		a.push_back({x,y});
		a.push_back({-4,3});
	}
	for(auto& [x,y]:a){
		cout<<x<<' '<<y<<'\n';
	}
	return 0;
}
