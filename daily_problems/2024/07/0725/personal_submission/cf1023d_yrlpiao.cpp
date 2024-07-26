#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int n, q;

void yrlpSolve() {
    cin >> n >> q;
    vector<int> v(n);
    for (int &x : v) cin >> x;
    vector<int> l(q + 1, -1), r(q + 1, -1);
    for (int i = 0; i < n; i++) if (v[i] != 0) {
        r[v[i]] = i;
        if (l[v[i]] == -1) l[v[i]] = i;
    }
    stack<int> st;
    int flg = 1, hq = 0, h0 = 0;
    for (int i = 0; i < n; i++) {
        h0 |= v[i] == 0;
        hq |= v[i] == q;
        if (v[i] == 0) continue;
        while (st.size() && v[i] < v[st.top()]) {
            int j = st.top(); st.pop();
            if (l[v[j]] == j && i < r[v[j]]) flg = 0;
        }
        st.push(i);
    }
    if (flg & (h0 | hq)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        return;
    }
    for (int i = 1, j = n - 2; i < n; i++, j--) {
        if (v[i] == 0) {
            if (hq == 0) v[i] = q, hq = 1;
            else v[i] = v[i - 1];
        }
        if (v[j] == 0) {
            if (hq == 0) v[j] = q, hq = 1;
            else v[j] = v[j + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) v[i] = q;
        cout << v[i] << " ";
    }
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
