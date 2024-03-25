def main():
    n,k = map(int, input().split())
    s = list(map(int, input().split()))
    MOD  = 998244353
    pos = [-1] * (n + 1)
    for i in range(n):
        pos[s[i]] = i
    cnt = 0
    for i in range(n - 1):
        if pos[s[i] + 1] > pos[s[i+1] + 1]:
            cnt += 1
            
    num,denom=1,1

    for i in range(n):
        num=num*(k-cnt+n-1-i)%MOD
        denom=denom*(i+1)%MOD

    print(num*pow(denom,MOD-2,MOD)%MOD)

main()