#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    i64 x; cin >> x;

    vector<pair<i64,int>> pos, neg, zero;
    for (int i = 0; i < n; i++){
    	i64 x; cin >> x;
    	if (x > 0) pos.push_back({x, i});
    	else if (x < 0) neg.push_back({x, i});
    	else zero.push_back({x, i});
    }
    vector<i64> res(n, 0);
    int zeroSz = zero.size();
    if (zeroSz <= k){
    	int negSz = neg.size();

    	if (zeroSz){
	    	if (negSz % 2 == 0){
	    		auto [val, idx] = zero.back();
	    		neg.push_back({-x, idx});
	    		zero.pop_back();
	    	}
			for (auto [val, idx] : zero){
				pos.push_back({x, idx});
			}
			k -= zeroSz;
		}
		else {
			if (negSz % 2 == 0){
				//try to get a pos to neg
				sort(pos.rbegin(), pos.rend());
				sort(neg.begin(), neg.end());
				if (pos.empty() || (!neg.empty() && !pos.empty() && -neg.back().first <= pos.back().first)){
					auto [val, idx] = neg.back();
					i64 need = (-val) / x + 1;
					if (need > k){
						neg.back().first += k * x;
						k = 0;
					}
					else {
						val += need * x;
						neg.pop_back();
						pos.push_back({val, idx});
						k -= need;
					}
				}
				else {
					auto [val, idx] = pos.back();
					i64 need = val / x + 1;
					if (need > k){
						pos.back().first -= k * x;
						k = 0;
					}
					else {
						val -= need * x;
						pos.pop_back();
						neg.push_back({val, idx});
						k -= need;
					}
				}
			}
		}

		priority_queue<array<i64,3>, vector<array<i64,3>>, greater<array<i64,3>>> pq;
		for (auto &[val, idx] : pos){
			pq.push({val, idx, 1LL});
		}
		for (auto &[val, idx] : neg){
			pq.push({-val, idx, -1LL});
		}
		while(k--){
			auto [val, idx, sgn] = pq.top(); pq.pop();
			pq.push({val + x, idx, sgn});
		}
		while(!pq.empty()){
			auto [val, idx, sgn] = pq.top(); pq.pop();
			res[idx] = val * sgn;
		}
    }
    else {
    	for (auto [val, idx] : pos) res[idx] = val;
    	for (auto [val, idx] : neg) res[idx] = val;
    	for (auto [val, idx] : zero) res[idx] = val;
    }
	for (int i = 0; i < n; i++){
		cout << res[i] << " \n"[i == n - 1];
	}


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