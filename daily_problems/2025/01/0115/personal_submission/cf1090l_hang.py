def main():
    t,n,a,b,k = map(int, input().split())
    c2 = n // 2
    c1 = n - c2
    ans = min(t, (c1 * a + c2 * b) // k)
    if k > c1: 
        ans = min(ans, c2 * b // (k - c1))
    if k > c2: 
        ans = min(ans, c1 * a // (k - c2))
    if k <= n:
        print(ans)
    else:
        print(0)

main()