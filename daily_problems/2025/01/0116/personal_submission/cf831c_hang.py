def main():
    k,n = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    for i in range(1,k):
        a[i] += a[i-1]
    s = set(a)

    ans = 0
    for v in s:
        start = b[0] - v
        for x in b:
            if x - start not in s:
                break
        else:
            ans += 1
    print(ans)

main()