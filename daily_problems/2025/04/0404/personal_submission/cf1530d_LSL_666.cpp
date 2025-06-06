#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n = 0;
		cin >> n;
		vector<int>arr(n + 1);
		vector<bool>vis(n + 1);
		vector<int>ans(n + 1, 0);
		vector<int>r;
		vector<int>find(n + 1);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			if (!vis[arr[i]]) {
				ans[i] = arr[i];
				vis[arr[i]] = 1;
				find[arr[i]] = i;
				sum++;
			}
		}
		for (int i = 1; i <= n; i++) if (!vis[i]) r.push_back(i);
		for (int i = 1; i <= n; i++) {
			if (ans[i] == 0) {
				if (i == r.back()) {
					int y = arr[i];
					int x = find[y];
					ans[x] = i;
					ans[i] = y;
				}
				else ans[i]=r.back();
				r.pop_back();
			}
		}
		cout << sum << endl;
		for (int i = 1; i <= n; i++)
			cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}
