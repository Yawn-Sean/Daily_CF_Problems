from collections import Counter

n = int(input())
s = input()

cnt = Counter(s)
odds = []

for c in cnt:
  if cnt[c] & 1:
    odds.append(c)
    cnt[c] -= 1

if len(odds) == 0:
  ans = []
  for c in cnt:
    ans.append(c * (cnt[c] // 2))
  res = ''.join(ans)

  print(1)
  print(res + res[::-1])
  exit()

for i in range(len(odds), n + 1):
  if n % i == 0:
    length = n // i
    if length % 2 == 0:
      continue

    ans = []
    k = length // 2
    for _ in range(i):
      if len(odds):
        c = odds.pop()
      else:
        for ch in cnt:
          if cnt[ch] > 0:
            c = ch
            cnt[ch] -= 1
            break
      half = []
      cur = 0
      to_delete = []

      for ch in cnt:
        val = min(cnt[ch] // 2, k - cur)
        cnt[ch] -= val * 2
        if cnt[ch] == 0:
          to_delete.append(ch)
        half.append(ch * val)
        cur += val
        if cur == k: break

      for ch in to_delete:
        del cnt[ch]

      res = ''.join(half)
      ans.append(res + c + res[::-1])

    print(i)
    print(' '.join(ans))
    break
