'''
https://codeforces.com/contest/1644/submission/277461682
1644D
2024/8/21 Y1
1700
hashset, 注意除了行列被占用，还存在行被所有列刷屏(列被所有行刷屏)的情况
'''

def init():
    n, m, k, q = map(int, input().split())
    a = []
    for _ in range(q):
        x, y = map(int, input().split())
        a.append((x, y))
    return n, m, k, q, a

def solve(n, m, k, q, a):
    cnt = 0
    hsx, hsy = set(), set()
    for x, y in a[::-1]:
        if len(hsx) == n or len(hsy) == m:
            break
        if not x in hsx or not y in hsy:
            cnt += 1
            hsx.add(x)
            hsy.add(y)
    return k ** cnt % 998244353

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
