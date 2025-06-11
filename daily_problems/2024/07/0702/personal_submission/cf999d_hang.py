def main():
    n,m = map(int,input().split())
    a = list(map(int,input().split()))
    c = [[] for _ in range(m)]
    for i in range(n):
        c[a[i] % m].append(i)
    ans = 0
    st = []
    tar = n // m
    for i in range(2 * m):
        t = i % m
        while st and len(c[t]) < tar:
            j = st.pop()
            ans += (t - a[j]) % m
            a[j] += (t - a[j]) % m
            
            c[t].append(j)
        while len(c[t]) > tar:
            st.append(c[t].pop())
    print(ans)
    print(*a)


main()