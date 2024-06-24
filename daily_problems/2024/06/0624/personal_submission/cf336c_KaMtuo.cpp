#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

vector<int> one[N];
int n;
int a[N];
bool st[N][32];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        for (int j = 0; j < 31; j ++) {
            if ((a[i] >> j) & 1) one[j].push_back(a[i]); 
        }
    } 
    // cout << (1 << 30) << endl;
    // cout << 1 << endl;
    // for (int i = 0; i < one[0].size(); i ++) cout << one[0][i] << endl;
    bool ok = false;
    for (int i = 30; i >= 0; i --) {
        int now = -1;
        if (one[i].size()) now = one[i][0];
        for (int j = 1; j < one[i].size(); j ++) {
            now &= one[i][j];
        } 
        if (now % (1 << i) == 0) {
            cout << one[i].size() << endl;
            for (int j = 0; j < one[i].size(); j ++) cout << one[i][j] << ' ';
            ok = true;
            break;
        }
    }
    if (ok == false) cout << -1 << endl;
    // cout << (20 & 22) << endl;
    return 0;
}
// 10100 10110
