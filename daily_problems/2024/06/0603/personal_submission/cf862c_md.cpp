// 0603
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    if (n == 1) {
        cout << "Yes\n" << x << endl;
    } else if (n == 2) {
        if (x == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n" << 0 << " " << x << endl;
        }
    } else {
        const int max_pos = 19;
        vector<int> nums;
        int xor_sum = 0;
        for (int i = 0, v = 1; i < n - 1 - (n % 2 == 0); i += 2, ++v) {
            if (v == x) {
                v++;
            }
            nums.push_back(v);
            nums.push_back(v ^ (1 << max_pos));
            xor_sum ^= v;
            xor_sum ^= (v ^ (1 << max_pos));
        }

        if (n % 2 == 0) {
            if (x == 0) {
                if (xor_sum == 1 << max_pos) {
                    const int magic = 50001;
                    nums.push_back(magic);
                    nums.push_back(magic ^ (1 << max_pos));
                } else {
                    const int magic = 50001;
                    nums.pop_back();
                    nums.pop_back();
                    nums.push_back(magic ^ 1);
                    nums.push_back(magic ^ (1 << max_pos));
                    nums.push_back(magic ^ 2);
                    nums.push_back(magic ^ 3);
                }
            } else {
                nums.push_back(xor_sum ^ x);
                nums.push_back(0);
            }
        } else {
            nums.push_back(xor_sum ^ x);
        }

        xor_sum = 0;
        cout << "YES\n";
        for (auto v : nums) {
            cout << v << " ";
            xor_sum ^= v;
        }
        cout << endl;

        sort(begin(nums), end(nums));
        assert(xor_sum == x && adjacent_find(begin(nums), end(nums)) == end(nums));
    }

    return 0;
}