#include <bits/stdc++.h>
using namespace std;
int jgs(f64 x){
    return (x < -eps ? -1 : x >= eps);
}
void print(vector <int> &A){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i];
    }
}

void solve(){
    int n, t;
    cin >> n;
    vector <int> stk(n+1), vis(n), A(n);
    for (auto &x : A){
        cin >> x;
    }

    cin >> t;
    for (int i = 0,x; i < t; ++ i){
        cin >> x;
        x -= 1;
        vis[x] = 1;
    }

    int top = 0;
    for (int i = n-1; i >= 0; -- i){
        if (vis[i]){
            stk[++ top] = i;
            A[i] = -A[i];
        } else if (top > 0 && A[stk[top]] == -A[i]){
            top -= 1;
        } else {
            stk[++ top] = i;
            A[i] = -A[i];
        }
    }

    if (top > 0) cout << "NO\n";
    else {
        cout << "YES\n";
        print(A);
        cout << "\n";
    }
}
