/*
 https://codeforces.com/problemset/problem/794/C
 C. Naming Company
 Solver: nhant
 2025-05-07 05:14:26
 https://codeforces.com/problemset/submission/794/318673409, O(N)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> cnt1(26), cnt2(26);
    string s;
    cin >> s;
    int n = (int) s.size();
    for (char c : s) {
        cnt1[c - 'a']++;
    }
    cin >> s;
    for (char c : s) {
        cnt2[c - 'a']++;
    }
    int skip1 = n / 2, skip2 = (n + 1) / 2;
    for (int i = 0; i < 26; i++) {
        int d = min(skip1, cnt1[25 - i]);
        skip1 -= d;
        cnt1[25 - i] -= d;
        d = min(skip2, cnt2[i]);
        skip2 -= d;
        cnt2[i] -= d;
    }

    int l1 = 0, r1 = 25, l2 = 0, r2 = 25;
    while (l1 <= r1 && cnt1[l1] == 0) l1++;
    while (l1 <= r1 && cnt1[r1] == 0) r1--;
    while (l2 <= r2 && cnt2[l2] == 0) l2++;
    while (l2 <= r2 && cnt2[r2] == 0) r2--;

    if (n == 1) {
        cout << (char) ('a' + l1) << '\n';
        return 0;
    }
    string res(n, '.');
    for (int l = 0, r = n - 1; l <= r;) {
        if ((n - (r - l + 1)) % 2 == 0) {
            if (l2 > r2 || l1 < r2) {
                res[l++] = (char) ('a' + l1);
                cnt1[l1]--;
                while (l1 <= r1 && cnt1[l1] == 0) {
                    l1++;
                }
            } else {
                res[r--] = (char) ('a' + r1);
                cnt1[r1]--;
                while (l1 <= r1 && cnt1[r1] == 0) {
                    r1--;
                }
            }
        } else {
            if (l1 > r1 || l1 < r2) {
                res[l++] = (char) ('a' + r2);
                cnt2[r2]--;
                while (l2 <= r2 && cnt2[r2] == 0) {
                    r2--;
                }
            } else {
                res[r--] = (char) ('a' + l2);
                cnt2[l2]--;
                while (l2 <= r2 && cnt2[l2] == 0) {
                    l2++;
                }
            }
        }
    }
    cout << res << '\n';
}
