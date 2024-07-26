# https://codeforces.com/contest/886/submission/272491945
n = RI()
d = [[-1, -1] for _ in range(26)]
cnt = [0]*26
for _ in range(n):
    s = RS()
    m = len(s)
    if Counter(s).most_common()[0][1] > 1:
        print('NO')
        exit()
    for i, x in enumerate(s):
        idx = ord(x) - ord('a')
        cnt[idx] = 1
        if i + 1 < m:
            right = ord(s[i + 1]) - ord('a')
            if d[idx][1] != -1 and d[idx][1] != right:
                print('NO')
                exit()
            d[idx][1] = right
            if d[idx][0] == right:
                print('NO')
                exit()
            if d[right][0] != -1 and d[right][0] != idx:
                print('NO')
                exit()
            d[right][0] = idx
            if d[right][1] == idx:
                print('NO')
                exit()
            
ans = []
mx = sum(cnt)
while True:
    i = 0
    while i < 26:
        if cnt[i] and d[i][0] == -1:
            cnt[i] = 0
            break
        i += 1
    if i == 26:
        break
    while i != -1:
        ans.append(chr(i + ord('a')))
        cnt[i] = 0
        t = d[i][1]
        d[i][1] = -1
        i = t
# 跑出来的长度可能和出现的字符不一样
# 3
# a
# bcd
# defgb
if len(ans) != mx:
    print('NO')
else:
    print(''.join(ans))