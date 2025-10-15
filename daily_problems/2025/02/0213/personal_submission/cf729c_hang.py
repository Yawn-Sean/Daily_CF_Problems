def main():
    n,k,s,t = map(int, input().split())
    cvs = []
    for _ in range(n):
        c,v = map(int, input().split())
        cvs.append((c,v))
    g = list(map(int, input().split()))
    g.append(s)
    g.sort()
    cvs.sort(key=lambda x:x[1])
    l,r = 0, n-1
    def check(x):
        time = 0
        pre = 0
        for cur in g:
            dis = cur - pre
            if x >= 2 * dis:
                time += dis
            elif x < dis:
                return False
            else:
                time += 2 * dis - (x - dis)
            pre = cur
        return time <= t
    while l < r:
        mid = (l + r) // 2
        if check(cvs[mid][1]):
            r = mid
        else:
            l = mid + 1
    if not check(cvs[l][1]):
        print(-1)
        return
    ans = 10 ** 9 + 100
    for c,v in cvs:
        if v >= cvs[l][1]:
            ans = min(ans, c)
    print(ans)

main()
