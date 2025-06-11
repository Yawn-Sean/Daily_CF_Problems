#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        n个卷子 每张卷子1-p分数
        现在已经写了k份 a[1]...a[k]
        
        要求: 中位数>= y 分 以及 卷子分数总和 <= x
        找到构造
    */
    int n, k, p, x, y;
    cin >> n >> k >> p >> x >> y;
    vector<int> a(k);
    int cur = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        cur += a[i];
    }

    // 中位数>=y
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] >= y) {
            cnt++;
        }
    }
    // 全部补充>=y都不够中位数
    if (cnt + (n - k) < n / 2 + 1) {
        cout << -1 << endl;
        return 0;
    }
    // >=y的个数 = n/2+1
    // <y的个数=n/2
    int idx = k;
    vector<int> ans;
    for (int j = cnt + 1; j <= n / 2 + 1; j++) {
        cur += y;
        idx++;
        ans.push_back(y);
    }
    
    for (; idx < n; idx++) {
        cur += 1;
        ans.push_back(1);
    }

    if (cur > x) {
        cout << -1 << endl;
    } else {
        for (auto&x: ans) {
            cout << x << ' ';
        }
        cout << endl;
    }

    return 0;
}
