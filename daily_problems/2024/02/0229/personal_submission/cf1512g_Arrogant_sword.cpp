// 初见积性函数。证明用算数基本定理分解就好了
#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}


//////////////////////////////////////////////////
const int N = 1e7 + 10;
signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    cin >> T;

    vector<int> d(N, -1);
    d[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (d[i] == -1) {
            d[i] = i;
            for (int j = i*i; j < N; j += i) {
                d[j] = i;
            }
        }
    }

    vector<int> phi(N);
    phi[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        int x = d[i], y = i, z = 1;
        while (y % x == 0) {
            y /= x;
            z *= x;
        }
        // 如果 i = pow(p, k), phi[i] = i + pow(p, 1) + pow(p, 2) + …… + pow(p, k)
        if (y == 1) {
            int tmp = 1;
            while (z % x == 0) {
                phi[i] += tmp;
                tmp *= x;
                z /= x;
            }
            phi[i] += tmp;
            continue;
        }
        
        phi[i] = phi[y] * phi[z];
    }
    
    vector<int> ans(N, -1);

    for (int i = 1; i < N; i ++ ) {
        if (phi[i] < N && ans[phi[i]] == -1) {
            ans[phi[i]] = i;
        }
    }

    while (T --) {
        int x;
        cin >> x;
        
        cout << ans[x] << endl;
    }
    
}