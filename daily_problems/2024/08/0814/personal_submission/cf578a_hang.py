def main():
    a,b = map(int,input().split())
    if b > a:
        print(-1)
        return
    ans = 10 ** 9
    t = a - b
    if t >= 2 * b:
        k = t // (2 * b)
        ans = min(ans, t/2/k)
    t = a + b
    if t >= 2 * b:
        k = t // (2 * b)
        ans = min(ans, t/2/k)
    print(ans)


main()