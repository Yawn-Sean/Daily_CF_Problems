import sys
input = lambda: sys.stdin.readline().rstrip()

def soviet():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    v = []
    for i in range(n):
        v.append(max(a[i], b[i]))
        v.append(min(a[i], b[i]))

    ans = []
    for x in v:
        if len(ans) == 0 or x > ans[-1]:
            ans.append(x)
            continue
        l = 0
        r = len(ans) - 1
        while l < r:
            mid = l + r >> 1
            if ans[mid] >= x:
                r = mid
            else:
                l = mid + 1
        ans[l] = x

    print(len(ans))

soviet()
