# https://codeforces.com/contest/1023/submission/272475802
# 不能出现 6 5 6 这种一个区间内有之前操作的情况
# 最后要注意必须有n，随便挑一个位置即可
# 0的处理，改成左右两边非0位置元素较大的
n, q = RII()
a = RILIST()
if sum(a) == 0:
    print('YES')
    print(' '.join(map(str, [q]*n)))
    exit()
pre = set()
st = [] # x后面只能出现比x大的，如果出现小的，就popx，如果后面再出现x就错了
left = [0]*(n + 1)
right = [0]*n
for i, x in enumerate(a):
    if x == 0:
        left[i + 1] = left[i]
        continue
    left[i + 1] = x
    if x in pre:
        print('NO')
        exit()
    if st and st[-1] > x:
        pre.add(st.pop())
    st.append(x)

last0 = -1 # 记录最后一个0的位置，如果后面没有出现q，就把这个位置改成q
for i in range(n - 1, -1, -1):
    if a[i]:
        if i:
            right[i - 1] = a[i]
    else:
        last0 = i
        a[i] = max(left[i], right[i])
        if a[i] == 0:
            a[i] = q
        if i:
            right[i - 1] = a[i]

if max(a) < q:
    if last0 == -1:
        print('NO')
        exit()
    else:
        a[last0] = q
print('YES')
print(' '.join(map(str, a)))