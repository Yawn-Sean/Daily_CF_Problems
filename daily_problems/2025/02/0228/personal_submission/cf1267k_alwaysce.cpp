#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /**
        key拥有一样的multiset就会发生collision
        给你t个key
        {1,1,2}排列有几种可能的情况? 满足p[i]<=i (还有最后1位非0 中间可以是0)
        求排列个数的问题
    */

    int t;
    cin >> t;
    while (t--) {
        i64 key;
        cin >> key;

        // 计算发生冲突的概率
        // multiset{1,1,2}
        // key%2, (key/2)%3, (key/2/3)%4,...
        vector<i64> fac(20, 1);
        for (int i = 1; i < 20; i++) {
            fac[i] = fac[i - 1] * i;
        }
    
        vector<int> cnt(21);
        int len;
        for (int i = 1; i <= 20; i++) {
            cnt[key % i]++;
            len = i;
            key /= i;
            if (key == 0) { break; }
        }

        i64 ans = 0;
        int cur = 0;
        i64 to_divide = 1, res = 1;
        for (int i = 0; i < len; i++) {
            to_divide *= fac[cnt[i]];
            cur += cnt[i];
            res *= cur;
            --cur; // x被选走了一个
        }

        // fac[cnt[i]!]
        ans += res / to_divide;
        // 最后一位不能是0
        if (cnt[0] > 0) {
            cnt[0]--;
            --len;

            cur = 0;
            to_divide = 1;
            res = 1;
            for (int i = 0; i < len; i++) {
                to_divide *= fac[cnt[i]];
                cur += cnt[i];
                res *= cur;
                --cur; // x被选走了一个
            }
            ans -= res / to_divide;
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}
