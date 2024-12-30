#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str; cin >> str;
    vector<int> lpos(26, -1);
    multiset<int> elmpos;
    vector<long long> ans(26);

    for (int i = 0; i < str.size(); i++) {
        int v = str[i] - 'a';
        
        int prev = lpos[v];
        if (prev != -1) {
            elmpos.erase(elmpos.find(prev));
        }
        lpos[v] = i;
        elmpos.insert(i);

        int sz = 0;
        for (auto p = elmpos.rbegin(); p != elmpos.rend();) {
            int curpos = *p;
            p++;
            int nxtpos = ((sz == elmpos.size() - 1) ? -1 : *p) ;

            ans[sz] += curpos - nxtpos;
            sz ++;
        }
    }

    int acnt = 26;
    while (!ans[acnt - 1]) {
        acnt --;
    }

    cout << acnt << "\n";
    for (int i = 0; i < acnt; i ++) {
        cout << ans[i] << "\n";
    }

}

int main(void) {
    
    ios::sync_with_stdio(false);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}