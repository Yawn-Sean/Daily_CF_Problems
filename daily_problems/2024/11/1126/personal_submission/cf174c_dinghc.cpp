#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> diff(n + 1, 0);
    diff[0] = a[0];
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
    }
    diff[n] = -a[n - 1];
    vector<int> inc, desc;
    for (int i = 0; i <= n; i++) {
        if (diff[i] > 0) {
            for (int j = 0; j < diff[i]; j++) {
                inc.push_back(i + 1);
            }
        } else {
            for (int j = 0; j < -diff[i]; j++) {
                desc.push_back(i);
            }
        }
    }
    cout << inc.size() << "\n";
    for (int i = 0; i < inc.size(); i++) {
        cout << inc[i] << " " << desc[i] << "\n";
    }
    return 0;
}

