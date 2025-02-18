// submission link: https://codeforces.com/problemset/submission/1660/272638176
// 难得能把羊蹄自己做出来hhh

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    string s;
    int n, sum = 0, mx = 0;
    cin >> n;
    vector<int> f (n);
    for (int i = 0; i < n; i ++) {
        cin >> s;
        for (int j = 0; j < n; j ++) {
            int num = s[j] - '0';
            sum += num;
            f[(j - i + n) % n] += num;
        }
    }
    mx = *max_element(f.begin(), f.end());
    cout << sum - mx + n - mx << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int check;
    cin >> check;
    while (check --) {
        solve();
    }

    return 0;
}