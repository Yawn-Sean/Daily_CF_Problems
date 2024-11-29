#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		从(y,y,y) -> (x,x,x)
		
		y,y,y -> y,y,2y-1 -> y,2y-1,3y-2 -> 2y-1,3y-2,5y-4 -> ...
		
		直到最大的边 >= x
		处理次大边 ...
		
		最后是最小边
	*/
	int x, y;
	cin >> x >> y;
	int ans = 0;
	
	vector<int> tr = {y, y, y};
	while (true) {
		sort(tr.begin(), tr.end());
		if (tr[0] == x) {
			break;
		}
		
		int m1 = tr[1], m2 = tr[2];
		int mx = min(x, m1 + m2 - 1);
		tr[0] = mx;
		++ans;
	}
	// for (auto& t: tr) { cout << t << ' '; }
	// cout << '\n';
	
	cout << ans;
	
    return 0;
}
