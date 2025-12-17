#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &x : a) cin >> x;

        sort(a.begin(), a.end(), greater<int>());

        vector<vector<int>> groups(n);
        map<int, int> cnt;

        for (int x : a) {
            groups[cnt[x]].push_back(x);
            ++cnt[x];
        }

        reverse(a.begin(), a.end());

        for (int x : a) cout << x << ' ';
        cout << '\n';

        for (const auto &g : groups)
            for (int x : g)
                cout << x << ' ';
        cout << '\n';
    }

    return 0;
}
