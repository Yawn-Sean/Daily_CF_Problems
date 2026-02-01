#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> bin_2s;

    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        char source = 'A', tmp = 'C', target = 'B';
        vector<int> bin_2;
        for (int j = (int)s.size() - 1; j >= 0; j--) {
            char c = s[j];
            if (c == target) {
                bin_2.push_back(1);
                swap(source, tmp);
            } else {
                bin_2.push_back(0);
                swap(tmp, target);
            }
        }

        bin_2s.push_back(bin_2);
    }

    int best = 0;
    for (int i = 1; i < m; i++) {
        if (bin_2s[i] > bin_2s[best]) {
            best = i;
        }
    }

    cout << best + 1 << "\n";
    return 0;
}
