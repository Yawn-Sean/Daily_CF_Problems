n  = int(input())
a = list(map(int, input().split()))
tarl = [i for i in range(n + 2)]
for i in range(1, n + 2):
    tarl[i] ^= tarl[i - 1]

ans = []
for i in range(1, n + 1):
    j = i
    if j == 1:
        ans.append(0)
        continue
    f = 0
    if (n // j) % 2 == 0:
        f = 1
    cnt = n - n // j * j
    if f:
        k = tarl[cnt]
    else:
        k = tarl[j - 1] ^ tarl[cnt]
    
    ans.append(k)
end = 0
for i in ans:
    end ^= i
for i in a:
    end ^= i
print(end)
