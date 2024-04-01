def main():
  n = II()
  nums = LII()
  cnt = Counter()
  for v in nums:
      cnt[v & -v] += 1
  
  msk = cnt.most_common()[0][0]
  chosen = []
  for v in nums:
      if v & -v != msk:
          chosen.append(v)
  
  print(len(chosen))
  print(' '.join(map(str, chosen)))
