import sys
sys.stdin = open('in.txt', 'r')

t = int(input())
while t:
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    res = 1e18
    ans = a[0]
    for i in range(n - k):
        if a[i + k] - a[i] < res:
            res = a[i + k] - a[i]
            ans = a[i] + res // 2
    print(ans)
    t -= 1