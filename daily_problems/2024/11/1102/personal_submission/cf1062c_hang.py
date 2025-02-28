def main():
    n,q = map(int,input().split())
    s = input()
    
    mod = 10 ** 9 + 7
    pre = [0] * (n + 1)
    p = [1] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + int(s[i])
        p[i + 1] = p[i] * 2 % mod
    ans = []
    for i in range(q):
        l,r = map(int,input().split())
        l -=1 
        ans.append((p[r - l] - p[r - l - (pre[r] - pre[l])]) % mod)
    print(*ans,sep='\n')

        

main()