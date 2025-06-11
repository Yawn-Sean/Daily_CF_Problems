#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	int m = s1.size();

	vector<int> cnt(100);
	auto get_mx = [&](string& s) {
		for(int i = 0; i < 100; i++) { cnt[i] = 0; }
		
		for (auto&ch: s) {
			++cnt[ch-'A'];
		}
		return *max_element(cnt.begin(), cnt.end());
	};
	
	int mx1 = get_mx(s1), mx2 = get_mx(s2), mx3 = get_mx(s3);	
	vector<string> name{"Kuro", "Shiro", "Katie"};
	// 问题 全部改成一样的之后 多出来的次数 是奇数会-1
	// 是原来有非主元字符存在 那么多出来的步数都无所谓
	// 多出来的>=2就无所谓了 多出来正好多1次怎么办
	
	vector<pair<int,int>> v;
	int v1 = min(mx1 + n, m);
	if (mx1 == m && n == 1) { v1 = m - 1; }
	
	int v2 = min(mx2 + n, m);
	if (mx2 == m && n == 1) { v2 = m - 1; }
	
	int v3 = min(mx3 + n, m);
	if (mx3 == m && n == 1) { v3 = m - 1; }
	
	v.emplace_back(v1, 0);
	v.emplace_back(v2, 1);
	v.emplace_back(v3, 2);
	sort(v.begin(), v.end(), [&](auto&pa, auto&pb) {
		if (pa.first == pb.first) {
			return pa.second < pb.second;
		}
		return pa.first > pb.first;
	});
	
	if (v[0].first == v[1].first) {
		cout << "Draw";
	} else {
		cout << (name[v[0].second]);
	}
	
	return 0;
}
