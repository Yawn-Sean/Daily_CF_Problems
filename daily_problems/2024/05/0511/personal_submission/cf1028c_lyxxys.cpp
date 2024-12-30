#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 2e9;
struct matrix {
    int x1 = -INF, y1 = -INF, x2 = INF, y2 = INF;
};

void solve(){ 
    int n;
    cin >> n;
    vector <matrix> vec(1), Pre(n+1), Suf(n+2);
    for (int i = 0; i < n; ++ i){
        matrix c;
        cin >> c.x1 >> c.y1 >> c.x2 >> c.y2;
        vec.push_back(c);
    }

    auto insect = [](matrix a, matrix b)->matrix{
        matrix c;
        c.x1 = max(a.x1, b.x1), c.y1 = max(a.y1, b.y1);
        c.x2 = min(a.x2, b.x2), c.y2 = min(a.y2, b.y2);
        return c;
    };
    auto check = [](matrix c)->bool{
        return c.x1 <= c.x2 && c.y1 <= c.y2;
    }; 
    for (int i = 1; i <= n; ++ i) Pre[i] = insect(Pre[i-1], vec[i]);
    for (int i = n; i >= 1; -- i) Suf[i] = insect(Suf[i+1], vec[i]);

    for (int i = 1; i <= n; ++ i){
        matrix c = insect(Pre[i-1], Suf[i+1]);
        if (check(c)){
            cout << c.x1 << " " << c.y1 << "\n";
            return;
        }
    }
    return;
}
