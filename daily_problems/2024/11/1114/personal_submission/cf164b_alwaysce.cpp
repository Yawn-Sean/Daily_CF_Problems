#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int la, lb;
	cin >> la >> lb;
	
	vector<int> a(la);
	vector<int> bidxs(1e6+1, -1);

	for (int i = 0; i < la; i++) { cin >> a[i]; }
	for (int i = 0; i < lb; i++) { 
		int b;
		cin >> b;
		bidxs[b] = i;
	}
	
	/*
	123451234512345
	135613561356...
	
	12[31]23123
	321321321
	Having considered the i-th character of a, 
	you should directly know where the i+1-th character of a
	should be in b.
	
	不会一个文字出现两次
	a[i] -> b[j], a[i+1] in b[x]
	x > j, x = j+1,...,j+m
	
	[1, lb] [lb+1, 2lb], ..., []
	
	*/
	int curL = 0; // 当前指针
	int rpt = 0;
	int ans = 0;
	for (int i = 0; i < la; i++) {
		if (rpt < i) {
			rpt = i;
			curL = 0;
		} else if (i > 0) {
			// rpt >= i, curL移动
			int ncur = bidxs[a[i]] - bidxs[a[i - 1]];
			if (ncur < 0) {
				ncur += lb;
			}
			curL -= ncur;
		}
		
		if (bidxs[a[i]] == -1) {
			continue;
		}
		
		while (rpt < i + la - 1) {
			if (bidxs[a[(rpt + 1) % la]] == -1) {
				break;
			}
			
			int ncur = bidxs[a[(rpt + 1) % la]] - bidxs[a[rpt % la]];
			if (ncur < 0) {
				ncur += lb;
			}
			
			// 超过了一圈 直接退出
			if (curL + ncur >= lb) {
				break;
			}
			// 找到了一个匹配
			rpt += 1;
			curL += ncur;
		}
		
		ans = max(ans, rpt - i + 1);
	}
	cout << ans;
    return 0;
}
