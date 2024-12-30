for _ in range(int(input())):
    n = int(input())
    a = list(input())
    b = list(input())
    cnta, cntb, ans = a.count('1'), b.count('1'), float('inf')
    if cnta == cntb:
        ans = sum((a[i] != b[i]) for i in range(n))
    if n + 1 == cnta + cntb:
        cnt = sum(a[i] == b[i] for i in range(n))
        for i in range(n):
            if a[i] == b[i] == '1':
                cnt -= 2
                break
        ans = min(ans, cnt + 2)
    print(ans if ans < float('inf') else -1)
