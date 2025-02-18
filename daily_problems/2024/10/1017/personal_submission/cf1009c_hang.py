def main():
    n,m = map(int,input().split())
    a1 = (n -1) * n // 2
    a2 = 0
    for i in range(n):
        a2 += abs(i - n//2)
    ans = 0
    
    for _ in range(m):
        x,d = map(int,input().split())
        ans += x * n
        ans += d * (a1 if d > 0 else a2)    
    print(ans / n)

main()