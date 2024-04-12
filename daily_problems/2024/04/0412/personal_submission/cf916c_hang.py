def main():
    n, m = map(int, input().split())
    prime = 998244353

    ans = ['998244353 998244353']
    
    for i in range(1, n - 1):
        ans.append(f'{i} {i + 1} {1}')

    ans.append(f'{n - 1} {n} {prime - (n - 2)}')

    m = m - (n - 1)

    for j in range(n):
        for i in range(j - 1):
            if m == 0: 
                break
            ans.append(f'{i + 1} {j + 1} {10 ** 9}')
            m -= 1

    for x in ans:
        print(x)

main()