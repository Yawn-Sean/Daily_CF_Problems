#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    i64 m, a, b; cin >> m >> a >> b;
    vector<i64> x(a, 1LL << 50), left(a, 1LL << 50);

    x[0] = left[0] = 0;

    i64 cur = 0, l = 0;
    
    while(1){
    	if (cur < b){
    		//min value > b
    		i64 add = (b - cur + a - 1) / a;
    		cur += a * add;
    		l = max(l, cur);
    	}
    	//back
    	cur -= b;

    	//suboptimal
    	if (cur >= x[cur % a]) break;
    	x[cur % a] = cur;
    	left[cur % a] = l;
    }

    auto gao = [&](i64 v) -> i64 {
    	//sum from 0/a + (v - 1)/a
    	if (v <= 0) return 0;
    	i64 ans = 0;
    	ans += (v % a) * (v / a);
    	v -= v % a;
    	ans += a * (v / a) * (v / a - 1) / 2;
    	return ans;
    };

    i64 res = 0;
    for (int i = 0; i < a; i++){
    	if (left[i] <= m){
    		res += (m - left[i] + 1) + gao(m - x[i] + 1) - gao(left[i] - x[i]);
    	}
    }
    cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}