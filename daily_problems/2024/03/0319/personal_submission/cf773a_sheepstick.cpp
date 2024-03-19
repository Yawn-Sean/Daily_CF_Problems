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
    i64 x, y, p, q; cin >> x >> y >> p >> q;

    if (p == 0){
    	if (x == 0) cout << "0\n";
    	else cout << "-1\n";
    	return;
    }

    if (p == q){
    	if (x < y) cout << "-1\n";
    	else cout << "0\n";
    	return;
    }

    i64 l = 1, r = 2E9;
    while(l < r){
    	i64 m = (l + r) / 2;
    	i64 np = p * m, nq = q * m;
    	bool ok = false;
    	if (nq >= y && np >= x && np - x <= nq - y) ok = true;
    	if (ok){
    		r = m;
    	}
    	else l = m + 1;
    }
    cout << q * l - y << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}
