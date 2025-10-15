#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<unordered_set>
using namespace std;
const int m = 1e6;
int main() {
	int n;
	cin >> n;
	unordered_set<int>s;
	unordered_set<int>t;
	for (int i = 1; i <= m / 2; i++) s.insert(i);
	int num = 0;
	for (int i = 0; i < n; i++) {
		int x = 0;
		scanf("%d", &x);
		int y = m - x+1;
		int v = min(x, y);
		if(s.count(v))
			s.erase(v);
		if (t.count(y)) {
			t.erase(y);
			num++;
		}
		else t.insert(x);
	}
	vector<int>ans;
	for (auto& x : t) ans.push_back(m - x + 1);
	for (auto& x : s) {
		if (num == 0) break;
		ans.push_back(x);
		ans.push_back(m - x + 1);
		num--;
	}
	printf("%d\n", n);
	for (auto& x : ans) printf("%d ", x);
	return 0;
}
