#include<bits/stdc++.h>
using namespace std;

#ifdef LOCAL
char DEBUG_BUFFER[1000];
#define debug(...) {sprintf(DEBUG_BUFFER,##__VA_ARGS__);\
cerr<<"\033[1;36m"<<DEBUG_BUFFER<<"\033[0;2m"<<"\033[0m";\
fflush(stderr);}
#define s S.c_str()
char TEST_GEN[1000],TEST_ANS[1000],TEST_OUT[1000],TEST_FC[1000];
void TEST(string S){
	sprintf(TEST_GEN,"%s_gen.exe > %s_input.txt",s,s);
	sprintf(TEST_ANS,"%s_sol.exe < %s_input.txt > %s_ans.txt",s,s,s);
	sprintf(TEST_OUT,"%s.exe < %s_input.txt > %s_out.txt",s,s,s);
	sprintf(TEST_FC,"fc %s_ans.txt %s_out.txt /n",s,s);
	while(1){
		debug("gen\n"); system(TEST_GEN);
		debug("ans\n"); system(TEST_ANS);
		debug("out\n"); system(TEST_OUT);
		if(system(TEST_FC)) break;
	}
}
#undef s
#else
#define debug(...) ;
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
int rand(int l,int r){return rng()%(r-l+1)+l;}

void solve(){
	int n,sb,m;
	cin>>n>>sb>>m;
	vector<vector<int>>e(n+1);
	vector<int>ck(m);
	{
		int last=1;
		for(auto& x:ck){
			cin>>x;
			if(last!=x){
				e[last].push_back(x);
				e[x].push_back(last);
			}
			last=x;
		}
	}
	for(int u,v;sb--;){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	vector<int>dis(n+1);
	dis[1]=1;
	queue<int>p;
	p.push(1);
	while(p.size()){
		int u=p.front();
		p.pop();
		for(auto& v:e[u]){
			if(dis[v]) continue;
			dis[v]=dis[u]+1;
			p.push(v);
		}
	}
	for(int i=1;i<m;++i){
		if(dis[ck[i]]<=dis[ck[i-1]]){
			cout<<"-1\n";
			return;
		}
	}
	bool skip=(ck[0]==1);
	cout<<(m-skip)<<'\n';
	int last=1;
	for(int i=skip;i<m;++i){
		const int& x=ck[i];
		if(last!=x){
			cout<<last<<' '<<x<<'\n';
		}
		last=x;
	}
}
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int t; cin>>t;
	while(t--) solve();
	return 0;
}
