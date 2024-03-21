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
    vector<double> p(n), v(n);
    for (auto &pi : p){
    	cin >> pi;
    }
    for (auto &vi : v){
    	cin >> vi;
    }

    auto gao = [&](double lim) -> bool {
    	double L = -2E18, R = 2E18;
    	for (int i = 0; i < n; i++){
    		double cL = p[i] - v[i] * lim, cR = p[i] +  v[i] * lim;
    		if (cL > R || cR < L) return false;
    		L = max(L, cL);
    		R = min(R, cR);
    	}
    	return true;
    };

    double l = 0, r = 1E9;
    for (int i = 0; i < 150; i++){
    	double m = (r + l) / 2;
    	if (gao(m)) r = m;
    	else l = m;
    }
    cout << fixed << setprecision(10) << l << "\n";
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
