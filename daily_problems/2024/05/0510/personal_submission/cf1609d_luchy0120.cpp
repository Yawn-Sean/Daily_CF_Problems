#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <set>
#include <cmath>
#include <array>
#include <unordered_set>
using namespace std;




vector<int> fa;

int rt(int x) {
	return fa[x] = ((x == fa[x]) ? x : rt(fa[x]));
}



int main() {
	int n, d;cin >> n >> d;

	fa.resize(n+1);
	for (int i = 1;i <= n;++i) {
		fa[i] = i;
	}
	
	int bon = 0;
	for (int i = 0;i < d;++i) {
		int x, y;cin >> x >> y;
		int xx = rt(x);
		int yy = rt(y);

		if (xx != yy) {
			fa[xx] = yy;
		}
		else {
			bon++;
		}
		map<int, int> mp;
		for (int i = 1;i <= n;++i) {
			mp[rt(i)]++;
		}
		vector<int> v;
		for (auto &ele : mp) {
			v.push_back(ele.second);
		}
		sort(v.rbegin(),v.rend());

		int tot = v[0]-1;
	
		for (int j = 1;j <= bon;++j) {
			tot += v[j];
		}
		cout << tot << endl;

	}

	return 0;
}