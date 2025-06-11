def z_algorithm(s):

    if isinstance(s, str):
        s = [ord(c) for c in s]

    n = len(s)
    if n == 0:
        return []

    z = [0] * n
    j = 0
    for i in range(1, n):
        z[i] = 0 if j + z[j] <= i else min(j + z[j] - i, z[i - j])
        while i + z[i] < n and s[z[i]] == s[i + z[i]]:
            z[i] += 1
        if j + z[j] < i + z[i]:
            j = i
    z[0] = n

    return z

def main():
    n,m = map(int,input().split())
    p = input()
    y = []
    if m != 0:

        y = list(map(lambda x : int(x) - 1,input().split()))  
    k = len(p)
    z = z_algorithm(p)
    mod = 10 ** 9 + 7
    for i in range(m - 1):
        if y[i + 1] - y[i] >= k: 
            continue
        j = y[i + 1] - y[i]
        if z[j] + j != k: 
            print(0)
            return

    
    cnt = [0] *(n + 1)
    for i in range(m):
        cnt[y[i]] += 1
        cnt[y[i] + k ] -= 1
    ans = 1
    
    for i in range(n): 
        cnt[i+1] += cnt[i]
        if cnt[i] == 0: 
            ans = ans * 26 
            ans = ans % mod
    print(ans)

main()