t = II()
outs = []

s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"

for _ in range(t):
    r, c, k = MII()
    nums = []
    tot = 0

    for _ in range(r):
        nums.append(list(I()))
        tot += sum(x == 'R' for x in nums[-1])

    b, m = divmod(tot, k)
    for i in range(k):
        need = b
        if i < m:
            need += 1
    
    need = b
    cur = cnt = 0
    for i in range(r):
        if i % 2 == 0:
            for j in range(c):
                tmp = nums[i][j]
                nums[i][j] = s[cnt] if cnt < k else s[k - 1]
                if tmp == 'R':
                    cur += 1
                if cur == need:
                    cur = 0
                    cnt += 1
                    if cnt == k - m:
                        need = b + 1
                
        else:
            for j in range(c - 1, -1, -1):
                tmp = nums[i][j]
                nums[i][j] = s[cnt] if cnt < k else s[k - 1]
                if tmp == 'R':
                    cur += 1
                if cur == need:
                    cur = 0
                    cnt += 1
                    if cnt == k - m:
                        need = b + 1

    for i in range(r):
        outs.append(''.join(nums[i]))

print("\n".join(outs))
