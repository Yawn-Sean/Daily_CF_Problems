'''
https://codeforces.com/problemset/submission/358/288725032
358D
2024/10/29 Y1
1800
DP[i]表示喂前i只兔子的总的joy值，其中：
d1:喂兔子时左右都是饿着的
d2:喂兔子时左边吃了，右边饿着
d3:喂兔子时左边饿着，右边吃了
d4:喂兔子时左右都吃了
'''
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))
    return n, a, b, c

def solve(n, a, b, c):
    d1, d2, d3, d4 = 0, 0, 0, 0
    for i, (x1, x2, x3) in enumerate(zip(a, b, c)):
        if i == 0:
            d1, d2, d3, d4 = x1, x1, x2, x2
        elif i == n - 1:
            d1, d2, d3, d4 = x1 + max(d3, d4), x2 + max(d1, d2), x1 + max(d3, d4), x2 + max(d1, d2)
        else:
            d1, d2, d3, d4 = x1 + max(d3, d4), x2 + max(d1, d2), x2 + max(d3, d4), x3 + max(d1, d2)
        # print("x=", x1, x2, x3, "d=", d1, d2, d3, d4)
    return max(d1, d2)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)