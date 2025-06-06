#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, x1, x2;
    cin >> n >> x1 >> x2;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return a[i] < a[j];
    });


    for (int i = 0; i < n; i++) {
        i64 cur = a[order[i]];
        i64 need1 = (x1 / cur) + (x1 % cur != 0);
        if (i + need1 < n) {
            i64 cur2 = a[order[i + need1]];
            i64 left2 = (n - (i + need1));
            if (1ll * left2 * cur2 >= 1ll * x2) {
                cout << "Yes" << endl;
                cout << need1 << " " << left2 << endl;
                for (int j = 0; j < need1; j++) {
                    cout << order[i + j] + 1 << " ";
                }
                cout << endl;
                for (int j = 0; j < left2; j++) {
                    cout << order[i + need1 + j] + 1 << " ";
                }
                cout << endl;

                return 0;
            }
        }

        
        cur = a[order[i]];
        need1 = (x2 / cur) + (x2 % cur != 0);
        if (i + need1 < n) {
            i64 cur2 = a[order[i + need1]];
            i64 left2 = (n - (i + need1));
            if (1ll * left2 * cur2 >= 1ll * x1) {
                cout << "Yes" << endl;
                cout << left2 << " " << need1 << endl;
                
                for (int j = 0; j < left2; j++) {
                    cout << order[i + need1 + j] + 1 << " ";
                }
                cout << endl;
                for (int j = 0; j < need1; j++) {
                   cout << order[i + j] + 1 << " ";
                }   
                cout << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
