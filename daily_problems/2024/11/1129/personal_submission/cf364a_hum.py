from collections import defaultdict
from itertools import accumulate

a = int(input())
s = [int(i) for i in input()]
acc = list(accumulate(s, initial=0))

dic = defaultdict(int)

for i in range(len(acc)):
  for j in range(i + 1, len(acc)):
    dic[acc[j] - acc[i]] += 1

res = 0
cnt_acc = 0
for x, v in dic.items():
  cnt_acc += v
  if x == 0:
    continue
  if a % x == 0 and a // x in dic:
    res += dic[a // x] * dic[x]

if a == 0:
  res += cnt_acc * dic[0]
print(res)
