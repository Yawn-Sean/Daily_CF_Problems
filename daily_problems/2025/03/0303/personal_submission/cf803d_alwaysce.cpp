#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        二分宽度 w

        只有' ' '-' 可以成为一行的结尾字符
    */
    int k;
    cin >> k;
    cin.get(); // '\n'

    vector<int> idxs;
    idxs.emplace_back(-1);

    int tot_len = 0;
    string s;
    while (getline(cin, s)) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '-' || s[i] == ' ') {
                idxs.emplace_back(i + tot_len);
            }
        }
        tot_len += n;
        tot_len++; // ' '空格
    }
    --tot_len; // 最后一个空格不算
    idxs.emplace_back(tot_len - 1);
    int x = idxs.size();
    
    int left = 1, right = tot_len + 1;
    int ans = tot_len;
    // for (auto&val: idxs) {
    //     cout << val << ' ';
    // }
    // cout << '\n';

    while (left < right) {
        int mid = (left + right) / 2;
        bool check = true;
        
        int row = 0;
        int i = 0;
        while (i < x) {
            int j = i;
            while (j < x && idxs[j] - idxs[i] <= mid) {
                j++;
            }
            ++row;

            if (j == x && idxs[j - 1] - idxs[i] <= mid) {
                break;
            } else {
                if (j == i + 1) {
                    check = false;
                    break;
                } else {
                    i = j - 1;
                }
            }
        }

        check &= (row <= k);
        if (!check) {
            left = mid + 1;
        } else {
            right = mid;
            ans = mid;
        }
    }
    cout << ans << '\n';
    return 0;
}
