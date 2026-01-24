#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> inc_length(n, 1);
    int pos = -1;

    for (int i = n - 1; i >= 0; --i) {
        if (nums[i] > 0) {
            if (pos != -1) {
                if (nums[i] > nums[pos]) {
                    inc_length[i] = pos - i;
                } else {
                    inc_length[i] = inc_length[i + 1] + 1;
                }
            }
            pos = i;
        } else if (i != n - 1) {
            inc_length[i] = inc_length[i + 1] + 1;
        }
    }

    vector<int> dec_length(n, 1);
    pos = -1;

    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            if (pos != -1) {
                if (nums[i] > nums[pos]) {
                    dec_length[i] = i - pos;
                } else {
                    dec_length[i] = dec_length[i - 1] + 1;
                }
            }
            pos = i;
        } else if (i > 0) {
            dec_length[i] = dec_length[i - 1] + 1;
        }
    }

    for (int i = 3; i <= n; ++i) {
        bool flg = true;
        for (int j = 0; j < n; j += i) {
            int l = j;
            int r = min(j + i - 1, n - 1);
            if (inc_length[l] + dec_length[r] < r - l + 2 || r - l + 1 < 3 || inc_length[l] < 2 || dec_length[r] < 2) {
                flg = false;
                break;
            }
        }
        if (flg) {
            cout << "Y" << "\n";
            return 0;
        }
    }

    cout << "N" << "\n";

    return 0;
}
