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
    vector<int> a(n);
    for (auto &ai : a){
    	cin >> ai;
    }
    i64 best = 0;
  
    auto gao = [&](int st) -> void {
    	i64 cur = 0;
    	for (int i = st; i < n; i += 2){
	    	if (i < n - 1) best = max(best, cur + abs(a[i] - a[i + 1]));
	    	if (i < n - 2){
	    		cur += abs(a[i] - a[i + 1]) - abs(a[i + 1] - a[i + 2]);
	    		if (cur < 0) cur = 0;
	    	}
    	}
    };
    gao(0);
    gao(1);
    cout << best << "\n";
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
