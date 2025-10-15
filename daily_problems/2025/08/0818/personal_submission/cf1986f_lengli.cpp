/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

constexpr int N=100010;

struct E_DCC{
	int n,cnt,cnt_edge;
	int dfn[N], low[N];
	std::vector<std::pair<int, int>> e[N];
	std::vector<std::vector<int>> ans;
	std::stack<int> st;
	std::vector<std::array<int,2>> bridge;
    int is_bridge[N];
    int col[N];
    int dcc_cnt;
	
	void init(int nn){
		n=nn,cnt_edge=cnt=0;
        dcc_cnt=0;
		st=std::stack<int>();
		ans.clear();bridge.clear();
		for(int i=1;i<=n;i++) {
			e[i].clear();
			dfn[i]=low[i]=0;
			is_bridge[i]=0;
		}
	}
	
	void add(int u,int v){
		cnt_edge++;
		e[u].push_back(std::make_pair(v, cnt_edge<<1));
		e[v].push_back(std::make_pair(u, cnt_edge<<1|1));
	}
	
	void dfs(int x, int las){
		low[x] = dfn[x] = ++cnt;
		st.push(x);
		for (auto i: e[x]){
			if (i.second == (las ^ 1)) continue;
			if (!dfn[i.first]){
				dfs(i.first, i.second);
				low[x] = std::min(low[x], low[i.first]);
				if(low[i.first]>dfn[x]){
                    bridge.push_back({x,i.first});
                    is_bridge[x]=1;
                    is_bridge[i.first]=1;
                }
			}else low[x] = std::min(low[x], dfn[i.first]);
		}
		if (dfn[x] == low[x]){
			std::vector<int> vec;
			vec.push_back(x);
			while (st.top() != x){
				vec.push_back(st.top());
                col[st.top()]=dcc_cnt;
				st.pop();
			}
            col[x]=dcc_cnt;
			st.pop();
			ans.push_back(vec);
            dcc_cnt++;
		}
	}
	
	void tarjan(){
		for(int i=1;i<=n;i++) 
			if(!dfn[i]) dfs(i,0);
	}
}tj;


void solve(){
    int n,m;
    std::cin>>n>>m;
    tj.init(n);
    std::vector<std::array<int,2>> edge(m);
    for(auto &[x,y]:edge){
        std::cin>>x>>y;
        tj.add(x,y);
    }

    tj.tarjan();

    std::vector<std::vector<int>> eg(n+2);
    for(auto [x,y]:edge){
        x=tj.col[x],y=tj.col[y];
        if(x==y) continue;
        eg[x].pb(y);
        eg[y].pb(x);
    }

    i64 res=0;

    auto dfs=[&](auto self,int u,int fa)->int{
        int sz=tj.ans[u].size();
        for(auto x:eg[u]){
            if(x==fa) continue;
            auto k=self(self,x,u);
            res=std::max(res,1ll*k*(n-k));
            sz+=k;
        }

        return sz;
    };
    
    dfs(dfs,0,-1);

    std::cout<<(1ll*(n-1)*n/2)-res<<"\n";
}

signed main(){
    fastio;
    
    int T;
    std::cin>>T;
    while(T--) solve();
    
    return 0;
}
