#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MAXN = 2e5 + 10;
int arr[MAXN];
int m, n;

long long calculate(int a[]) {
    long long sum = 0;
    for (int i = 1; i < m; ++i) {
        sum += abs(a[i] - a[i + 1]);
    }
    return sum;
}

long long solve() {
    cin >> m >> n;
    int arr_min = MAXN, arr_max = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> arr[i];
        arr_min = min(arr_min, arr[i]);
        arr_max = max(arr_max, arr[i]);
    }
    long long sum = calculate(arr);
    int insert_1 = min(abs(arr[1] - 1),abs(arr[m] - 1));  // 在两端插入1的最小代价
    int insert_n = min(abs(arr[1] - n),abs(arr[m] - n));  // 在两端插入n的最小代价
    for(int i = 2;i <= m;i++) {  // 在中间插入1和n的代价
        insert_1 = min(insert_1,abs(arr[i-1] - 1) + abs(arr[i] - 1) - abs(arr[i] - arr[i-1]));
        insert_n = min(insert_n,abs(arr[i-1] - n) + abs(arr[i] - n) - abs(arr[i] - arr[i-1]));
    }
    if(arr_min > 1) {
        sum += insert_1;
    }
    if(n > arr_max) {
        sum += insert_n;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long ans = solve();
        cout << ans << endl;
    }
    return 0;
}
