#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n; cin >> n;
	vector<int> c(n), a(n);
	for (auto &ci : c){
		cin >> ci;
	}
	for (auto &ai : a){
		cin >> ai;
		ai--;
	}
	int res = 0;
	vector<int> visited(n, 0);
	for (int i = 0; i < n; i++) if (!visited[i]){
		visited[i] = 1;
		int j = i;
		vector<int> stk{i};
		while(1){
			j = a[j];
			if (!visited[j]){
				visited[j] = 1;
				stk.push_back(j);
			}
			else {
				if (visited[j] == 1){
					int cur = c[j];
					while(stk.back() != j){
						cur = min(cur, c[stk.back()]);
						visited[stk.back()] = 2;
						stk.pop_back();
					}
					res += cur;
				}
				while(!stk.empty()){
					visited[stk.back()] = 2;
					stk.pop_back();
				}
				break;
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