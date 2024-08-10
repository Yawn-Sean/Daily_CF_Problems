'''
https://codeforces.com/contest/1442/submission/268437028
1442B
2024/7/2 Y1
1800
couting
'''

def init():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    return n, k, a, b

def solve(n, k, a, b):
    s = set(b)
    d = {}
    for i in range(1, len(a) - 1):
        d[a[i]] = (a[i - 1], a[i + 1])
    d[a[0]] = (a[1], a[1])
    d[a[-1]] = (a[-2], a[-2])
    ans = 1
    for x in b:
        y, z = d[x]
        if y == z:
            if y in s:
                return 0
        else:
            if y in s and z in s:
                return 0
            elif y in s or z in s:
                pass
            else:
                ans = (ans << 1) % 998244353
        s.remove(x)
    return ans 

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        print(ans)
