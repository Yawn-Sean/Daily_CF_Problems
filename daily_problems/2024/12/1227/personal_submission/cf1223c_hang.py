def main():
    n = int(input())
    p = list(map(lambda x: int(x) // 100, input().split()))
    x,a = map(int, input().split())
    y, b = map(int, input().split())
    k = int(input())
    p.sort(reverse=True)
    if y > x:
        x,y = y,x
        a,b = b,a

    l,r = 1, n
    while l <= r:
        mid = (l + r) // 2
        cnt_a,cnt_b,cnt_ab = 0,0,0
        for i in range(1,mid+1):
            if i % a == 0:
                if i % b == 0:
                    cnt_ab += 1
                else:
                    cnt_a += 1
            elif i % b == 0:
                cnt_b += 1
        tot = 0
        for i in range(cnt_a + cnt_b + cnt_ab):
            if cnt_ab:
                tot += p[i] * (x + y)
                cnt_ab -= 1
            elif cnt_a:
                tot += p[i] * x
                cnt_a -= 1
            elif cnt_b:
                tot += p[i] * y
                cnt_b -= 1
        if tot >= k:
            r = mid - 1
        else:
            l = mid + 1
    print(l if l <= n else -1)

q = int(input())
for _ in range(q):
    main()