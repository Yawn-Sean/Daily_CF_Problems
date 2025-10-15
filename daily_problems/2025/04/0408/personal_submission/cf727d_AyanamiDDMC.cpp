#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> PII;
typedef pair<int, string> PSI;
const int N = 1e5 + 10, M = 6;

int cnt[M];
map<string, int> mp;
string ans[N];
vector<PSI> w;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	mp["S"] = 0;
	mp["M"] = 1;
	mp["L"] = 2;
	mp["XL"] = 3;
	mp["XXL"] = 4;
	mp["XXXL"] = 5;

	int sum = 0;
	for (int i = 0; i < M; ++i) {
		cin >> cnt[i];
		sum += cnt[i];
	}

	int n;
	cin >> n;
	if (sum < n) {
		cout << "NO" << "\n";
		return 0;
	}

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		int pos = s.find(',');
		if (pos == string::npos) {
			if (cnt[mp[s]] == 0) {
				cout << "NO" << "\n";
				return 0;
			}
			ans[i] = s;
			cnt[mp[s]]--;
		}
		else w.push_back({i, s});
	}

	// 枚举每个尺码
	for (int size = 0; size < M; ++size) {
		for (auto &[i, s]: w) {
			if (ans[i] != "") continue;

			int pos = s.find(',');
			string s1 = s.substr(0, pos);
			string s2 = s.substr(pos + 1);

			int a = mp[s1];
			int b = mp[s2];

			// 优先使用小尺码
			if (a == size && b == size + 1) {
				if (cnt[a] > 0) {
					ans[i] = s1;
					cnt[a]--;
				}
				else if (cnt[b] > 0) {
					ans[i] = s2;
					cnt[b]--;
				}
				else {
					cout << "NO" << "\n";
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (ans[i] == "") {
			cout << "NO" << "\n";
			return 0;
		}
	}

	cout << "YES" << "\n";
	for (int i = 0; i < n; ++i) cout << ans[i] << "\n";
	return 0;
}
