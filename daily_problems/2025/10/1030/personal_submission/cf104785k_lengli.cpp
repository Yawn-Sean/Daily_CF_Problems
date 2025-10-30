#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> idxs1, idxs2;

    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        if (x < y) idxs1.push_back(i);
        else idxs2.push_back(i);
    }

    cout << "YES\n";
    if (idxs1.size() > idxs2.size()) {
        cout << idxs1.size() << "\n";
        for (int i = 0; i < (int)idxs1.size(); ++i) {
            if (i) cout << ' ';
            cout << idxs1[i];
        }
        cout << "\n";
    } else {
        cout << idxs2.size() << "\n";
        for (int i = 0; i < (int)idxs2.size(); ++i) {
            if (i) cout << ' ';
            cout << idxs2[i];
        }
        cout << "\n";
    }

    return 0;
}
