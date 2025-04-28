/*
沙发的摆放要么是横着的，要么是竖着的
沙发可能既在上又在下，可能既在左又在右，但四个肯定不可能同时满足
对于某个沙发，如何快速计算其上、下、左、右各有几个沙发？
计算其上面有几个沙发，其实就是看有多少沙发的最小的 y，严格小于自己最大的 y
当然，要剔除自己的（假如被算进去了的话）
其他方向也是类似的
*/

struct Sofa {
    int x[2], y[2];
};

int d, n, m;
Sofa s[N];
vector<int> min_x, max_x, min_y, max_y;
int cntl, cntr, cntt, cntb;
 
void meibao() {
    cin >> d >> n >> m;
    for (int i = 1; i <= d; i++) {
        cin >> s[i].x[1] >> s[i].y[1] >> s[i].x[2] >> s[i].y[2];
        int minx = min(s[i].x[1], s[i].x[2]);
        int maxx = max(s[i].x[1], s[i].x[2]);
        int miny = min(s[i].y[1], s[i].y[2]);
        int maxy = max(s[i].y[1], s[i].y[2]);
        min_x.push_back(minx);
        max_x.push_back(maxx);
        min_y.push_back(miny);
        max_y.push_back(maxy);
    }

    sort(min_x.begin(), min_x.end());
    sort(max_x.begin(), max_x.end());
    sort(min_y.begin(), min_y.end());
    sort(max_y.begin(), max_y.end());

    cin >> cntl >> cntr >> cntt >> cntb;

    for (int i = 1; i <= d; i++) {
        int minx = min(s[i].x[1], s[i].x[2]);
        int maxx = max(s[i].x[1], s[i].x[2]);
        int miny = min(s[i].y[1], s[i].y[2]);
        int maxy = max(s[i].y[1], s[i].y[2]);

        int cl = lower_bound(min_x.begin(), min_x.end(), maxx) - min_x.begin();
        if (minx < maxx) {
            cl--;
        }

        int cr = upper_bound(max_x.begin(), max_x.end(), minx) - max_x.begin();
        cr = max_x.size() - cr;
        if (maxx > minx) {
            cr--;
        }

        int ct = lower_bound(min_y.begin(), min_y.end(), maxy) - min_y.begin();
        if (miny < maxy) {
            ct--;
        }

        int cb = upper_bound(max_y.begin(), max_y.end(), miny) - max_y.begin();
        cb = max_y.size() - cb;
        if (maxy > miny) {
            cb--;
        }

        if (cl == cntl && cr == cntr && ct == cntt && cb == cntb) {
            cout << i << "\n";
            return;
        }
    }

    cout << "-1\n";
}   
