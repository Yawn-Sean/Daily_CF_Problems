#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>

using namespace std;
using i64 = long long;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++){
    	int u, v; cin >> u >> v;
    	u--; v--;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    deque<int> dq;
    vector<int> visited(n, 0);
    dq.push_back(0);
    visited[0] = 1;
    while(1){
    	auto u = dq.back();
    	bool found = false;
    	set<int> seen;
    	for (auto &v : adj[u]){
    		seen.insert(v);
    		if (!visited[v]){
    			visited[v] = 1;
    			dq.push_back(v);
    			found = 1;
    			break;
    		}
    	}
    	if (found) continue;
    	else {
    		while(!seen.count(dq.front())){
    			dq.pop_front();
    		}
    		cout << (int) dq.size() << "\n";
    		for (auto val : dq){
    			cout << val + 1 <<" ";
    		}
    		cout << "\n";
    		return;
    	}
    }
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}
