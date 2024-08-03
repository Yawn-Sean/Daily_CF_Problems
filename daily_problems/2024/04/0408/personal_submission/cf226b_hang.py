def main():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    pre = [0]
    for x in a:
        pre.append(pre[-1] + x)

    q = int(input())
    qs = list(map(int, input().split()))
    # 需要预处理
    # 否则会超时
    # qs中可能含有大量重复元素
    ans = [0]
    for k in range(1,n+1):
        k = min(k, n)
        ans.append(0)
        p = 1
        idx = k
        deep = 1
        while p < n:
            ans[-1] += (pre[min(p + idx, n)] - pre[p]) * deep
            p += idx
            idx *= k
            deep += 1
    res = [ans[min(k,n)] for k in qs]
    print(*res)





main()