#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, k; cin >> n >> k;
	vector<string> a(n);
	for (auto &ai : a){
		cin >> ai;
	}
	int res = 0, base = 0;
	//feasible range for each row
	vector<array<int,2>> row(n);
	for (int i = 0; i < n; i++){
		int left = n, right = -1;
		for (int j = 0; j < n; j++) if (a[i][j] == 'B'){
			left = min(left, j);
			right = max(right, j);
		}
		if (left == n){ //all white
			base++;
			row[i] = {n, n};
		}
		else {
			if (right - left >= k) row[i] = {n, n};
			else {
				row[i] = {max(0, right - k + 1), min(n - k, left)};
			}
		}
	}
	//col
	vector<int> last(n, n), bad(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) if (a[i][j] == 'B'){
			last[j] = i; 
		}
	}
	base += count(last.begin(), last.end(), n);

	vector<deque<int>> right(n + 1);
	for (int i = 0, w = 0; i <= n - k; i++){
		while(w < i + k){
			right[row[w][0]].push_back(row[w][1]);
			w++;
		}
		priority_queue<int, vector<int>,greater<int>> pq;
		for (int j = 0, idxCol = 0, colCnt = 0; j <= n - k; j++){
			//row
			while(!pq.empty() && pq.top() < j) pq.pop();
			for (auto v : right[j]){
				pq.push(v);
			}
			//col
			while(idxCol < j + k){
				if (!bad[idxCol] && last[idxCol] < i + k) colCnt++;
				idxCol++;
			}
			res = max(res, base + (int) pq.size() + colCnt);
			//remove col
			if (!bad[j] && last[j] < i + k) colCnt--;
		}
		for (int j = 0; j < n; j++){
			if (a[i][j] == 'B') bad[j] = 1;
		}
		right[row[i][0]].pop_front();
	}
	cout << res << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}