d = ix()
o = d
while d % 2 == 0:
    d //= 2
while d % 5 == 0:
    d //= 5
cur = tot = 0
for i in range(1 , 10 ** 6):
    cur = (cur * 10 + 9) % d
    tot = (tot +9) % o
    if cur == tot == 0:
        print('9' * i + '0'*9)
        break
