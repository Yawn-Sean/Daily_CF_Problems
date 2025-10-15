#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    
    // find subsets that are easy to compare
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    /*
        先取一个前缀k-1
        然后剩下的最后一个数字从n-k+1里面选一个
    */
    sort(a.rbegin(), a.rend());
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << i + 1 << ' ';
            for (int l = 0; l < i; l++) {
                cout << a[l] << ' ';
            }
            cout << a[j] << '\n';
            if (--k == 0) {
                return 0;
            }
        }
    }
    return 0;
}
