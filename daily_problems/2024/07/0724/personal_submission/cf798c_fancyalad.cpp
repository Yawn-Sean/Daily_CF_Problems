// submission link: https://codeforces.com/contest/798/submission/272251131

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, g = 0;
    cin >> n;
    vector<int> nums (n);
    int cnt = 0, ans = 0;
    for (auto& num : nums) {
        cin >> num;
        g = __gcd(g, num);
        if (num % 2) {
            cnt ++;
        } else {
            ans += cnt / 2 + cnt % 2 * 2;
            cnt = 0;
        }
    }
    cout << "YES" << endl;
    if (g > 1) {
        cout << 0 << endl;
    } else {
        ans += cnt / 2 + cnt % 2 * 2;
        cout << ans << endl;
    }
    return 0;
}