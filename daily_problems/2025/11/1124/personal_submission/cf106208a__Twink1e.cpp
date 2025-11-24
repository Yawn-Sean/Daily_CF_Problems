#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cases;
    cin >> cases;
    while (cases--) {
        int type_count;
        cin >> type_count;

        long long total_cards = 0;
        int max_card = 0;
        int x = 0, y = 0;

        for (int i = 0; i < type_count; i++) {
            int card_num;
            cin >> card_num;
            total_cards += card_num;

            if (card_num > max_card) max_card = card_num;

            if (type_count == 2) {
                if (i == 0) x = card_num;
                else y = card_num;
            }
        }


        if (max_card < 2) {
            cout << 0 << endl;
        }

        else if (type_count == 2) {
            int trade_count = 0;

            while (true) {
                int a = x / 2;
                int b = y / 2;
                if (a == 0 && b == 0) break;
                trade_count += a + b;

                int nx = x % 2 + b;
                int ny = y % 2 + a;
                x = nx;
                y = ny;
            }
            cout << trade_count << endl;
        }

        else if (total_cards == 3 && max_card == 3) {
            cout << 1 << endl;
        }

        else {
            cout << total_cards - 1 << endl;
        }
    }
    return 0;
}