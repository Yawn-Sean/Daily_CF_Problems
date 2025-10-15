#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<char> v1, v2;
    for (auto&ch: s) { v1.push_back(ch); }
    for (auto&ch: t) { v2.push_back(ch); }
    sort(v1.begin(), v1.end());
    sort(v2.rbegin(), v2.rend());

    vector<char> ans(n, ' ');
    int l1 = 0, r1 = n / 2 + (n % 2) - 1;
    int l2 = 0, r2 = n / 2 - 1;
    int pt1 = 0, pt2 = n - 1;

    for (int i = 0; i < n; i++) {
        char x = v1[l1];
        char y = v2[l2];
        if (i % 2 == 0) {
            if (x < y) {
                ans[pt1++] = x;
                l1++;
            } else {
                ans[pt2--] = v1[r1]; //
                r1--;
            }
        } else {
            if (y > x) {
                ans[pt1++] = y;
                l2++;
            } else {
                ans[pt2--] = v2[r2]; //
                r2--;
            }
        }
    }
    for (auto&ch: ans) { cout << ch; }
    cout << '\n';
    return 0;
}
