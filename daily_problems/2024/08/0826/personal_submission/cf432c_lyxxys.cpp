#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5;
vector <int> prm, vis(N+10), join(N+10);

void solve(){
    int n;
    cin >> n;
    vector <int> nums(n), p(n);
    map <int,int> mps;
    for (int i = 0; i < n; ++ i){
        cin >> nums[i];
        mps[nums[i]] = i;
    }

    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y){
        return nums[x] < nums[y];
    });

    vector <int> temp = nums;
    vector <array<int,2>> ans;
    for (int i = 0; i < n; ++ i){
        int b = mps[nums[p[i]]];
        // mps[nums[p[i]]] 表示 第 i+1 小数字 在新数组中对应的 下标
        if (i == b) continue;
        int a = i;
        // 交换位置，更换 顺带 维护 这些数字的 下标 是什么
        mps[temp[b]] = a;
        mps[temp[a]] = b;
        swap(temp[a], temp[b]);

        if (a > b) swap(a, b);
        if (!vis[b-a+1]){
            ans.push_back({a, b});
        } else {
            int dis = b-a+2;
            // 对 奇偶 分情况讨论
            if (dis%2){
                // x + y = b-a-1+2 = b-a+1 = dis-1
                int L = join[dis-1];
                ans.push_back({a, a+L-1});
                ans.push_back({a+L-1, b-1});
                ans.push_back({b-1, b});
                ans.push_back({a+L-1, b-1});
                ans.push_back({a, a+L-1});
            } else {
                // x+y = b-a+2 = dis
                int L = join[dis];
                ans.push_back({a, a+L-1});
                ans.push_back({a+L-1, b});
                ans.push_back({a, a+L-1});
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &it : ans){
        cout << it[0]+1 << " " << it[1]+1 << "\n";
    }
}

int main(){
    for (int i = 2; i <= N; ++ i){
        if (!vis[i]) prm.push_back(i);
        for (auto &x : prm){
            if (1ll*x*i > N) break;
            vis[x*i] = 1;
            if (i%x == 0) break;
        }
    }
    for (int i = 2; i <= N; ++ i){
        if (!vis[i]) join[i] = i;
        else if (i%2) continue;
        else 
            for (auto &x : prm){
                int y = i-x;
                // 找拼成 偶数 的 两个素数
                assert(y > 0);
                if (!vis[y]){
                    join[i] = y;
                    break;
                }
            }
    }
    int _ = 1;
    while (_--)
        solve();
    return 0;
}
