/*
 https://codeforces.com/problemset/problem/67/B
 B. Restoration of the Permutation
 Solver: nhant
 2025-05-13 15:31:11
 https://codeforces.com/problemset/submission/67/319475385, O(N^2)
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (int& x : b) {
        cin >> x;
    }
    for (int i = n - 1; i >= 0; i--) {
        int j = i;
        while (b[i] > 0 && j + 1 < n) {
            j++;
            if (a[j] >= i + 1 + k) {
                b[i]--;
            }
            a[j - 1] = a[j];
        }
        a[j] = i + 1;
    }
    for (int v : a) {
        cout << v << " ";
    }
    cout << '\n';
}
