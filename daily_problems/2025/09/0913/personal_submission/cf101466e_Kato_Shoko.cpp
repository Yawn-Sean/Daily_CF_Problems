#include <bits/stdc++.h>
using namespace std;

vector<int> get_pi(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string t, p;
    getline(cin, t);
    getline(cin, p);
    int k;
    cin >> k;

    int n = p.size();
    int l = 1, r = n;
    int ans = 0;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        string s = p.substr(0, mid) + "#" + t;
        vector<int> pi = get_pi(s);
        
        int cnt = 0;
        for (int x : pi) {
            if (x == mid) {
                cnt++;
            }
        }
        
        if (cnt >= k) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    if (ans > 0) {
        cout << p.substr(0, ans) << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}
