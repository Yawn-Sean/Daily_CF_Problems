from itertools import permutations

d = ''
i = 0
while len(d) != 4:
    print(str(i)*4)
    a = input()
    if a != '0 0':
        d += str(i)
    i += 1

for w in permutations(d):
    i = ''.join(w)
    print(i)
    a = input()
    if a == '4 0':
        break
