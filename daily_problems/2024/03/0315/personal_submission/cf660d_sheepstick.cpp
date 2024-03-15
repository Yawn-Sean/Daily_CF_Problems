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
    int n; cin >> n;
    vector<array<int,2>> p(n);
    for (int i = 0; i < n; i++){
    	cin >> p[i][0] >> p[i][1];
    }

    map<pair<int,int>, int> mp;
    for (int i = 0; i < n; i++){
    	for (int j = i + 1; j < n; j++){
    		mp[{p[i][0] + p[j][0], p[i][1] + p[j][1]}]++;
    	}
    }
    i64 res = 0;
    for (auto &[k, v] : mp){
    	res += 1LL * v * (v - 1) / 2;
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
