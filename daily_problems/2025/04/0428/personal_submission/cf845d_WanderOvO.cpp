/*
速度和超车可以分开考虑
1 3 5 需要放一起考虑
2 4 6 需要放一起考虑
我们可能会怎样违法？
- 超速了，这个时候需要说自己没有注意到限速标志
- 违规超车，这个时候需要说自己没有注意到禁止超车标志
解除速度限制以及允许超车标志对我们有利，不用管
假如超车时发现不能超，则必须把和上次允许超车之间的所有禁止超车给删了
假如超速了，需要把前面的速度限制标志忽略掉，直到遇到无限制或者一个足够高的限制
每个标志只会被插入和删除 1 次，所以上面说的过程似乎可以暴力模拟
*/

int n;
vector<int> overtake;
vector<PII> speed;
 
void meibao() {
    cin >> n;
    int cur_speed = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int t, s;
        cin >> t;
        if (t == 1) {
            cin >> s;
            cur_speed = s;
            for (int j = speed.size() - 1; j >= 0; j--) {
                if (speed[j].x == 3 && speed[j].y < cur_speed) {
                    speed.pop_back();
                    res++;
                } else {
                    break;
                }
            }
        } else if (t == 2) {
            for (int j = overtake.size() - 1; j >= 0; j--) {
                if (overtake[j] == 6) {
                    overtake.pop_back();
                    res++;
                } else {
                    break;
                }
            }
        } else if (t == 3) {
            cin >> s;
            if (s >= cur_speed) {
                speed.push_back({3, s});
            } else {
                res++;
            }
        } else if (t == 4) {
            overtake.push_back(4);
        } else if (t == 5) {
            speed.push_back({5, 0});
        } else {
            overtake.push_back(6);
        }
    }
    cout << res << "\n";
}   
