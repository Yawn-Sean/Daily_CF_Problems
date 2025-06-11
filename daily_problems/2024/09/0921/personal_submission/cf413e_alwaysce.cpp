#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int inf = 1e9 + 7;
struct Info {
    std::vector<int> ans;    
    Info() : ans(4, inf) { ans[0] = ans[3] = 0; }
    Info(std::initializer_list<int> list) {
        ans = list;
    }
};


Info operator+(Info a, Info b) {
    Info c;
    // 00: 0->0 0->0 / 0->1 1->0
    c.ans[0] = min(a.ans[0] + b.ans[0], a.ans[1] + b.ans[2]);
	// 01: 0->1 1->1 / 0->0 0->1
	c.ans[1] = min(a.ans[0] + b.ans[1], a.ans[1] + b.ans[3]);
	// 10: 1->0 0->0 / 1->1 1->0
	c.ans[2] = min(a.ans[2] + b.ans[0], a.ans[3] + b.ans[2]);
	// 11: 1->1 1->1 / 1->0,0->1 
	c.ans[3] = min(a.ans[3] + b.ans[3], a.ans[2] + b.ans[1]);    
    for (int i = 0; i < 4; i++) {
    	c.ans[i] = min(c.ans[i], inf);
    }
    return c;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, q;
	cin >> n >> q;
	
	string s1, s2;
	cin >> s1 >> s2;
	
	vector<Info> init(n);
	
	// i位置在0/1行 走到i+1位置的0/1行
	for (int i = 0; i < n; i++) {
		if (s1[i] == 'X') {
			if (s2[i] == 'X') {
				init[i] = {inf, inf, inf, inf};
			} else {
				init[i] = {inf, inf, inf, 0};
			}
		} else {
			if (s2[i] == 'X') {
				init[i] = {0, inf, inf, inf};
			} else {
				init[i] = {0, 1, 1, 0};
			}
		}
	}
	
	SegmentTree<Info> seg(init);
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		
		int l = u, sl = 0;
		int r = v, sr = 0;
		if (l >= n) {
			l -= n;
			sl = 1;
		}
		if (r >= n) {
			r -= n;
			sr = 1;
		}
		
		if (l > r) {
			swap(l, r);
			swap(sl, sr);
		}
		
		int ans = seg.rangeQuery(l, r + 1).ans[2 * sl + sr];
		cout << (ans < inf ? ans + r - l : -1) << '\n';
	}

    return 0;
}
