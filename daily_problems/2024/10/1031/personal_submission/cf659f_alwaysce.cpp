#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> size;
    vector<bool> has_c;

    DSU(int n_cells) : parent(n_cells), size(n_cells, 1), has_c(n_cells, false) {
        for(int i = 0; i < n_cells; ++i) parent[i] = i;
    }

    int find_set(int u) {

    }

    void union_set(int u, int v) {

    }
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
	仓库是一个n行m列的矩阵a
	i行j列的格子有一个正整数a[i][j]
	
	对于每个a[i][j] 可以减去一个正整数b[i][j]
	要求 0<=b[i][j] <= a[i][j]
	
	
	需要使得最终状态下
	所有a[i][j] > 0的格子形成一个连通块
	a[i][j]的取值相同
	所有的格子求和 = k
	至少有一个a[i][j] > 0的格子没有改变
	
	1<=n,m<=1000, 1<=k<=1e18, 1<=a[i][j]<=1e9
	
	提示：Iterate over the final non-zero number.
	所以枚举最终希望保留的a[i][j], 它得满足 
	k % a[i][j] == 0, cnt = (k / a[i][j])
	连通分量大小 = cnt, 
	从(i,j)出发的连通块内其他元素都应该>=a[i][j]才能够操作
	那么从(i,j)出发的连通分量大小决定了(i,j)是否可能成为最终保留的点
	*/
    int n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    // 按值降序排序
    vector<tuple<int, int, int>> cells; // (a[i][j], i, j)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cells.emplace_back(a[i][j], i, j);
        }
    }
    sort(cells.begin(), cells.end(), [&](const tuple<int,int,int> &a, const tuple<int,int,int> &b) -> bool {
        if(get<0>(a) != get<0>(b)) return get<0>(a) > get<0>(b);
        if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
        return get<2>(a) < get<2>(b);
    });

    int total_cells = n * m;
    DSU dsu(total_cells);

    // 记录当前取值的位置是否被使用
    vector<vector<bool>> active(n, vector<bool>(m, false));
    vector<pair<int, int>> dirs = { {-1,0},{1,0},{0,-1},{0,1} };

    i64 result_c = -1;
    int result_root = -1;

    for(auto &[c, i, j] : cells){
        active[i][j] = true;
        int u = i * m + j;
        if(a[i][j] == c){
            dsu.has_c[u] = true;
        }

        for(auto &[di, dj] : dirs){
            int ni = i + di, nj = j + dj;
            if(ni >=0 && ni < n && nj >=0 && nj < m && active[ni][nj]){
                int v = ni * m + nj;
                dsu.union_set(u, v);
            }
        }

        int pu = dsu.find_set(u);
        if(dsu.has_c[pu]){
            if(k % c == 0){
                i64 cnt = k / c;
                if(dsu.size[pu] >= cnt){
                    result_c = c;
                    result_root = pu;
                    break;
                }
            }
        }
    }

    if(result_c == -1){
        cout << "NO";
        return 0;
    }

    // 需要找到一个大小为 cnt 的连通块，并且其中至少一个格子原值等于 c
    i64 cnt = k / result_c;
    vector<pair<int, int>> start_cells;

    for(int idx = 0; idx < n*m; idx++){
        if(dsu.find_set(idx) == result_root){
            int i = idx / m;
            int j = idx % m;
            if(a[i][j] == result_c){
            	start_cells.emplace_back(i, j);
            	break;
        	}
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<pair<int, int>> selected;
    
    pair<int, int> start = start_cells[0];
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while(!q.empty() && (i64)selected.size() < cnt){
        auto [x, y] = q.front();
        q.pop();
        selected.emplace_back(x, y);
        
        for(auto &[di, dj] : dirs){
            int ni = x + di, nj = y + dj;
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !visited[ni][nj] && a[ni][nj] >= result_c && dsu.find_set(ni * m + nj) == result_root){
                visited[ni][nj] = true;
                q.push({ni, nj});
                if((i64)(selected.size() + q.size()) >= cnt) {
                	break;
                }
            }
        }
    }

    selected.resize(cnt);

    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(auto &[x, y] : selected){
        ans[x][y] = result_c;
    }
	
	cout << "YES\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << ans[i][j] << (j == m-1 ? '\n' : ' ');
        }
    }

    return 0;
}
