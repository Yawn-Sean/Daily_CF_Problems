#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    vector<i64> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    vector<i64> squares;
    for (i64 i = 0; i * i <= 1e9; i++) {
        squares.push_back(i * i);
    }
    i64 nxt = squares.size();
    squares.push_back(nxt * nxt); // first > 1e9

    vector<i64> costs, square_num;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(squares.begin(), squares.end(), nums[i]);
        if (it != squares.end() && *it == nums[i]) {
            if (nums[i] == 0) {
                square_num.push_back(2);
            } else {
                square_num.push_back(1);
            }
        } else {
            i64 cost1 = abs(nums[i] - *it);
            i64 cost2 = (it != squares.begin()) ? abs(nums[i] - *(it - 1)) : LLONG_MAX;
            costs.push_back(min(cost1, cost2));
        }
    }

    sort(costs.begin(), costs.end());
    sort(square_num.begin(), square_num.end());

    if (square_num.size() * 2 == n) {
        cout << "0\n";
        return 0;
    } else if (square_num.size() * 2 > n) {
        i64 ans = 0;
        int need = square_num.size() - n / 2;
        for (int i = 0; i < need; i++) {
            ans += square_num[i];
        }
        cout << ans << "\n";
        return 0;
    } else {
        i64 ans = 0;
        int need = n / 2 - square_num.size();
        for (int i = 0; i < need; i++) {
            ans += costs[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
