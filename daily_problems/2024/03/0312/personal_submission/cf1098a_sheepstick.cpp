#include <iostream>
#include <string>
#include <vector>
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
    int n; cin >> n;
    vector<vector<int>> child(n);
    vector<i64> val(n);
    for (int i = 1; i < n; i++){
    	int p; cin >> p;
    	p--;
    	child[p].push_back(i);
    }
    for (auto &vi : val){
    	cin >> vi;
    }

    bool ok = true;
    i64 tot = 0;

    auto dfs = [&](auto self, int u, int p, bool even) -> void {
    	if (!even){
    		for (auto &v : child[u]){
    			self(self, v, u, 1 ^ even);
    		}
    	}
    	else {
    		i64 fValue = val[p];
    		i64 mi = 1LL << 50;
    		for (auto &v : child[u]){
    			mi = min(mi, val[v]);
    		}
    		if (child[u].empty()) mi = fValue;
    		if (mi < fValue){
    			ok = false;
    		}
    		val[u] = mi;
    		for (auto &v : child[u]){
    			self(self, v, u, 1 ^ even);
    		}
    	}
    	tot += val[u] - (p == -1 ? 0 : val[p]);
    };
    dfs(dfs, 0, -1, 0);
    if (!ok){
    	cout << "-1\n";
    }
    else cout << tot << "\n";
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
