#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    i64 tot = 0; // 总共的二进制1的个数
    i64 cur_high = 0; // 当前枚举的二进制位
    i64 cnt = 0; // 当前二进制位的种类数量
    for (int i = 0; i < n; i++) {
        // 1. 处理当前的二进制位
        while (cur_high < a[i] && cnt > 0) {
            tot += (cnt & 1);
            cur_high++;
            cnt /= 2;
        }
        // 2. 追上并累加新数
        cur_high = a[i];
        ++cnt;
    }

    while (cnt > 0) {
        tot += (cnt & 1);
        cur_high++;
        cnt /= 2;
    }

    cout << cur_high - tot << endl;
    return 0;
}
