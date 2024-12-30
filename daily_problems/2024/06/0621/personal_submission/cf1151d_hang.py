def main():
    n = int(input())
    g = []
    ans = 0
    for _ in range(n):
        a,b =  map(int, input().split())
        ans += b * n - a
        g.append(a - b)
        
    g.sort()
    for i in range(n):
        
        ans += g[i] * (n - i)
    print(ans)
main()