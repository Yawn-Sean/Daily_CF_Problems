#include <bits/stdc++.h>
using namespace std;

vector<int> prefix_function(const vector<int>& p) {
    int n = p.size();
    vector<int> pi(n, 0);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j > 0 && p[j] != p[i]) {
            j = pi[j - 1];
        }
        if (p[j] == p[i]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string str;
        cin >> str;

        vector<int> s;
        for (char c : str) {
            s.push_back(c - '0');
        }
        s.push_back(-1);
        for (int i = 0; i < n; i++) {
            s.push_back(s[i] ^ 1);
        }

        vector<int> pi = prefix_function(s);

        for (int i = n + 1; i < (int)pi.size(); i++) {
            cout << pi[i];
            if (i + 1 < (int)pi.size()) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}
