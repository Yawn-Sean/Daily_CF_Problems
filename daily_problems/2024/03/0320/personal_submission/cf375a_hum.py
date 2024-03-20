s = input()

d = ["1869", "1968", "1689", "6198", "1698", "1986", "1896"]

c_0 = s.count("0")
s_1689 = set()
s_1689.add(s.find("1"))
s_1689.add(s.find("6"))
s_1689.add(s.find("8"))
s_1689.add(s.find("9"))
res = []
rem = 0
for i, c in enumerate(s):
  if c == "0" or i in s_1689:
    continue
  res.append(c)
  rem = (rem * 10 + int(c)) % 7
rem = (rem * 10000) % 7

res.append(d[(7 - rem) % 7])
res.append("0" * c_0)

print("".join(res))
