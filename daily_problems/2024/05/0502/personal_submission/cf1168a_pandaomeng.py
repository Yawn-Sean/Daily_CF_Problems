# https://codeforces.com/problemset/submission/1168/259107217

def main():
  n, m = MII()
  nums = LII()

  def check(t):
    min_val = 0
    for i in range(n):
      # 判断是否可以达到上一个数 min_val
      if nums[i] + t < min_val:
        return False
      if nums[i] > min_val and nums[i] + t < min_val + m:
        min_val = nums[i]
    return True
  
  l = -1
  r = m
  # 开区间 (l, r)
  while l + 1 < r:
    mid = (l + r) // 2
    if check(mid):
      r = mid
    else:
      l = mid
  
  print(r)


main()