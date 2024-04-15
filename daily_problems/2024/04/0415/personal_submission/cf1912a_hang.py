def main():
    x,k = map(int, input().split())
    s = []
    for _ in range(k):
        t = list(map(int, input().split()))[1:]
        tot,mn,pre = 0,0,0
        for num in t:
            tot += num
            mn = min(mn, tot)
            if tot > pre:
                s.append((-mn, tot - pre))
                pre = tot
    s.sort()
    ans = x
    for mn,val in s:
        if ans < mn:
            break
        ans += val
    print(ans)



main()