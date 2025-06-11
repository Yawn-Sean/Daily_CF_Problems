/*
系统里有一个长度为 4 的字符串，玩家每次输出一个长度为 4 的字符串
系统会告诉你有几个数位数值和位置匹配了，有几个数位数值对但是位置不对
至多 50 次询问，猜出待猜字符串
先考虑猜第 1 位，不妨猜 0000，1000，... 9000
然后看填多少时，数值和位置同时匹配的个数最多，就确定了第一个数，问了 10 次
后边也是差不多的
*/

void meibao() {
    string res = "";
    for (int rd = 1; rd <= 4; rd++) {
        int max_bulls = 0, max_digit = -1;
        for (int i = 0; i <= 9; i++) {
            cout << res;
            cout << i;
            for (int j = rd + 1; j <= 4; j++) {
                cout << "0";
            }
            cout << endl;
            int bulls, cows;
            cin >> bulls >> cows;
            if (bulls == 4 && cows == 0) {
                return;
            }
            if (bulls > max_bulls) {
                max_bulls = bulls;
                max_digit = i;
            }
        }
        res += char(max_digit + '0');
    }
    cout << res << "\n";    
}
