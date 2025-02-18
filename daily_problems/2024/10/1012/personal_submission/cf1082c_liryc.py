'''
https://codeforces.com/problemset/submission/1082/285448707
CF1082C
2024/10/12(Sat) Y1
1600
soring, enumerating
'''
# ref
def solve():
    n, m = map(int, input().split())

    tmp = [[] for _ in range(m + 1)]
    for _ in range(n):
        x, y = map(int, input().split())
        tmp[x].append(y)

    vals = [0] * (n + 1)
    for i in range(m + 1):
        tmp[i].sort(reverse=True)
        cur = 0
        for j in range(len(tmp[i])):
            cur += tmp[i][j]
            if cur > 0: 
                vals[j + 1] += cur

if __name__ == '__main__':
    ans = solve()
    print(ans)