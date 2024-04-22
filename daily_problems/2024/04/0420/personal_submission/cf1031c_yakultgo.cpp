#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int a, b;
    cin >> a >> b;
    // 先找到最大的n使得n*(n+1)/2 <= a+b
    int n = 0;
    ll sum = 0;
    for (int i = 1;; i++) {
        sum += i;
        if (sum > a + b) {
            n = i - 1;
            break;
        }
    }
    // 然后将这n个任务分配给a和b
    // 将a的时间刚好利用完，则剩下的一定可以在b中完成
    vector<int> ansa, ansb;
    for (int i = n; i >= 1; i--) {
        if (a >= i) {
            a -= i;
            ansa.push_back(i);
        } else {
            b -= i;
            ansb.push_back(i);
        }
    }
    cout << ansa.size() << endl;
    for (int i = 0; i < ansa.size(); i++) {
        cout << ansa[i] << " ";
    }
    cout << endl;
    cout << ansb.size() << endl;
    for (int i = 0; i < ansb.size(); i++) {
        cout << ansb[i] << " ";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}