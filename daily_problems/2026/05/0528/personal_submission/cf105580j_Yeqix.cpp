#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

string query(string& s) {
	cout << s << "\n";
	cout.flush();
	string ans;
	cin >> ans;
	return ans;
}

vector<string> q = {"MOVE DOWN", "MOVE UP", "MOVE RIGHT", "MOVE LEFT", "BACK"};
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

vector<int> py = {1, -1, 1, -1};
set<array<int, 3>> f[62][62];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;

	auto dfs = [&](auto && dfs, int x, int y, array<int, 3> arr)->void{
		for (int i = 0; i < 4; i++) {
			if (arr[2] == i + py[i]) {
				continue;
			}
			int ex = x + dx[i], ey = y + dy[i];
			array<int, 3> nw = {arr[1], arr[2], i};
			if (f[ex][ey].count(nw)) {
				continue;
			}
			string now = query(q[i]);
			if (now == "FAIL") {
				continue;
			} else if (now == "OK") {
				f[ex][ey].insert(nw);
				dfs(dfs, ex, ey, nw);
				query(q[4]);
			} else {
				exit(0);
			}
		}
	};
	dfs(dfs, 30, 30, { -1, -2, -3});
	return 0;
}