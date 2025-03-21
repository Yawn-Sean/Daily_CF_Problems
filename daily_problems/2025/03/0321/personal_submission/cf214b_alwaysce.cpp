#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> cnt(11);
    int tot = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        tot += x;
    }

    auto print_ans = [&]() {
        bool flag = false;
        for (int i = 9; i > 0; i--) {
            for (int j = 0; j < cnt[i]; j++) {
                cout << i;
                flag = true;
            }
        }
        if (!flag) {
            cout << 0;
        } else {
            for (int j = 0; j < cnt[0]; j++) {
                cout << 0;
            }
        }
    };

    if (!cnt[0]) {
        cout << -1;
    } else if (tot % 3 == 0) {
        print_ans();
    } else {
        for (int i = 0; i < 10; i++) {
            if (cnt[i] && (tot - i) % 3 == 0) {
                cnt[i]--;
                print_ans();
                return 0;
            }
        }

        for (int i = 0; i < 10; i++) {
            if (cnt[i]) {
                --cnt[i];
                for (int j = 0; j <= i; j++) {
                    if (cnt[j] && (tot - i - j) % 3 == 0) {
                        cnt[j]--;
                        print_ans();
                        return 0;
                    }
                }
                ++cnt[i];
            }
        }
    }
    return 0;
}
