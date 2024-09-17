'''
https://codeforces.com/contest/641/submission/281459627
641 C
2024/9/16 Y1
1800
math
'''

import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    n, q = map(int, input().split())
    s, d, e = 0, 1, 1
    for _ in range(q):
        cin = input()
        if  cin[0] == '1':
            k = int(cin.split()[-1])
            k = n - k
            if k & 1:
                s, d, e = (s + (d + e) * (k >> 1) + d) % n, e, d
            else:
                s = (s + (d + e) * (k >> 1)) % n
        else:
            s, d, e = (s + d) % n, -d, (d + e + d) % n
        # print('s d e=', s, d, e)
    ans = [0] * n
    ans[0] = s + 1
    for i in range(1, n):
        if i & 1:
            ans[i] = (ans[i - 1] - 1 + d) % n + 1
        else:
            ans[i] = (ans[i - 1] - 1 + e) % n + 1
    print(' '.join(map(str, ans)))

if __name__ == '__main__':
    solve()
