//https://codeforces.com/problemset/submission/613/255806520
#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	i64 n, mxScore, coeffFull, coeffMi, m;
	cin >> n >> mxScore >> coeffFull >> coeffMi >> m;

	vector<i64> b(n), acc(n);
	int cnt = 0;
	for (auto &bi : b){
		cin >> bi;
		if (bi == mxScore) cnt++;
	}

	vector<i64> a(b);
	vector<int> idx(n, 0); iota(idx.begin(), idx.end(), 0);
	sort(a.begin(), a.end());
	sort(idx.begin(), idx.end(), [&](int i, int j){return b[i] < b[j];});
	partial_sum(a.begin(), a.end(), acc.begin());

	i64 res = a[0] * coeffMi + cnt * coeffFull;
	i64 fullNeed = 0, miNeed = 0;

	auto check = [&](int idx, i64 target) -> bool {
		return (idx + 1) * target - acc[idx] <= miNeed;
	};

	i64 bestMx = cnt, bestMi = a[0], curMi = -1;
	for (int i = cnt, j = n - 1; i <= n; i++){
		if (i && a[n - i] < mxScore){
			fullNeed += mxScore - a[n - i];
		}
		if (fullNeed > m) break;
		while(j >= n - i && j >= 0) j--;
		miNeed = m - fullNeed;
		while (j >= 0){
			if (!check(j, a[j])) j--;
			else {
				i64 l = a[j], r = mxScore - 1;
				while(l < r){
					i64 mid = (l + r + 1) / 2;
					if (check(j, mid)){
						l = mid;
					}
					else r = mid - 1;
				}
				curMi = l;
				break;
			}
		}
		i64 val = i * coeffFull + coeffMi * (j >= 0 ? curMi : mxScore);
		if (val > res){
			res = val;
			bestMx = i;
			bestMi = curMi;
		}
	}
	cout << res << "\n";
	for (int i = n - bestMx; i < n; i++){
		b[idx[i]] = mxScore;
	}
	for (int i = 0; i < n; i++){
		if (b[i] < bestMi) b[i] = bestMi;
	}
	for (int i = 0; i < n; i++){
		cout << b[i] << " \n"[i == n - 1];
	}
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    solve();
    return 0;
}