import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n, k = lii()
    arr = lii()
    x, ans = -1, 10**9
    for i in range(n-k):
        if (tmp := arr[i+k] - arr[i]) < ans:
            ans = tmp
            x = (arr[i] + arr[i+k]) // 2
    return x

for _ in range(ii()):
    print(solve())