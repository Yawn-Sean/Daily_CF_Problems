mii = lambda: map(int, input().split())

n, a, b = mii()
a -= 1; b -= 1
strategy1 = [[x-1 for x in mii()] for _ in range(3)]
strategy2 = [[x-1 for x in mii()] for _ in range(3)]
mp = {(a, b): 0}
turns = [(a, b)]
i = 1
while True:
    a, b = strategy1[a][b], strategy2[a][b]
    if (a, b) in mp:
        loop = i - mp[(a, b)]
        break
    mp[(a, b)] = i
    turns.append((a, b))
    i += 1

start = i - loop
tot1, tot2 = 0, 0
for i in range(min(start, n)):
    t1, t2 = turns[i]
    if (t1 == 2 and t2 == 1) or (t1 == 1 and t2 == 0) or (t1 == 0 and t2 == 2):
        tot1 += 1
    elif (t2 == 2 and t1 == 1) or (t2 == 1 and t1 == 0) or (t2 == 0 and t1 == 2):
        tot2 += 1
n = max(n - start, 0)
rounds = n // loop
for i in range(start, start+loop):
    t1, t2 = turns[i]
    if (t1 == 2 and t2 == 1) or (t1 == 1 and t2 == 0) or (t1 == 0 and t2 == 2):
        tot1 += rounds
    elif (t2 == 2 and t1 == 1) or (t2 == 1 and t1 == 0) or (t2 == 0 and t1 == 2):
        tot2 += rounds
for i in range(start, start+n%loop):
    t1, t2 = turns[i]
    if (t1 == 2 and t2 == 1) or (t1 == 1 and t2 == 0) or (t1 == 0 and t2 == 2):
        tot1 += 1
    elif (t2 == 2 and t1 == 1) or (t2 == 1 and t1 == 0) or (t2 == 0 and t1 == 2):
        tot2 += 1

print(tot1, tot2)