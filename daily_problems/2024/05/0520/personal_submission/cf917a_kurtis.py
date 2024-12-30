# 就是合法括号的前缀和优化，O(n^2)
# 利用了字串的关系
s = input()
n = len(s)
res = 0
for i in range(n):
    cur, right = 0, 0
    for j in range(i, n):
        if s[j] == '(':
            cur += 1
        elif s[j] == ')':
            cur -= 1
        else:
            cur -= 1
            right += 1
        
        if cur < 0:
            if right:
                right -= 1
                cur += 2
            else: break

        if cur == 0:
            res += 1
            
print(res)