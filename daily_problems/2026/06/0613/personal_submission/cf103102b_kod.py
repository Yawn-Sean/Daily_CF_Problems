s = ip()
c = t = 0
for x in s:
    if x == '0':
        c += t
    else:
        t += 1
if c % 3 : print("Alice")
else: print("Bob")




