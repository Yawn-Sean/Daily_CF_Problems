h, n = map(int, input().split())

ans = 0


def dfs(l, r, d):
  global ans
  if l == r:
    print(ans)
    exit()

  mid = l + r >> 1
  if d == 0:
    if n <= mid:
      ans += 1
      dfs(l, mid, 1)
    else:
      ans += (mid - l + 1) * 2
      dfs(mid + 1, r, 0)
  else:
    if n > mid:
      ans += 1
      dfs(mid + 1, r, 0)
    else:
      ans += (mid - l + 1) * 2
      dfs(l, mid, 1)


dfs(1, 1 << h, 0)
