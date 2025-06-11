#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n), nxt(n);
	map<int,int> mp;
	set<int> cache;
	for (auto &ai : a){
		cin >> ai;
	}

	for (int i = n - 1; i >= 0; i--){
		if (!mp.count(a[i])){
			nxt[i] = n;
		}
		else nxt[i] = mp[a[i]];
		mp[a[i]] = i;
	}

	int res = 0;
	priority_queue<pair<int,int>> pq;
	for (int i = 0; i < n; i++){
		if (cache.count(a[i])){
			pq.push({nxt[i], a[i]});
		}
		else {
			if ((int) cache.size() < k){
				res++;
				cache.insert(a[i]);
				pq.push({nxt[i], a[i]});
			}
			else {
				res++;
				while(1){
					auto [x, y] = pq.top(); 
					if (!cache.count(y)) pq.pop();
					else break;
				}
				auto [x, y] = pq.top(); 
				cache.erase(y);
				cache.insert(a[i]);
				pq.pop();
				pq.push({nxt[i], a[i]});
			}

		}
	}	
	cout << res << "\n";

}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}