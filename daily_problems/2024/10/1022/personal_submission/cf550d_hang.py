def main():
    k = int(input())
    ans = []
    if k % 2 == 0:
        print("NO")
        exit()
    for i in range(k - 1):
        for j in range(k - 1):
            ans.append(f'{i + 1} {j + k}')
            ans.append(f'{i + 2 * k - 1} {j + 3 * k - 2}')
            
        if i % 2 == 0:
            ans.append(f'{i + 1} {i + 2}')
            ans.append(f'{i + 2 * k - 1} {i + 2 * k}')
            
        ans.append(f'{i + k} {4 * k - 3}')
        ans.append(f'{i + 3 * k - 2} {4 * k - 2}')
        
    ans.append(f'{4 * k - 3} {4 * k - 2}')
    print("YES")
    print(4 * k  - 2, len(ans))
    for i in ans:
        print(i)

main()