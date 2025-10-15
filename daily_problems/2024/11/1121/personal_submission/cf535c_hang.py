from math import inf
def main():
    n = int(input())
    p = [-1] * n
    d = [0] * n
    for i in range(n):
        p[i],d[i] = map(int,input().split())
        p[i] -= 1
    dp0 = [0] * n
    dp1 = [-inf] * n
    for i in range(n-1, 0, -1):
        par =  p[i]
        dp1[i] = max(dp1[i], dp0[i] + d[i])
        dp0[par],dp1[par] = max(dp0[par] + dp0[i], dp1[i] + dp1[par]), max(dp0[par] + dp1[i], dp0[i] + dp1[par])
    print(max(dp0[0] + d[0], dp1[0]))

main()