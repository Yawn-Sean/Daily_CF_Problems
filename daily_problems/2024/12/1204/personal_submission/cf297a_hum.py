a = input()
b = input()
cnt1 = a.count('1')
cnt2 = b.count('1')
if (cnt1 + 1) // 2 * 2 >= cnt2:
  print("YES")
else:
  print("NO")
