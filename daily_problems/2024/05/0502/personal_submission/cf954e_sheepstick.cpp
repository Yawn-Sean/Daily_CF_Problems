#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
double eps = 1E-10;

void solve() {
    int n, T; cin >> n >> T;

    vector<int> a(n), t(n);
    vector<array<int,2>> cold, hot;
    for (auto &ai : a){
    	cin >> ai;
    }
    for (auto &ti : t){
    	cin >> ti;
    }


    double res = 0;
    i64 coldSum = 0, hotSum = 0;
    for (int i = 0; i < n; i++){
    	t[i] -= T;
    	if (t[i] < 0){
    		cold.push_back({-t[i], a[i]});
    		coldSum -= 1LL * t[i] * a[i];
    	}
    	else if (t[i] > 0){
    		hot.push_back({t[i], a[i]});
    		hotSum += 1LL * t[i] * a[i];
    	}
    	else res += a[i];
    }

    if (cold.empty() || hot.empty()){
    	cout << res << "\n";
    	return;
    }

    sort(cold.begin(), cold.end());
    sort(hot.begin(), hot.end());

    if (coldSum > hotSum){
    	swap(coldSum, hotSum);
    	swap(cold, hot);
    }
    for (auto &[ti, ai] : cold){
    	res += ai;
    }
    //cout << res << "---\n";
    for (auto &[ti, ai] : hot){
    	i64 cur = 1LL * ti * ai;
    	if (coldSum > cur){
    		coldSum -= cur;
    		res += ai;
    	}
    	else {
    		res += 1.0 * coldSum / (double) ti;
    		break;
    	}
    }
    cout << fixed << setprecision(10) << res << "\n";
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