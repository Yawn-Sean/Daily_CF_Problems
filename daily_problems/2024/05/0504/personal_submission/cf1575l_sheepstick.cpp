#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// for i < j < k, if compatible(i, j) and compatible(j, k), then compatible(i, k)
// find best compatible solution before
// (i, j) compatible iff ? (rem(i) + (j - i - 1) >= rem(j) and rem(i) <= rem(j))
//sort based on rem(i) and find max value of f in all (i - rem(i) + 1 <= j - rem(j))

void solve() {
    int n; cin >> n;
    vector<array<int,2>> rem(n);
    for (int i = 0; i < n; i++){
    	int x; cin >> x;
    	rem[i] = {i - x + 1, i};
    }
    sort(rem.begin(), rem.end());
    map<int,int> mp;
    int res = 0;
    for (auto [val, idx] : rem){
    	if (val < 0) continue;
    	
    	int cur = 0;
    	auto it = mp.lower_bound(idx - val);
    	if (it != mp.begin()){
    		it--;
    		cur = it -> second + 1;
    	}
    	else {
    		cur = 1;
    	}
    	res = max(res, cur);
    	if (mp[idx - val] >= cur) continue;
    	mp[idx - val] = cur;
    	it = mp.upper_bound(idx - val);
    	while(it != mp.end()){
    		if (it -> second > cur) break;
    		else it = mp.erase(it);
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