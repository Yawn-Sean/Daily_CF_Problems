n = int(input())
ans = [] 
for _ in range(n):
    a, b, c, d = map(int, input().split()) 
    ans.append(a // 2 + b // 2 + c // 2 + d // 2 + (a % 2 == 1 and b % 2 == 1 and c % 2 == 1))

print('\n'.join(str(res) for res in ans))
