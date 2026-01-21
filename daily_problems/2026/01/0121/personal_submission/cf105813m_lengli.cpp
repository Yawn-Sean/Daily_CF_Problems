#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> digits = {1,2,3,4,5,6,7,8,9,0};

    while(t--){
        string s;
        cin >> s;

        vector<int> ans;
        for(char ch : s){
            int c = ch - '0';
            for(int rep = 0; rep < 2; ++rep){
                for(int x : digits){
                    if(x != c){
                        ans.push_back(x);
                    }
                }
            }
            ans.push_back(c);
        }

        if(!ans.empty()) ans.pop_back();

        for(int x : ans) cout << x;
        cout << "\n";
    }

    return 0;
}
