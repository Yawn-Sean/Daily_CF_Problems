#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    int total = 0, neg = 0, mi = INT_MAX;
    for (int i = 0; i < n * 2 - 1; i++) {
        int a;
        cin >> a;
        if (a < 0) {
            a = -a;
            neg++;
        }
        total += a;
        mi = min(mi, a);
    }

    if (n % 2 == 0 && neg % 2 == 1) {
        total -= 2 * mi;
    }

    cout << total << "\n";    

    return 0;
}

