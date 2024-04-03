import sys
input = lambda: sys.stdin.readline().rstrip()
ii = lambda: int(input())
lii = lambda: list(map(int, input().split()))

def solve():
    n = ii()
    arr1, arr2 = [], []
    for i in range(1, n+1):
        a, b = lii()
        if a < b:
            arr1.append((a, b, i))
        else:
            arr2.append((b, a, i))

    def calc(arr):
        arr.sort(key=lambda p: p[1], reverse=True)
        res = []
        pre = 2*n+1
        for a, b, i in arr:
            if a < pre:
                pre = b
                res.append(i)
        return res

    ans1 = calc(arr1)
    ans2 = calc(arr2)[::-1]
    return ans1 if len(ans1) > len(ans2) else ans2

ans = solve()
print(len(ans))
print(*ans)