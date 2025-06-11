#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
// #define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 3e5 + 10;

int n, idx;
int Tr[N * 30 + 10][2], sz[N * 30 + 10][2];
//Trie不能开动态数组，他不够2的次方就会开2的次幂，会爆内存
inline void insert(int x) {
	int p = 0;
	for (int i = 30; i >= 0; i --) {
		int t = x >> i & 1;
		if (!Tr[p][t]) {
			Tr[p][t] = ++ idx;//存储新结点位置
			sz[p][t] ++;
		} else sz[p][t] ++;
		p = Tr[p][t];
	}
}
inline int query(int x) { //与x异或后的最小值
	int p = 0, ans = 0;
	for (int i = 30; i >= 0 ; i --) {
		int t = x >> i & 1;
		if (Tr[p][t] && sz[p][t]) {
			sz[p][t]--;
			p = Tr[p][t]; //贪心先查找相同的数，判断该位置是否存在结点，若不为0则该位置存在值可以继续向下查找；
		} else if (sz[p][t ^ 1]) {
			sz[p][t ^ 1]--;
			p = Tr[p][t ^ 1], ans += 1 << i; //若要求的是异或后的最大值，则需将if内改为Tr[p][bit^1],先判断不同的使得异或最大；
		}
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	vector<int>a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		insert(x);
	}

	for (int i = 1; i <= n; i++) {
		// cout<<a[i]<<endl;
		cout << query(a[i]) << ' ';
	}
}
signed main() {
	fastio;
	int T;
	T = 1;
	// cin>>T;
	while (T--) solve();

	return 0;
}
