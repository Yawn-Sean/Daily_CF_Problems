#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl; 
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;

    int pos1 = 1;
    for (int i = 2; i <= n; ++i) {
        if (query(pos1, i) != pos1) {
            pos1 = i;
        }
    }

    vector<int> cur;
    cur.reserve(n);
    for (int i = 1; i <= n; ++i) {
        if (i != pos1) {
            cur.push_back(i);
        }
    }

    vector<int> ans;

    while (!cur.empty()) {
        vector<int> ncur;
        int prime_val = cur[0];
        for (size_t i = 1; i < cur.size(); ++i) {
            int v = query(prime_val, cur[i]);

            if (v == pos1) {
                ncur.push_back(cur[i]);
            } else {
                prime_val = v;
            }
        }

        cur = ncur;
        ans.push_back(prime_val);
    }

    cout << "! " << ans.size();
    for (int x : ans) {
        cout << " " << x;
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
