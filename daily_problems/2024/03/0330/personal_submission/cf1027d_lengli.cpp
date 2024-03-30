const int N=200010;

struct Tarjan{
    vector<int> eg[N];
    int dfn[N],low[N],timespace;
    int stk[N],top;
    bool st[N];
    int color[N];
    int scc_cnt,n;
    vector<int> scc[N];
    void init(int x){
        timespace=1;scc_cnt=0;
        top=0;
        n=x;
        for(int i=1;i<=n;i++) eg[i].clear(),scc[i].clear();
        for(int i=1;i<=n;i++){
        	dfn[i]=0,low[i]=0;
        	color[i]=0;
        }
    }
    void add(int a,int b){
        eg[a].push_back(b);
    }
    void dfs(int u){
		low[u]=dfn[u]=++timespace;
		stk[++top]=u;
		st[u]=1;
		for(auto v:eg[u]){
			if (!dfn[v]){
				dfs(v);
				low[u]=min(low[u],low[v]);
			}else if(st[v]) low[u]=min(low[u],low[v]);
		}
		if(dfn[u]==low[u]){
			scc_cnt++;
			int y;
			while (y=stk[top--])
			{
				scc[scc_cnt].push_back(y);
				color[y]=scc_cnt;
				st[y]=0;
				if (u==y) break;
			}
		}
	}
    void tarjan(){
        for(int i=1;i<=n;i++){
            if(!dfn[i]) dfs(i);
        }
    }
}tj;

void solve(){
	int n;
	cin>>n;
	vector<int> c(n+1);
	for(int i=1;i<=n;i++) cin>>c[i];
	tj.init(n);
	int res=0;
	for(int i=1;i<=n;i++){
		int b;
		cin>>b;
		if(i==b) res+=c[i];
		tj.add(i,b);
	}
	tj.tarjan();
	for(int i=1;i<=tj.scc_cnt;i++){
		auto &t=tj.scc[i];
		if(t.size()>=2){
			int mi=2e9;
			for(auto x:t) mi=min(mi,c[x]);
			res+=mi;
		}
	}
	cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
