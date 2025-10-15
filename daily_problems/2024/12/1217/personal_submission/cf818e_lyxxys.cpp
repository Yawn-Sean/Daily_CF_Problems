#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}


void solve(){
    int n, k;
    cin >> n >> k;
    
    vector <int> fas, cnts;
    for (i64 i = 2; i*i <= k; ++ i){
        if (k%i == 0){
            int j = 0;
            while (k%i == 0){
                k /= i;
                j += 1;
            }
            fas.push_back(i);
            cnts.push_back(j);
        }
    }
    if (k > 1){
        fas.push_back(k);
        cnts.push_back(1);
    }

    int m = fas.size();
    vector<vector<int>> As(n+1);
    for (int i = 1, x; i <= n; ++ i){
        cin >> x;
        for (auto &y : fas){
            int c = 0;
            while (x%y == 0){
                x /= y;
                c += 1;
            }
            As[i].push_back(c);
        }
        assert(As[i].size() == m);
    }

    vector <int> curs(m);
    auto chge = [&](int id, int v)->void{
        for (int i = 0; i < m; ++ i){
            curs[i] += v*As[id][i];
        }
    };
    auto chk = [&]()->bool{
        for (int i = 0; i < m; ++ i){
            if (curs[i] < cnts[i]){
                return false;
            }
        }
        return true;
    };

    i64 res = 0;
    for (int i = 1, j = 0; i <= n; ++ i){
        while (j < i || (j+1 <= n && !chk())){
            j += 1;
            chge(j, 1);
        }
        if (chk()) res += n-j+1;
        chge(i, -1);
    }

    cout << res << "\n";
}
