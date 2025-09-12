#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cout << (char)('a' + __builtin_ctz(i & -i));
    }
    return 0;
}
