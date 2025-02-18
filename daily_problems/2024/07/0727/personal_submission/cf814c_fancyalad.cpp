#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> saved(26, vector<int>(n + 1));
    for (int ci = 0; ci < 26; ci ++) {
        char c = 'a' + ci;
        for (int mi = 0; mi <= n; mi ++) {
            int i = 0, j = 0, m = mi;
            while (j < n) {
                if (s[j] != c) {
                    if (m) {
                        m --;
                    } else {
                        while (i < j && s[i ++] == c);
                    }
                }
                saved[ci][mi] = max(saved[ci][mi], j - i + 1);
                j ++;
            }
        }
    }

    int q, m;
    char c;
    cin >> q;
    while (q --) {
        cin >> m >> c;
        cout << saved[c - 'a'][m] << endl;
    }

    return 0;
}