#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    if(!(cin >> n)) return 0;

    struct P{int x,y,v;};
    vector<P> pts(n);

    unordered_map<int,long long> col,row;
    col.reserve(n*2); row.reserve(n*2);

    for (int i=0;i<n;i++){
        int x,y,v; cin>>x>>y>>v;
        pts[i]={x,y,v};
        col[x]+=v; row[y]+=v;
    }

    // 排序得到所有列/行按权值降序
    vector<pair<long long,int>> cx, cy;
    cx.reserve(col.size()); cy.reserve(row.size());
    for (auto &kv: col) cx.push_back({kv.second, kv.first});
    for (auto &kv: row) cy.push_back({kv.second, kv.first});
    sort(cx.begin(), cx.end(), greater<>());
    sort(cy.begin(), cy.end(), greater<>());

    long long ans=0;

    // 0+3（同向三条）
    long long s=0;
    for(int i=0;i<3 && i<(int)cx.size();i++){ s+=cx[i].first; ans=max(ans,s); }
    s=0;
    for(int i=0;i<3 && i<(int)cy.size();i++){ s+=cy[i].first; ans=max(ans,s); }

    // 建索引：每行有哪些(列,值)，每列有哪些(行,值)
    unordered_map<int, vector<pair<int,int>>> inRow, inCol;
    inRow.reserve(n*2); inCol.reserve(n*2);
    for (auto &p: pts){
        inRow[p.y].push_back({p.x,p.v});
        inCol[p.x].push_back({p.y,p.v});
    }

    auto best2_sum = [](const vector<long long>& vals){
        long long a=0,b=0;
        for(long long t: vals){
            if(t>a){ b=a; a=t; }
            else if(t>b){ b=t; }
        }
        return a+b;
    };

    // 1 行 + 2 列
    for (auto &kv: inRow){
        int y = kv.first;
        auto &vec = kv.second;                 // 这一行的 (x,v)
        int k = (int)vec.size();
        int take = min<int>(cx.size(), k+2);   // ☆ 关键：动态取前 k+2 个列

        unordered_set<int> used; used.reserve(k*2 + take*2);
        unordered_map<int,int> onrow; onrow.reserve(k*2+1);
        for(auto &pr: vec) onrow[pr.first]=pr.second;

        vector<long long> cand; cand.reserve(k + take);

        // 来自全局前 (k+2) 列
        for(int i=0;i<take;i++){
            int x = cx[i].second;
            if(used.insert(x).second){
                long long val = col[x] - (onrow.count(x)? onrow[x] : 0);
                cand.push_back(val);
            }
        }
        // 来自本行出现过的列（可能不在全局前 (k+2) 内）
        for(auto &pr: vec){
            int x = pr.first;
            if(used.insert(x).second){
                long long val = col[x] - pr.second;
                cand.push_back(val);
            }
        }
        ans = max(ans, row[y] + best2_sum(cand));
    }

    // 1 列 + 2 行（对称）
    for (auto &kv: inCol){
        int x = kv.first;
        auto &vec = kv.second;                 // 这一列的 (y,v)
        int k = (int)vec.size();
        int take = min<int>(cy.size(), k+2);   // ☆ 动态取前 k+2 个行

        unordered_set<int> used; used.reserve(k*2 + take*2);
        unordered_map<int,int> oncol; oncol.reserve(k*2+1);
        for(auto &pr: vec) oncol[pr.first]=pr.second;

        vector<long long> cand; cand.reserve(k + take);

        for(int i=0;i<take;i++){
            int y = cy[i].second;
            if(used.insert(y).second){
                long long val = row[y] - (oncol.count(y)? oncol[y] : 0);
                cand.push_back(val);
            }
        }
        for(auto &pr: vec){
            int y = pr.first;
            if(used.insert(y).second){
                long long val = row[y] - pr.second;
                cand.push_back(val);
            }
        }
        ans = max(ans, col[x] + best2_sum(cand));
    }

    cout << ans << "\n";
    return 0;
}
