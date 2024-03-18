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

struct PT {
	int x, y;
	PT() : x(0), y(0) {}
	PT(int xx, int yy) : x(xx), y(yy) {}
	PT operator-(const PT &o) const { return PT(x-o.x, y-o.y); }
	i64 cross(const PT &o) const { return 1ll*x*o.y - 1ll*y*o.x; }
	i64 dot(const PT &o) const { return 1ll*x*o.x + 1ll*y*o.y; }
	i64 len2() { return dot(*this); }
	double len() { return sqrt(len2()); }
};


void solve(){
    int n; cin >> n;
    vector<PT> p;
    for (int i = 0; i < n; i++){
    	int x, y; cin >> x >> y;
    	p.push_back(PT(x, y));
    }

    double res = std::numeric_limits<double>::max();
    for (int i = 0; i < n; i++){
    	PT tri[3] = {p[i], p[(i + 1) % n], p[(i + 2) % n]};
    	PT diff = tri[2] - tri[0];
    	swap(diff.x, diff.y);
    	diff.y = -diff.y;
    	double cur = (double) diff.dot(tri[2] - tri[1]) / (2 * diff.len());
    	res = min(res, cur);
    }
    cout << fixed << setprecision(10) << res << "\n";
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
