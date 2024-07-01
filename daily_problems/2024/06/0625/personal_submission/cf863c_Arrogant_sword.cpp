
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int> vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

int check(int a, int b) {
    if (a == 3 && b == 2) return 1;
    if (a == 2 && b == 1) return 1;
    if (a == 1 && b == 3) return 1;
    if (a == b) return -1;
    return 0;
}

void solve(int _) 
{
    int k, a, b;
    cin >> k >> a >> b;

    vector A(4, vector<int>(4)), B(4, vector<int>(4)), vis(4, vector<int>(4));
    rep(i, 3) {
        rep(j, 3) {
            cin >> A[i][j];
        }
    }
    rep(i, 3) {
        rep(j, 3) {
            cin >> B[i][j];
        }
    }
    vis[a][b] = 1;
    vector<int> tracka(100), trackb(100);
    tracka[1] = a, trackb[1] = b;
    int now = 1, scorea = 0, scoreb = 0;
    int res = check(a, b);
    if (res != -1) {
        scorea += res; scoreb += res ^ 1;
    }
    k --;
    while (k) {
        int x = A[a][b], y = B[a][b];
        now ++; tracka[now] = x; trackb[now] = y;
        if (vis[x][y]) {
            break;
        }
        vis[x][y] = 1;
        res = check(x, y);
        if (res != -1) {
            scorea += res; scoreb += res ^ 1;
        }
        a = x; b = y;
        k --;
    } 

    int ea = tracka[now], eb = trackb[now];
    now --;
    int len = 0, addA = 0, addB = 0;
    while (now) {
        len ++;
        int x = tracka[now], y = trackb[now];
        res = check(x, y);
        if (res != -1) {
            addA += res; addB += res ^ 1;
        }
        if (x == ea && y == eb) {
            break;
        }
        now --;
    }

    if (len != 0) {
        scorea += (k / len) * addA; scoreb += (k / len) * addB;
        k %= len;
    }

    while (k > 0) {
        int x = tracka[now], y = trackb[now];
        res = check(x, y);
        if (res != -1) {
            scorea += res; scoreb += res ^ 1;
        }
        k --; now ++;
    }

    cout << scorea << ' ' << scoreb << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
#define rep(i, n) for (int i = 1; i <= n; i ++)
#define rep0(i, n) for (int i = 0; i < n; i ++)

using namespace std;
void print(vector<int> vi, int st, int ed)
{
    for (int i = st; i <= ed; i ++ ) cout << vi[i] << ' ';
    cout << endl;
}

void print(vector<int>& vi) {
    for (auto t: vi) {
        cout << t << ' ';
    }
    cout << endl;
}

//////////////////////////////////////////////////
const int N = 2e5 + 10;

int check(int a, int b) {
    if (a == 3 && b == 2) return 1;
    if (a == 2 && b == 1) return 1;
    if (a == 1 && b == 3) return 1;
    if (a == b) return -1;
    return 0;
}

void solve(int _) 
{
    int k, a, b;
    cin >> k >> a >> b;

    vector A(4, vector<int>(4)), B(4, vector<int>(4)), vis(4, vector<int>(4));
    rep(i, 3) {
        rep(j, 3) {
            cin >> A[i][j];
        }
    }
    rep(i, 3) {
        rep(j, 3) {
            cin >> B[i][j];
        }
    }
    vis[a][b] = 1;
    vector<int> tracka(100), trackb(100);
    tracka[1] = a, trackb[1] = b;
    int now = 1, scorea = 0, scoreb = 0;
    int res = check(a, b);
    if (res != -1) {
        scorea += res; scoreb += res ^ 1;
    }
    k --;
    while (k) {
        int x = A[a][b], y = B[a][b];
        now ++; tracka[now] = x; trackb[now] = y;
        if (vis[x][y]) {
            break;
        }
        vis[x][y] = 1;
        res = check(x, y);
        if (res != -1) {
            scorea += res; scoreb += res ^ 1;
        }
        a = x; b = y;
        k --;
    } 

    int ea = tracka[now], eb = trackb[now];
    now --;
    int len = 0, addA = 0, addB = 0;
    while (now) {
        len ++;
        int x = tracka[now], y = trackb[now];
        res = check(x, y);
        if (res != -1) {
            addA += res; addB += res ^ 1;
        }
        if (x == ea && y == eb) {
            break;
        }
        now --;
    }

    if (len != 0) {
        scorea += (k / len) * addA; scoreb += (k / len) * addB;
        k %= len;
    }

    while (k > 0) {
        int x = tracka[now], y = trackb[now];
        res = check(x, y);
        if (res != -1) {
            scorea += res; scoreb += res ^ 1;
        }
        k --; now ++;
    }

    cout << scorea << ' ' << scoreb << endl;
} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}