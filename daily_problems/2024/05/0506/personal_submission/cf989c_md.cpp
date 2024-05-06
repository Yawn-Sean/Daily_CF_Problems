// 0506
#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    array<int, 4> req;
    for (int i = 0; i < 4; ++i) {
        cin >> req[i];
        --req[i];
    }
    
    array<string, 50> board;
    for (int i = 0; i < 25; ++i) {
        board[i] = board[i + 25] = string(50, ' ');
        fill(begin(board[i]), begin(board[i]) + 25, 'A');
        fill(begin(board[i]) + 25, end(board[i]), 'B');        
        fill(begin(board[i + 25]), begin(board[i + 25]) + 25, 'C');
        fill(begin(board[i + 25]) + 25, end(board[i + 25]), 'D');
    }

    vector<pair<int, int>> offsets = {{1, 1}, {1, 26}, {26, 1}, {26, 26}};
    for (int i = 0; i < 4; ++i) {
        int next_id = (i == 3) ? 0 : i + 1;
        auto[x, y] = offsets[next_id];
        for (int num = 0; num < req[i]; ++num) {
            if (y >= ((1 + (next_id & 1)) * 25)) {
                y = offsets[next_id].second;
                x += 2;
            }
            board[x][y] = static_cast<char>('A' + i);            
            y += 2;
        }
    }

    cout << "50 50\n";
    for (int i = 0; i < 50; ++i) {
        cout << board[i] << endl;
    }

    return 0;
}