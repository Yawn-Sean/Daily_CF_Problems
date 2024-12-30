from collections import deque

# 读入数据
n, m = map(int, input().split())
arr = list(map(int, input().split()))
managers = []
for _ in range(m):
  managers.append(list(map(int, input().split())))


# 单调栈存储所有有效的排序，栈下大上小
st = []
i = 0
for i in range(m):
  while st and managers[i][1] >= st[-1][1]:
    st.pop()
  st.append(managers[i])


ans = arr.copy()
arr = arr[:st[0][1]]
arr.sort()
arr = deque(arr)

for i, (order, l) in enumerate(st):
  # 每次更新当前和上一个区间的差区间
  l_next = 0
  if i + 1 < len(st):
    l_next = st[i + 1][1]
  
  for j in range(l - 1, l_next - 1, -1):
    if order == 1:
        ans[j] = arr.pop()
    else:
        ans[j] = arr.popleft()

print(' '.join(map(str, ans)))
