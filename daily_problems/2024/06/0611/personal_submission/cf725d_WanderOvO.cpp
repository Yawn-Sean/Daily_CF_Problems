/*
自己给别人一个气球，则可能导致对方升天，自己的排名上升，也可能气球给出去之后自己的排名下降更多
为了让自己排名上升，肯定优先把气球给比自己排名靠前，且离升天所需要的气球最少的
自己可能给别人的气球数其实是有限的，如果给完之后比上一个还要多，则排名肯定不会下降
使用堆模拟整个过程，并记录最高排名即可
*/

int T;
LL n, my_t, my_w;
PLL team[N];

void solve1() {
    cin >> n;
    cin >> my_t >> my_w;
    for (int i = 1; i < n; i++) {
        cin >> team[i].x >> team[i].y;
    }    
    sort(team + 1, team + n);
    reverse(team + 1, team + n);
    priority_queue<LL, vector<LL>, greater<LL>> q;
    int cur = 1;
    while (cur < n) {
        if (team[cur].x > my_t) {
            q.push(team[cur].y - team[cur].x + 1);
            cur++;
        } else {
            break;
        }
    }
    int res = q.size() + 1;
    while (!q.empty()) {
        LL cost = q.top();
        q.pop();
        if (my_t >= cost) {
            my_t -= cost;
        } else {
            break;
        }
        while (cur < n && team[cur].x > my_t) {
            q.push(team[cur].y - team[cur].x + 1);
            cur++;
        }

        res = min(res, (int)q.size() + 1);
    }
    cout << res << "\n";
}                                                                                                                  
