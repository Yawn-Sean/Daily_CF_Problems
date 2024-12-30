a, b, h, w, n = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort(reverse=True)
a, b = min(a, b), max(a, b)
st = set()
st.add((min(h, w), max(h, w)))

for i in range(n + 1):
  nst = set()
  for x, y in st:
    if x >= a and y >= b:
      print(i)
      exit()
    if i != n:
      nx, ny = x * nums[i], y
      nst.add((min(nx, ny), max(nx, ny)))
      if y < b:
        nx, ny = x, y * nums[i]
        nst.add((nx, ny))
  st = nst

print(-1)
