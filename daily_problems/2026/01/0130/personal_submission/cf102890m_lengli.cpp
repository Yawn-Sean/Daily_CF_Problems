#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;                  
    vector<int> s;
    for(char c : S) s.push_back((c - '0') - 1);

    vector<int> cnt(9);
    for(int i = 0; i < 9; i++) cin >> cnt[i];  

    int n = s.size();
    vector<vector<int>> acc(9, vector<int>(n+1, 0));
    vector<vector<int>> next_pos(9, vector<int>(n+1, n));

    for(int i = n - 1; i >= 0; --i){
        for(int j = 0; j < 9; ++j){
            next_pos[j][i] = next_pos[j][i + 1];
            acc[j][i] = acc[j][i + 1];
        }
        next_pos[s[i]][i] = i;
        acc[s[i]][i] += 1;
    }

    for(int i = 0; i < n; ++i){
        cnt[s[i]] -= 1;
    }
    for(int i = 0; i < 9; ++i){
        cnt[i] = -cnt[i];
    }

    vector<int> ans;
    int total = 0;
    for(int i = 0; i < 9; ++i) total += cnt[i];

    int pt = 0;
    for(int step = 0; step < total; ++step){
        for(int i = 8; i >= 0; --i){
            int npt = next_pos[i][pt];
            bool flg = true;

            for(int j = 0; j < 9; ++j){
                if(acc[j][npt] < cnt[j]){
                    flg = false;
                    break;
                }
            }

            if(flg && cnt[i] > 0){
                ans.push_back(i + 1);
                cnt[i]--;
                pt = npt + 1;
                break;
            }
        }
    }

    for(int x : ans) cout << x;
    cout << '\n';

    return 0;
}
