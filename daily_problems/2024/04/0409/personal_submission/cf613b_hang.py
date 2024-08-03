# debug 人傻了
# z数组最好正序（更容易处理一些）
# https://codeforces.com/contest/613/submission/255851953
# 固定i个满级，二分找最小的等级
from itertools import accumulate
def main():
    n, A, cf, cm, m = map(int, input().split())
    a = list(map(int, input().split()))
    z = []
    for i,x in enumerate(a):
        z.append([x, i])
    z.sort(key=lambda t: t[0], reverse=True)
    # 前i项和
    pre = list(accumulate((t[0] for t in z), initial=0))

    res = [0,0]
    for i in range(n + 1):
        t = A * i - pre[i]
        d =  m - t
        if d < 0:
            break
        if i == n:
            res = [A, n]
            break
        l,r = i + 1, n
        while l < r:
            mid = (l + r ) // 2
            t = pre[mid] - pre[mid - 1]
            if t * (n - mid) - (pre[-1] - pre[mid]) > d:
                l = mid + 1
            else:
                r = mid
        if min(A, pre[l] - pre[l - 1] + (d - ((pre[l] - pre[l - 1]) * (n - l) - (pre[-1] - pre[l]))) // (n-l+1)) * cm + i * cf >= res[0] * cm + res[1] * cf:
            res = [min(A, pre[l] - pre[l - 1] + (d - ((pre[l] - pre[l - 1]) * (n - l) - (pre[-1] - pre[l])))// (n-l+1)), i]
    for st in z:
        if st[0] < res[0]:
            st[0] = res[0]
    for i in range(res[1]):
        z[i][0] = A
    for i in range(n):
        a[z[i][1]] = z[i][0]
    print(res[0] * cm + res[1] * cf)
    print(*a)




    pass

main()
