#include <bits/stdc++.h>
using namespace std;

void solveD() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<pair<int, int>> st;
    unordered_map<int, decltype(st.begin())> mp;
    for (int &x : a) {
        cin >> x;
        if (x == m) continue;
        mp[x] = st.insert({0, x}).first;
    }
    
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == m) {
            cnt++;
            while (!st.empty() && st.begin()->first < cnt) {
                mp.erase(st.begin()->second);
                st.erase(st.begin());
            }
        } else if (mp.count(a[i])) {
            int vcnt = mp[a[i]]->first;
            st.erase(mp[a[i]]);
            mp[a[i]] = st.insert({++vcnt, a[i]}).first;
        }
    }

    if (st.empty()) cout << "-1\n";
    else cout << st.begin()->second << '\n';
}

int main() {
    solveD();
    return 0;
}
