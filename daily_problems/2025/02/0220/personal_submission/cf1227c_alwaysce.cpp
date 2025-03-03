#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<char> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        bool flag = true;
        vector<pair<int,int>> op;
                
        auto do_swap = [&](int l, int r) {
            op.emplace_back(l, r);

            while (l < r) {
                swap(s[l], s[r]);
                l++;
                r--;
            }
        };


        for (int i = 0; i < n; i++) {
            if (flag) {
                if (s[i] != '(') {
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == '(') { 
                            do_swap(i, j);
                            break;
                        }
                    }
                    
                }
            } else {
                if (s[i] != ')') {
                    for (int j = i + 1; j < n; j++) {
                        if (s[j] == ')') { 
                            do_swap(i, j);
                            break;
                        }
                    }
                    
                }
            }
            flag = !flag;
        }
    
        // 然后根据k的大小合并一些括号
        int cur = n / 2;
        int r = n - 2;
        for (int i = cur; i > k; i--) {
            op.emplace_back(r - 1, r);
            r -= 2;
        }

        cout << op.size() << '\n';
        for (auto& [l, r] : op) {
            cout << l + 1 << ' ' << r + 1 << '\n';
        }
    }
    return 0;
}
