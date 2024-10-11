def main():
    x = int(input())
    s = input()
    mod = 10**9 + 7
    ans = len(s)
    tmp = [0] * x
    for i in range(min(len(s), x)):
        tmp[i] = int(s[i])
    idx = min(len(s), x)
    for i in range(x):

        ans = (ans + (ans - i - 1) * (tmp[i] - 1)) % mod
        j = i + 1
        end = idx
        cnt = 1
        while cnt < tmp[i] and idx < x:
            tmp[idx] = tmp[j]
            idx += 1
            j += 1
            if j == end:
                j = i + 1
                cnt += 1
    print(ans)
            
     
t = int(input())
for _ in range(t):
    main()