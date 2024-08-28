#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+11;
struct dot {
    int x, y, z, id;
};
void solve(){
    int n;
    cin >> n;
    vector <dot> dots(n);
    {
        int i = 0;
        for (auto &it : dots){
            cin >> it.x >> it.y >> it.z;
            it.id = ++ i;
        }
    }

    auto cmpX = [&](dot &a, dot &b)->bool{
        return a.x < b.x;
    };
    auto cmpY = [&](dot &a, dot &b)->bool{
        return a.y < b.y;
    };
    auto cmpZ = [&](dot &a, dot &b)->bool{
        return a.z < b.z;
    };
    vector <array<int,2>> ans;
    // 自底向上来说 z坐标, y坐标，x坐标 相同的 递归的去删 ，不同的排序去删
    auto deleZ = [&](vector <dot> &dots)->int{
        int n = dots.size(), p = -1;  // 删除干净返回-1， 不干净返回是哪一个 没有删去
        sort(dots.begin(), dots.end(), cmpZ);
        int i = 0;
        while (i+1 < n){
            assert(dots[i].z != dots[i+1].z);
            ans.push_back({dots[i].id, dots[i+1].id});
            i += 2;
        }
        if (i < n) p = dots.back().id;
        return p;
    };
    auto deleY = [&](vector <dot> & dots)->int{
        int n = dots.size();
        sort(dots.begin(), dots.end(), cmpY);
        vector <int> dY;
        for (int i = 0, p; i < n; ++ i){
            vector <dot> dotY;
            while (i <= n-2 && dots[i].y == dots[i+1].y){
                dotY.push_back(dots[i]);
                ++ i;
            }
            dotY.push_back(dots[i]);
            if (dotY.size() > 1) p = deleZ(dotY);
            else p = dots[i].id;
            if (p != -1){
                dY.push_back(p);
            }
        }
        int i = 0, p = -1;
        while (i+1 < dY.size()){
            ans.push_back({dY[i], dY[i+1]});
            i += 2;
        }
        if (i < dY.size()) p = dY.back();
        return p;
    };

    sort(dots.begin(), dots.end(), cmpX);
    // 当 p 为 -1时 表示 删干净了
    vector <int> dX;
    for (int i = 0, p = -1; i < n; ++ i){
        vector <dot> dotX;
        while (i <= n-2 && dots[i].x == dots[i+1].x){
            dotX.push_back(dots[i]);
            ++ i;
        }
        dotX.push_back(dots[i]);
        if (dotX.size() > 1) p = deleY(dotX);
        else p = dots[i].id;
        if (p != -1){
            dX.push_back(p);
        }
    }

    assert(dX.size()%2 == 0);
    int i = 0;
    while (i+1 < dX.size()){
        ans.push_back({dX[i], dX[i+1]});
        i += 2;
    }
    for (auto &it : ans){
        if (it[0] > it[1]) swap(it[0], it[1]);
        cout << it[0] << " " << it[1] << "\n";
    }
}
