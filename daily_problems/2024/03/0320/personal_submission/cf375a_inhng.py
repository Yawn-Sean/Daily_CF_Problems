from collections import Counter

# 对 7 取余分别为 0, 1, 2, 3, 4, 5, 6
all = ['1869', '1968', '1689', '6198', '1698', '1986', '1896']
s = input()
n, ans = len(s), 0
mp = Counter(int(c) for c in s)
mp[1], mp[6], mp[8], mp[9] = mp[1] - 1, mp[6] - 1, mp[8] - 1, mp[9] - 1
for i in range(1, 10):
    while mp[i]:
        ans = ans * 10 % 7 + i % 7
        print(i, end = "")
        mp[i] -= 1
print(all[(7 - ans * 10000 % 7) % 7] + '0' * mp[0])

