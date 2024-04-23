#include <bits/stdc++.h>
using namespace std;

struct Info{
    int sh;
    int s;
    int h;
};

void work(){
    int n; cin >> n;
    vector<Info> info(n);

    for(int i = 0; i < n; i ++){
        string buff; cin >> buff;
        int lh = 0;
        int ans = 0;
        for(int p = 0; p < buff.size(); p++){
            lh += (buff[p]=='h');
        }
        info[i].h = lh;
        info[i].s = buff.size() - lh;
        for(int p = 0; p < buff.size(); p ++){
            if(buff[p] == 's'){
                ans += lh;
            } else {
                lh --;
            }
        }
        info[i].sh = ans;
    }
    sort(info.begin(), info.end(), [](auto a, auto b) {
        return 1ll * a.s * b.h > 1ll * b.s * a.h;
    });

    int tth = 0;
    for(int i = 0; i < n; i++){
        tth += info[i].h;
    }
    long long otpt = 0;
    for(int i = 0; i < n; i++){
        otpt += info[i].sh;
        tth -= info[i].h;
        otpt += 1ll * info[i].s * tth;
    }
    cout << otpt << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}