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

struct Edge{
	int v,w,nxt;
	bool vis;
};
struct Node{
	LL d; int u;
	friend bool operator <(const Node& A,const Node& B){
		return A.d>B.d;
	}
};
int main(){
#ifndef LOCAL
	cin.tie(nullptr)->sync_with_stdio(false);
#endif
	int n,m,K;
	cin>>n>>m>>K;
	vector<Edge>e(2);
	vector<int>h(n+1);
	auto addedge=[&](int u,int v,int w)->void{
		e.emplace_back(v,w,h[u],0);
		h[u]=e.size()-1;
	};
	for(int i=0,u,v,w;i<m;++i){
		cin>>u>>v>>w;
		addedge(u,v,w);
		addedge(v,u,w);
	}
	const LL inf=1e17;
	vector<LL>dis(n+1,inf);
	priority_queue<Node>q;
	q.push({dis[1]=0,1});
	vector<int>opt;
	while(q.size()){
		auto [du,u]=q.top();
		q.pop();
		if(du!=dis[u]) continue;
		for(int i=h[u];i;i=e[i].nxt){
			if(!e[i].vis){
				e[i].vis=e[i^1].vis=1;
				opt.push_back(e[i].w);
			}
			if(updmn(dis[e[i].v],du+e[i].w)){
				q.emplace(dis[e[i].v],e[i].v);
			}
		}
	}
	sort(all(opt));
	if(opt.size()>K) opt.resize(K);
	cout<<min(accumulate(all(opt),0ll),dis[n]);
	return 0;
}
