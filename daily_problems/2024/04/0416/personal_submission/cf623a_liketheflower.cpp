// submission link: https://codeforces.com/contest/623/submission/256982569
#include<iostream>
#include<vector>
using namespace std;

const int BLACK = 0, WHITE = 1, UNCOLORED = -1;
bool dfs(int i, const vector<vector<int>>& reversed_graph, vector<int>& colors){ 
    for (auto j: reversed_graph[i]){
	if (colors[j] == UNCOLORED){
	    colors[j] = 1 - colors[i]; /*flip the color */
	    auto ret = dfs(j, reversed_graph, colors);
	    if (!ret){
		return false;
	    }
    } else {
	    if (colors[j] == colors[i]){
		return false;
	    }
	}
    }
    return true;
}
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>cnt(n, 0 );
    int u, v;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i){
	cin >> u >> v;
	--u, --v;
	graph[u][v] = 1;
	graph[v][u] = 1;
    }
    vector<vector<int>> reversed_graph(n);
    for (int i = 0; i < n - 1; ++i){
	for (int j = i +1; j <n ;++j){
	    if (graph[i][j] == 0){
		reversed_graph[i].push_back(j);
		reversed_graph[j].push_back(i);
	    }
	}
    }
    vector<int> colors(n, UNCOLORED);
    for (int i = 0; i < n; ++i){
	if (colors[i] == UNCOLORED && reversed_graph[i].size() > 0){
	    colors[i] = BLACK;
	    auto good = dfs(i, reversed_graph, colors);
	    if (!good){
		cout << "NO\n";
		return 0;
	    }
	}
    }
    for (int i = 0; i < n; ++i){
	for (int j = i + 1; j < n; ++j){
	    if (graph[i][j] == 1){
		if (colors[i] == colors[j] || colors[j] == UNCOLORED || colors[i] == UNCOLORED)continue;
		cout << "NO\n";
		return 0;
	    }
	}
    }
    cout << "YES\n";
    for (auto c: colors){
	if (c == UNCOLORED){
	    cout << 'b';
    } else {
	    cout << (c == BLACK ? 'a' : 'c');
	}
    }
    cout << '\n';
    return 0;
}
