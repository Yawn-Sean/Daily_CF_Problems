#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    int cnt = 0;
    for (auto &ai : a){
    	cin >> ai;
    	cnt += (ai < 0);
    }
    if (cnt > k){
    	cout << "-1\n";
    	return;
    }
    if (cnt == 0){
    	cout << "0\n";
    	return;
    }

    int last = -1;
    vector<int> gap;
    for (int i = 0; i < n; i++){
    	if (a[i] >= 0) continue;
    	else {
    		if (last != -1 && last != i - 1){
    			gap.push_back(i - last - 1);
    		}
    		last = i;
    	}
    }

    sort(gap.begin(), gap.end());
    int res = ((int) gap.size() + 1) * 2 - (last == n - 1);
    int cur = res;
    //case one, extend last part
    if (last < n - 1 && cnt + (n - 1 - last) <= k){
    	int cur = res - 1;
    	int nCnt = cnt + (n - 1 - last);
    	for (auto v : gap){
    		if (nCnt + v <= k) {
    			nCnt += v;
    			cur -= 2;
    		}
    		else break;
    	}
    	res = min(res, cur);
    }

    for (auto v : gap){
    	if (cnt + v <= k) {
    		cnt += v;
    		cur -= 2;
    	}
    	else break;
    }
    res = min(res, cur);
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