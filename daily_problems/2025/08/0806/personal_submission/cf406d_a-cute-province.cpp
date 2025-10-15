#include <bits/stdc++.h>
#include <vector>
#include <numeric>
#include <algorithm>
struct Point {
    long long x, y;
};


const int MAXN = 100005;
const int LOGN = 18; 

Point hills[MAXN];
int next_hill[MAXN];
std::vector<int> g[MAXN];
int dep[MAXN], fa[MAXN][20];
void dfs(int u, int father){
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	for(int i =1 ; i <= 19; i ++){
		fa[u][i] = fa[fa[u][i-1]][i-1];
	}
	for(auto v : g[u]){
		if(v != father)
		dfs(v, u);
	}
	
}
int lca(int u, int v){
	if(dep[u] < dep[v])std::swap(u, v);
	for(int i = 19; i >= 0; i --){
		if(dep[fa[u][i]] >= dep[v])u = fa[u][i];
	}
	if(u == v)return v;
	for(int i = 19; i >= 0; i --){
		if(fa[u][i] != fa[v][i])
		u = fa[u][i], v = fa[v][i];
	}
	return fa[u][0];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
        std::cin >> hills[i].x >> hills[i].y;
    }
    std::vector<int> st; 
    for (int i = n; i >= 1; --i) {
        while (st.size() >= 2) {
            int j1 = st.back();
            int j2 = st[st.size() - 2];
            // 比较坡度: 如果从 i 到 j1 的坡度小于等于到 j2 的坡度，
            // 说明 j1 被 j2 "遮挡"，则 j1 出栈
            if ((long long)(hills[j1].y - hills[i].y) * (hills[j2].x - hills[i].x) < 
                (long long)(hills[j2].y - hills[i].y) * (hills[j1].x - hills[i].x)) {
                st.pop_back();
            } else {
                break;
            }
        }

        if (st.empty()) {
            next_hill[i] = i; // 右边没有可见的山丘，停在原地
        } else {
            next_hill[i] = st.back();
        }
        st.push_back(i); // 将当前山丘压入栈
    }
    for(int i =1 ; i <= n; i ++)g[next_hill[i]].emplace_back(i) ;
    dfs(n, 0);
    int m;
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        std::cout << lca(u, v) << ' ';
    }
    std::cout << std::endl;

    return 0;
}
