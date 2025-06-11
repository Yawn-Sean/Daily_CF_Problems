n = int(input())
s, t = input(), input()

# 找最长前后缀，允许为空，如果中间不同的字符超过1，则不能
i, j = 0, n - 1
while i < n and s[i] == t[i]:
    i += 1
while j >= 0 and s[j] == t[j]:
    j -= 1

print(int(s[i:j] == t[i + 1:j + 1]) + int(s[i + 1:j + 1] == t[i:j]))
    
# 期待是1，却输出了0