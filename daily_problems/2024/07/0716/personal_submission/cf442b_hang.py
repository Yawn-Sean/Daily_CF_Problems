def main():
    n = int(input())
    p = list(map(float, input().split()))
    p.sort(reverse=True)

    p0, p1 = 1, 0
    ans = 0
    for p in p:
        p1 = p1 * (1 - p) + p0 * p
        p0 *= 1 - p
        ans = max(ans, p1)
    print(ans)
main()