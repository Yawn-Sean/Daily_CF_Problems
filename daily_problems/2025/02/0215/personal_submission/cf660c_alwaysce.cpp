#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        
    */
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int left = 0, cnt = 0;
    int ansL = 0, lidx = 0, ridx = -1;

    for (int right = 0; right < n; right++) {
        if (a[right] == 0) { ++cnt; }

        while (left <= right && cnt > k) {
            if (a[left] == 0) { --cnt; }
            ++left;
        }
        if (right - left + 1 > ansL) {
            ansL = right - left + 1;
            lidx = left;
            ridx = right;
        }
    }


    cout << ansL << '\n';
    for (int i = 0; i < n; i++) {
        if (lidx <= i && i <= ridx) {
            cout << 1 << ' ';
        } else {
            cout << a[i] << ' ';
        }
    }
    return 0;
}
