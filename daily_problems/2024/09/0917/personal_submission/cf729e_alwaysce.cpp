#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	for (auto& x: a) {
		cin >> x;
	}
	--s;
	
	int ans = 0;
	if (a[s] != 0) {
		ans++;
	}
	
	// 修改数组元素，使得剩余元素是从 1 开始的连续整数组成的数组
 	// 最小修改次数 
 	// 最后的数组由 1-x的数字组成
	vector<int> cnt(n);
    for (int i = 0; i < n; i++) {
    	if (i != s) {
    	    ++cnt[a[i]];	
    	}
    }
    
    // 因为里面的空总能填满，同时外面的数字也总能变进来，两件事也是可以直接同时进行的
    int cur = 0;
    for (int x = 1; x < n; x++) {
    	if (cnt[x] > 0) {
    		cur += cnt[x];
    	} else {
    		cur++;
    		ans++;
    	}
    	// 足够多了 break
    	if (cur >= n - 1) {
    		break;
    	}
    }
    cout << ans << '\n';
    return 0;
}
