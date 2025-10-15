# 本题与20220505灵茶重复
n = RI()
a = RILIST()

f = [0] * n # 每天水上+水下最多有多少条线
f[-1] = a[-1]
for i in range(n - 2, -1, -1):
    f[i] = mx(f[i + 1] - 1, a[i]) # 从后向前推，今天的线为今天水面上的线和前一天所有线-1的最大值

# 从前往后，保证f单调不减
for i in range(1, n):
    f[i] = mx(f[i], f[i - 1])

print(sum(f) - sum(a))