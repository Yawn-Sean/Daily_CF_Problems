#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << setprecision(12);
    
    int n, U;
    cin >> n >> U;

    vector<int> energies(n);
    for (auto& e : energies) {
        cin >> e;
    }

    double ans = 1.0;
    for (int i = 0, k = 2; i < n - 1; i++) {
        while (k + 1 < n && energies[k + 1] - energies[i] <= U) {
            k += 1;
        }
        if (energies[k] - energies[i] <= U) {
            ans = min(ans, static_cast<double>(energies[i + 1] - energies[i]) / (energies[k] - energies[i]));
        }
    }

    if (ans == 1.0) {
        cout << "-1\n";
    } else {
        cout << 1.0 - ans << "\n";
    }

    return 0;
}

