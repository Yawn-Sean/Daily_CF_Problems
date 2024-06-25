k, d = list(map(int, input().split()))
ans = []
x = 1
# 按照 2^i-1 的方式拆分 k
while k > 0:
    l = k.bit_length()
    if k < (1 << l) - 1:
        l -= 1
    ans.extend([x] * l)
    x += d
    k -= (1 << l) - 1

print(len(ans))
print(*ans)