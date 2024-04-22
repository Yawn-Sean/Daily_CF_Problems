def main():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort()
    b.sort()
    z = list(set(a + b))
    z.sort()
    sum_a,sum_b = sum(a), sum(b)
    d_a,d_b = 0,0
    ans = 10**18
    p_a,p_b = 0,0
    for x in z:
        while d_a < n and a[d_a] < x:
            p_a += a[d_a]
            d_a += 1
        while d_b < m and b[d_b] < x:
            p_b += b[d_b]
            d_b += 1
        ans = min(ans, x * (d_a ) - p_a + sum_b - p_b - x * (m - d_b))
    print(ans)

main()
