#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
        if (a * c * e < b * d * f || (a == 0 && b > 0 && d > 0) || (c == 0 && d > 0)) {
            cout << "Ron" << "\n";
        } else {
            cout << "Hermione" << "\n";
        }

    return 0;
}
