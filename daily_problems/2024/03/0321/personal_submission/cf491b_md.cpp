#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

constexpr long long inf = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int c;
    cin >> c;
    
    long long mx_ru = -inf;
    long long mx_lu = -inf;
    long long mx_rd = -inf;
    long long mx_ld = -inf;

    for (int i = 0; i < c; ++i) {
        long long x, y;
        cin >> x >> y;
        mx_ru = max(mx_ru, x + y);
        mx_lu = max(mx_lu, -x + y);
        mx_rd = max(mx_rd, x - y);
        mx_ld = max(mx_ld, -x - y);
    }

    int h;
    cin >> h;
    long long all_min = inf;
    int id = -1;
    for (int i = 0; i < h; ++i) {
        long long x, y;
        cin >> x >> y;
        int cur = max({mx_ru + (-x-y), mx_lu + (x - y), mx_rd + (-x + y), mx_ld + (x + y)});
        if (cur < all_min) {
            all_min = cur;
            id = i + 1;
        }
    }

    cout << all_min << "\n" << id << endl;

    return 0;
}