#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PDI = pair<double, int>;
using PLI = pair<ll, int>;
using PLL = pair<ll, ll>;
using PSI = pair<string, int>;
using PSS = pair<string, string>;
using PDD = pair<double, double>;
template <typename T> using max_heap = priority_queue<T>;
template <typename T> using min_heap = priority_queue<T, vector<T>, greater<>>;
#define endl '\n'

void balance_r(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr, int &indx) {
    row[indx] = 0;
    for (int j = 0; j < arr[0].size(); j++) col[j] -= arr[indx][j];
    return;
}

void back_r(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr, int &indx, ll &pre) {
    row[indx] = pre;
    for (int j = 0; j < arr[0].size(); j++) col[j] += arr[indx][j];
    return;
}

void balance_c(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr, int &indx) {
    col[indx] = 0;
    for (int i = 0; i < arr.size(); i++) row[i] -= arr[i][indx];
    return;
}

void back_c(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr, int &indx, ll &pre) {
    col[indx] = pre;
    for (int i = 0; i < arr.size(); i++) row[i] += arr[i][indx];
    return;
}

ll get_ans(vector<ll> &row, vector<ll> &col, int k, int flag) {
    int n = row.size(), m = col.size();
    ll ans = 0;
    if (flag == 0) {
        min_heap<ll> q;
        for (auto &x : row) {
            if (q.size() < k) ans += x, q.emplace(x);
            else {
                if (x > q.top()) {
                    ans -= q.top();
                    q.pop(); q.emplace(x);
                    ans += x;
                }
            }
        }
    } else {
        min_heap<ll> q;
        for (auto &x : col) {
            if (q.size() < k) ans += x, q.emplace(x);
            else {
                if (x > q.top()) {
                    ans -= q.top();
                    q.pop(); q.emplace(x);
                    ans += x;
                }
            }
        }
    }
    return ans;
}

ll row_1(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll a = row[i], cnt = row[i];
        balance_r(row, col, arr, i);
        cnt += get_ans(row, col, 3, 1);
        back_r(row, col, arr, i, a);
        ans = max(ans, cnt);
    }
    return ans;
}

ll col_1(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    ll ans = 0;
    for (int j = 0; j < m; j++) {
        ll cnt = col[j], b = col[j];
        balance_c(row, col, arr, j);
        cnt += get_ans(row, col, 3, 0);
        back_c(row, col, arr, j, b);
        ans = max(ans, cnt);
    }
    return ans;
}

ll row_2(vector<ll> &row, vector<ll> &col, vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    ll ans = 0;
     for (int i1 = 0; i1 < n; i1++) {
        ll a = row[i1];
        balance_r(row, col, arr, i1);
        for (int i2 = i1 + 1; i2 < n; i2++) {
            ll b = row[i2];
            ll cnt = a + b;
            balance_r(row, col, arr, i2);
            cnt += get_ans(row, col, 2, 1);
            back_r(row, col, arr, i2, b);
            ans = max(ans, cnt);
        }
        back_r(row, col, arr, i1, a);
    }
    return ans;
}


void solve() { 
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n, vector<int> (m));
    vector<ll> row(n), col(m);
    for (int i = 0; i < n; i++) {
        ll sum = 0;
        for (int j = 0; j < m; j++) cin >> arr[i][j], sum += arr[i][j];
        row[i] = sum;
    }
    for (int j = 0; j < m; j++) {
        ll sum = 0;
        for (int i = 0; i < n; i++) sum += arr[i][j];
        col[j] = sum;
    }
    ll ans = 0;
    if (n < 4 || m < 4) for (auto &x : row) ans += x;
    else {
        ans = get_ans(row, col, 4, 0);
        ans = max(ans, get_ans(row, col, 4, 1));
        ans = max(ans, row_1(row, col, arr));
        ans = max(ans, col_1(row, col, arr));
        ans = max(ans, row_2(row, col, arr));
    }
    cout << ans << endl;
    return ;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; t = 1;
    while (t--) solve();
    return 0;
}
