def main():
    n,k = map(int,input().split())
    a =  list(map(int,input().split()))
    nxt = list(range(n))
    for i in range(n-2, -1, -1):
        if a[i] == 1:
            nxt[i] = nxt[i+1]
    tot = sum(a) * k
    ans = 0
    for i in range(n):
        p,s = 1, 0
        while i < n:
            if nxt[i] == i:
                # 不可能再有 k * s == p的情况了 
                # tot 是 k * s 最大的状态
                if p * a[i] > tot:
                    break
                p *= a[i]
                s += a[i]
                if s * k == p:
                    ans += 1
                i += 1
            else:
                # 至多 1 个
                if p % k == 0 and 0 < p // k - s <= nxt[i] - i:
                    ans += 1
                s += nxt[i] - i
                i = nxt[i]
    print(ans)
main()