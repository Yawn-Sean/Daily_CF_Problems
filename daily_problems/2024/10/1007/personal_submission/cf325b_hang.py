def main():
    n = int(input())
    ans = []
    for i in range(60):
        b = 1 << i
        l,r = 1, 2 * 10 ** 9
        while l < r:
            m = (l + r) // 2
            if m * (m - 1) // 2 + m * (b - 1) < n:
                l = m + 1
            else: 
                r = m
        if l * (l - 1) // 2 + l * (b  - 1) == n and (l & 1):
            ans.append(l * b)
    if ans:
        print(*ans,sep='\n')
    else:
        print(-1)

main()