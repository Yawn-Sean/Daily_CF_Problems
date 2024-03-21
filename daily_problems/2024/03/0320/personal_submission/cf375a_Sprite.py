from collections import Counter
a = str(input())
na = Counter(a)
na['1'] -= 1
na['6'] -= 1
na['8'] -= 1
na['9'] -= 1
ans = ''
for i in na:
    if i == '0':
        continue
    ans += i*na[i]
w = 0
for i in ans:
    w = (w*10 + int(i)) % 7
dic = {0:'1869', 1:'1896', 2:'1986', 3:'1698', 4:'6198', 5:'1689', 6:'1968'}
print(ans + dic[w*10000%7] + '0' * na['0'])
