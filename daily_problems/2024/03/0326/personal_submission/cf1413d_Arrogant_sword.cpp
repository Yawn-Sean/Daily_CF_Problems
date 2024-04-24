#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;

void solve(int _) 
{
    int n;
    cin >> n;
    vector<pair<char, int>> op(2*n+1);
    vector<int> tmp, a(2*n+1);
    for (int i = 1; i <= 2*n; i ++ ) {
        cin >> op[i].x;
        if (op[i].x == '+') {
            tmp.push_back(i);
        } else {
            cin >> op[i].y;
            if (tmp.empty()) {
                cout << "NO" << endl;
                return;
            }
            a[tmp.back()] = op[i].y;
            tmp.pop_back();
        }
}
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= 2*n; i ++ ) {
        if (op[i].x == '+') {
            pq.push(a[i]);
        } else {
            if (pq.empty() || op[i].y != pq.top()) {
                cout << "NO" << endl;
                return;
            }
            pq.pop();
        }
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n*2; i ++ ) {
        if (a[i] != 0) {
            cout << a[i] << ' ';
        }
    }
} 