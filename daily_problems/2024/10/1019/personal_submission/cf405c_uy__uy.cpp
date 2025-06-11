#include<bits/stdc++.h>

using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    /*
        [x1,x2,x3]
        [x4,x5,x6]
        [x7,x8,x9]
        (x1*x1+x2*x4+x3*x7+x4*x2+x5*x5+xx6*x8+x7*x3+x8*x6+x9*x9)%2
        (x1*x1+x5*x5+x9*x9+2*(x2*x4+x3*x7+x6*x8))%2
        (x1*x1+x5*x5+x9*x9)
    */
    int n;
    cin >> n;
    vector<int>a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (i == j) {
                a[i] = x;
                cnt += (x == 1);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op;
        if (op == 1 || op == 2) {
            cin >> x;
            x--;
            if (a[x] == 0)cnt++;
            else cnt--;
            a[x] ^= 1;
        }
        else {
            cout << cnt % 2;
        }
    }

    return 0;
}
