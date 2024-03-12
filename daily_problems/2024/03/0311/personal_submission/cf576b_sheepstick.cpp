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
    vector<int> p(n);
    for (auto &pi : p){
    	cin >> pi;
    	pi--;
    }
    //check fixed point
    for (int i = 0; i < n; i++){
    	if (p[i] == i){
    		cout << "YES\n";
    		for (int j = 0; j < n; j++) if (j != i){
    			cout << p[j] + 1 <<" "<< i + 1 << "\n";
    		}	
    		return;
    	}
    }

    vector<int> visited(n, 0);
    vector<vector<int>> groups;
    bool edge = false, odd = false;
    int f = -1, s = -1;
    for (int i = 0; i < n; i++){
    	if(!visited[i]){
    		vector<int> cur;
    		int j = i;
    		while(!visited[j]){
    			cur.push_back(j);
    			visited[j] = 1;
    			j = p[j];
    		}
    		int sz = cur.size();
    		if (sz % 2) odd = true;
    		if (sz == 2 && f == -1){
    			edge = true;
    			f = cur[0];
    			s = cur[1];
    		}
    		groups.push_back(cur);
    	}
    }

    if (!edge || odd){
    	cout << "NO\n";
    	return;
    }
    cout << "YES\n";
    cout << f + 1 <<" "<< s + 1 << "\n";
    for (auto &v : groups){
    	int sz = v.size();
    	for (int i = 0; i < sz && v[0] != f; i++){
    		if (i % 2){
    			cout << s + 1 <<" "<< v[i] + 1 << "\n";
    		}
    		else cout << f + 1 <<" "<< v[i] + 1 << "\n";
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
