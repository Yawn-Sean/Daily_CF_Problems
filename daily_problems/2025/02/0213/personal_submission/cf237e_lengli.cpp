/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

namespace dinic{
	const int N=1e5+7,M=2e6+7;
	const int INF=1e9;
	int n,S,T;
	int head[N],ver[M],nex[M],tot,cur[N];
	int dist[N],edge[M],cost[M],maxflow,mincost;
	bool vis[N];
	
	inline void add(int x,int y,int z,int c=0,bool o=1){
		ver[tot]=y;
		edge[tot]=z;
		cost[tot]=c;
		nex[tot]=head[x];
		head[x]=tot++;
		if(o) add(y,x,0,-c,0);
	}
	inline bool spfa(){
		for(int i=1;i<=n;i++) dist[i]=INF;
		memset(vis,0,sizeof vis);
		std::queue<int> q;
		q.push(S);
		dist[S]=0,vis[S]=1;
		while(q.size()){
			auto x=q.front();
			q.pop();
			vis[x]=0;
			for(int i=head[x];~i;i=nex[i]){
				int y=ver[i];
				int z=edge[i],c=cost[i];
				if(dist[y]<=dist[x]+c or !z) continue;
				dist[y]=dist[x]+c;
				if(!vis[y]) q.push(y),vis[y]=1;
			}
		}
		return dist[T]!=INF;
	}
	int dfs(int x,int flow=INF){
		if(x==T) return flow;
		int ans=0,k,i;
		vis[x]=1;
		for(int i=cur[x];~i and flow;i=nex[i]){
			cur[x]=i;
			int y=ver[i];
			int z=edge[i],c=cost[i];
			if(!z or (dist[y]!=dist[x]+c) or vis[y]) continue;
			k=dfs(y,std::min(flow,z));
			if(!k) dist[y]=INF;
			edge[i]-=k;
			edge[i^1]+=k;
			ans+=k;
			mincost+=k*c;
			flow-=k;
		}
		vis[x]=0;
		return ans;
	}
	inline void main(){
		while(spfa()){
			for(int i=1;i<=n;i++){
				cur[i]=head[i];
			}
			int now;
			while((now=dfs(S,INF))) maxflow+=now;
		}
	}
	inline void init(int _n,int _S,int _T){
		n=_n,S=_S,T=_T;
		tot=0,maxflow=0,mincost=0;
		memset(head,-1,sizeof head);
	}
}

void solve(){
    std::string str;
    std::cin>>str;
    int n;
    std::cin>>n;
    int S=1000,T=2000;
    dinic::init(T+10,S,T);
    std::vector<int> cnt(30,0);
    for(auto x:str){
        cnt[x-'a']++;
    }
    for(int i=0;i<26;i++){
        dinic::add(n+i+1,T,cnt[i],0);
    }
    for(int i=1;i<=n;i++){
        std::string tmp;
        std::cin>>tmp;
        int k;
        std::cin>>k;
        dinic::add(S,i,k,0);
        std::fill(all(cnt),0);
        for(auto x:tmp) cnt[x-'a']++;
        for(int j=0;j<26;j++){
            dinic::add(i,n+j+1,cnt[j],i);
        }
    }
    dinic::main();
    if(dinic::maxflow!=str.size()) std::cout<<"-1"<<"\n";
    else std::cout<<dinic::mincost<<"\n";
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
