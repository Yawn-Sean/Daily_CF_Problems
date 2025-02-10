/*
走到第一个加油站之后，直接把油贪心加到满
之后每到一个加油站，假如还剩下油，且当前加油站的油便宜，则都替换成这个加油站买的
*/

LL d, n, m;
PLL s[N];

void meibao() {
    cin >> d >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s[i].x >> s[i].y;
    }
    s[m + 1].x = d;
    s[m + 1].y = 0;
    m++;
    sort(s + 1, s + m + 1);
    LL to_buy = max(0LL, d - n);
    multiset<PLL> bought_gas;
    bought_gas.insert({0, n});
    LL tot_cost = 0, left_gas = n;
    for (int i = 1; i <= m; i++) {
        LL dist = s[i].x - s[i - 1].x;
        while (bought_gas.size() > 0 && dist > 0) {
            PLL cheapest_gas = *bought_gas.begin();
            auto it = bought_gas.find(cheapest_gas);
            bought_gas.erase(it);
            if (cheapest_gas.y > dist) {
                cheapest_gas.y -= dist;
                left_gas -= dist;
                dist = 0;
                bought_gas.insert(cheapest_gas);
            } else {
                dist -= cheapest_gas.y;
                left_gas -= cheapest_gas.y;
            }
        }
        if (dist > 0) {
            cout << "-1\n";
            return;
        }

        while (bought_gas.size() > 0) {
            PLL most_expensive_gas = *bought_gas.rbegin();
            auto it = bought_gas.find(most_expensive_gas);
            bought_gas.erase(it);
            LL cur_price = s[i].y;
            if (cur_price < most_expensive_gas.x) {
                tot_cost -= (most_expensive_gas.x - cur_price) * most_expensive_gas.y;
                most_expensive_gas.x = cur_price;
                bought_gas.insert(most_expensive_gas);
            } else {
                bought_gas.insert(most_expensive_gas);
                break;
            }
        }
        
        LL cur_price = s[i].y;
        if (to_buy > 0 && left_gas < n) {
            bought_gas.insert({cur_price, min(to_buy, n - left_gas)});
            tot_cost += min(to_buy, n - left_gas) * cur_price;
            if (to_buy < n - left_gas) {
                left_gas += to_buy;
                to_buy = 0;
            } else {
                to_buy -= n - left_gas;
                left_gas = n;
            }
        }
    }
    cout << tot_cost << "\n";
}
