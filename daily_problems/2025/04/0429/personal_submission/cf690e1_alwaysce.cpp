#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    while(q--){
        int h, w;
        cin >> h >> w;
        vector<vector<int>> pixels(h, vector<int>(w));
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> pixels[i][j];
            }
        }

        // 计算中间行   
        int mid = h / 2;
        int x1 = mid - 1, x2 = mid;
        if (x1 < 0) {
            cout << "NO" << endl;
        } else {
            double tot = 0;
            for (int i = 0; i < h - 1; i++) {
                for (int j = 0; j < w; j++) {
                    tot += abs(pixels[i][j] - pixels[i+1][j]);
                }
            }
            double threshold = tot / ((h - 1) * w);

            double tmp = 0;   
            for (int j = 0; j < w; j++) {
                tmp += abs(pixels[x1][j] - pixels[x2][j]);
            }
            tmp /= w;

            double RATIO = 1.50;
            if (tmp >= RATIO * threshold) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}


    
