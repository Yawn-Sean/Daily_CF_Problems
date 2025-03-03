#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        How can you check if the current result can be formed with all intervals containing one integer?
        - 没有一个点会出现在所有的线段上
        - 当前的结果可以被所有的线段覆盖
        - 有一个点会出现在所有的线段上
        x1, x2, ..., xn, xn+1, ..., xp
        如果只知道这个集合(而不知道 n )，就不能确定不存在属于初始图片中所有线段的点

        1 2 2 1 2 2
        1 2 2 x 2 2

        */
    int n, m;
    cin >> n >> m;
    vector<int> ls(n), rs(n);
    for (int i = 0; i < n; i++) {
        cin >> ls[i] >> rs[i];
    }

    vector<int> cnt(m + 2);
    for (int i = 0; i < n; i++) {
        cnt[ls[i]]++;
        cnt[rs[i] + 1]--;
    }

    for (int i = 1; i <= m; i++) {
        cnt[i] += cnt[i - 1];
    }

    // LIS
    vector<int> tmp, v1(m + 2), v2(m + 2);
    for (int i = 1; i <= m; i++) {
        int p = upper_bound(tmp.begin(), tmp.end(), cnt[i]) - tmp.begin();
        if (p == tmp.size()) {
            tmp.emplace_back(cnt[i]);
        } else {
            tmp[p] = cnt[i];
        }
        v1[i] = tmp.size();
    }

    tmp.clear();

    // LDS(从后往前的LIS)
    for (int i = m; i >= 1; i--) {
        // > x
        int p = upper_bound(tmp.begin(), tmp.end(), cnt[i]) - tmp.begin();
        if (p == tmp.size()) {
            tmp.emplace_back(cnt[i]);
        } else {
            tmp[p] = cnt[i];
        }
        v2[i] = tmp.size();
    }

    int ans = 0;
    for (int i = 0; i <= m; i++) {
        ans = max(ans, v1[i] + v2[i + 1]);
    }
    cout << ans;
    return 0;
}
