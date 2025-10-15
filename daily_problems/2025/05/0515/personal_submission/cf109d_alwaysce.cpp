#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
        swap only one of them is lucky number (all 4 or 7)       
        任意位置的交换等于 (u, lucky), (lucky, v)
        请在2n次交换操作内完成排序
    */
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    auto is_lucky = [&](int x) {
        while (x > 0) {
            if (x % 10 != 4 && x % 10 != 7) {
                return false;
            }
            x /= 10;
        }
        return true;
    };

    int lucky_pos = -1;
    for (int i = 0; i < n; i++) {
        if (is_lucky(nums[i])) {
            lucky_pos = i;
            break;
        }
    }

    if (lucky_pos == -1) {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            ok &= (nums[i - 1] <= nums[i]);
        }
        if (ok) {
            cout << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
        return 0;
    }
    
    vector<pair<int,int>> ops;
    vector<int> order(n), actual(n), pos(n);
    iota(order.begin(), order.end(), 0);
    
    iota(actual.begin(), actual.end(), 0);
    iota(pos.begin(), pos.end(), 0);

    sort(order.begin(), order.end(), [&](int x, int y) {
        return nums[x] < nums[y];
    });

    auto change = [&](int x, int y) {
        if (x == y) {
            return;
        }

        // x y 变成 value = x 元素 和 value = y 元素的下标
        x = pos[x];
        y = pos[y];
        ops.emplace_back(x, y);

        // pos[actual[x]]: value=actual[x]的位置下标 进行下标交换
        swap(pos[actual[x]], pos[actual[y]]);
        // x 和 y位置上 实际的元素交换
        swap(actual[x], actual[y]);
    };


    for (int i = 0; i < n; i++) {
        // 数值为actual[i]的元素 与 数值为order[i]的元素
        // 通过lucky_pos 交换
        change(actual[i], lucky_pos);
        change(order[i], lucky_pos);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << actual[i] << ' ';
    // }
    // cout << '\n';

    cout << ops.size() << '\n';
    for (auto& [x, y]: ops) {
        cout << x + 1 << ' ' << y + 1 << '\n';
    }
    return 0;
}
