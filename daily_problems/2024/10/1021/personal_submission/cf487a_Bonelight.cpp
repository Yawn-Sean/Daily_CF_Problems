/*
    Bonelight * v *
    20241017：CF,Goodnight
    No Coding , No Bug
*/
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int hp1, atk1, def1; int hp2, atk2, def2; int cHp, cAtk, cDef;
    cin >> hp1 >> atk1 >> def1 >> hp2 >> atk2 >> def2 >> cHp >> cAtk >> cDef;

    int cost;
    {
        int chAtk = max(0ll, def2 + 1 - atk1);
        atk1 += chAtk;
        cost = chAtk * cAtk;
    }

    int rnd1 = max(0ll, atk2 - def1), rnd2 = max(0ll, atk1 - def2);
    int addC = INF;
    for(int chDef = 0; chDef <= rnd1; chDef ++){
        for(int chAtk = 0; chAtk <= 100; chAtk ++){ // 破甲Atk + 100 = 秒杀 
            int oRnd1 = max(0ll, rnd1 - chDef), oRnd2 = rnd2 + chAtk;
            int nRnd = (hp2 + oRnd2 - 1) / oRnd2;
            int chHp = max(0ll, nRnd * oRnd1 + 1 - hp1);
            addC = min(addC, chDef * cDef + chAtk * cAtk + chHp * cHp);
        }
    }

    cout << addC + cost << endl;
}

signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
    cerr << "整个程序运行时间: " << double(clock()) << " ms" << endl;
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
