#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
struct Info {
    vector <int> vet;
    int p;
};

void solve(){
    int n;
    cin >> n;
    vector <Info> curs;
    curs.push_back({{}, 0});
    vector<vector<int>> ans;

    auto chk = [&](int x)->bool{
        assert(curs.size());
        return curs.back().p == x-1;
    };

    for (int i = 0, x; i < n; ++ i){
        cin >> x;
        while (!chk(x)) curs.pop_back();

        auto j = curs.back();
        curs.pop_back();
        j.p += 1, curs.push_back(j);
        assert(j.p == x);

        j.vet.push_back(x), j.p = 0;
        curs.push_back(j);

        ans.push_back(j.vet);
    }

    for (auto &vec : ans){
        int len = vec.size();
        for (int i = 0; i < len; ++ i){
            if (i) cout << ".";
            cout << vec[i];
        }
        cout << "\n";
    }
}
