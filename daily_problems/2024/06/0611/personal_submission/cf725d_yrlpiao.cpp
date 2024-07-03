#include <iostream>
#include <queue>
#include <array>
#include <algorithm>
using namespace std;

#define int long long
#define ar2 array<int, 2>

ar2 arr[1 << 20] {};
void yrlpSolve() {
   	int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i][0] >> arr[i][1];
    sort(arr + 1, arr + n, greater<ar2>());
    int pos = 1, ans = 1e9;
    priority_queue<int, vector<int>, greater<int>> q;
    while (1) {
        while (pos < n && arr[pos][0] > arr[0][0]) q.push(arr[pos][1] - arr[pos++][0]);
        ans = min(ans, (long long)q.size() + 1);
        if (q.size() && arr[0][0] >= q.top()) arr[0][0] -= q.top() + 1, q.pop();
        else break;
    }
    cout << ans;
    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
