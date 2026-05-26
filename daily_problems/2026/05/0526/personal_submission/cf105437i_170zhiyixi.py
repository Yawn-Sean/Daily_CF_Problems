[n, m] = LI()
a = [0] + LI() + [m + 1]

#智力
dp = [0] * (m + 2)

l = [0] * (m + 2)
r = [0] * (m + 2)

#print(a)
#当前的智力值
ans = 0

for i in range(1, n + 2):
    #特殊处理结尾
    if a[i] == 0 or a[i] == m + 1:

        
            
        for j in range (1, m + 1):
            l[j] += l[j - 1]
            r[j] += r[j - 1]
            
        #枚举智力值
        for j in range (ans, -1, -1):
            
            #如果这个点拿智力 从上一个点转移过来
            dp[j + 1] = max(dp[j] + l[j] + r[ans - j], dp[j + 1])
            #拿体力
            dp[j] = max(dp[j], dp[j] + l[j] + r[ans - j])

       

        
        if a[i] == 0:
            ans += 1
        
            
        for j in range (1, m + 1):
            l[j] = 0
            r[j] = 0
    else:
        if a[i] > 0:
            l[a[i]] += 1
        else:
            r[-a[i]] += 1


ma = 0
for i in range (0, m + 1):
    ma = max(ma, dp[i])

print(ma)
