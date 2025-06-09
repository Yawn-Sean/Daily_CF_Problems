n = II()
nums = []
for _ in range(n - 1):
    nums.append(I())

ans = set(chr(i + ord('a')) for i in range(26))
flg = False
cnt = 0

for op in nums:
    a, b = op.split()
    if not flg:
        if a == "!":
            tmp = [1] * 26
            for x in list(b):
                tmp[ord(x) - ord('a')] = 0
            for i in range(26):
                if tmp[i]:
                    x = chr(i + ord('a'))
                    ans.discard(x)
        else:
            for x in list(b):
                ans.discard(x)
        if len(ans) == 1:
            ans = list(ans)[0]
            flg = True
    else:
        if a == "!" or a == "?":
            cnt += 1
print(cnt)
