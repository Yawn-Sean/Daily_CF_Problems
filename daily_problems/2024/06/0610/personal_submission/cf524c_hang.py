def  main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    d= set(a)
    q = int(input())
    for _ in range(q):
        x = int(input())
        ans = 1e9+7
        for i in range(n):
            for t in range(k + 1):
                r = x - a[i] * t
                if r == 0:
                    ans = min(ans,t)
                else:
                    for j in range(1, k-t+1):
                        if r % j == 0 and r // j in d:
                            ans = min(ans,t+j)
        print(ans if ans != 1e9+7 else -1)
                
main()