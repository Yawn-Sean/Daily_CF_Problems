#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1505, mod = 1e9 + 7, inf = 1e9;
/*
    将两个矩形的问题划分成两个一个矩形的问题
 */
void solve(){
    int n;
    cin >> n;
    auto ops = [&](int x1, int y1, int x2, int y2)->int{
        cout << "? " << x1 << " " << y1 << " "<< x2 << " " << y2 << "\n" << flush;
        int cnt;
        cin >> cnt;
        return cnt;
    };

    vector <int> ans;
    int up = n;
    auto findrec = [&](int x1, int x2, int y1, int y2)->void{
        int l = x1, r = x2;
        while (l < r){
            int mid = l+r+1 >> 1;
            if (ops(mid,y1,x2,y2) >= 1) l = mid;
            else r = mid-1;
        }
        ans.push_back(l);
        l = y1, r = y2;
        while (l < r){
            int mid = l+r+1 >> 1;
            if (ops(x1,mid,x2,y2) >= 1) l = mid;
            else r = mid-1;
        }
        ans.push_back(l);
        l = x1, r = x2;
        while (l < r){
            int mid = l+r >> 1;
            if (ops(x1,y1,mid,y2) >= 1) r = mid;
            else l = mid+1;
        }
        ans.push_back(l);
        l = y1, r = y2;
        while (l < r){
            int mid = l+r >> 1;
            if (ops(x1,y1,x2,mid) >= 1) r = mid;
            else l = mid+1;
        }
        ans.push_back(l);
    };

    int l = 1, r = n;
    while (l < r){
        int mid = l+r >> 1;
        if (ops(1,1,mid,up) >= 1) r = mid;
        else l = mid+1;
    }
    // 特别需要特判 l < n，不然查询的时候会wa
    if (l < up && ops(l+1,1,up,up) >= 1){
        findrec(1,l,1,up);
        findrec(l+1,up,1,up);
    } else {
        l = 1, r = n;
        while (l < r){
            int mid = l+r >> 1;
            if (ops(1,1,up,mid) >= 1) r = mid;
            else l = mid+1;
        }
        findrec(1,up,1,l);
        findrec(1,up,l+1,up);
    }

    cout << "! ";
    for (auto &x : ans) cout << x << " ";
    cout << "\n" << flush;
}
