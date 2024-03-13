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
using pi = pair<int,int>;

void solve(){
    int n; cin >> n;
    vector<string> str(n);
    vector<int> strLen(n);
    vector<vector<int>> pos(n);
    for (int i = 0; i < n; i++){
    	cin >> str[i];
    	int len; cin >> len;
    	strLen[i] = (int) str[i].length();
    	for (int j = 0; j < len; j++){
    		int p; cin >> p;
    		p--;
    		pos[i].push_back(p);
    	}
    }
    vector<int> idx(n, 0);

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0;i < n; i++){
    	pq.push({pos[i][0], i});
    }
    string res;
    int cur = 0;
    while(!pq.empty()){
    	auto [st, i] = pq.top();
    	if (st > cur){
    		res.push_back('a');
    		cur++;
    	}
    	else {
    		if (st + strLen[i] <= cur){
    			pq.pop();
    			idx[i]++;
    			if (idx[i] >= (int) pos[i].size()) continue;
    			else {
    				pq.push({pos[i][idx[i]], i});
    			}
    		}
    		else {
    			res.push_back(str[i][cur - st]);
    			cur++;
    		}
    	}
    }
    cout << res << "\n";
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
