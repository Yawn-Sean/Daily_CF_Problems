s = []
for _ in range(int(input())):
    s.append(input())

def f(s):
    return s.count('s') / len(s)

s.sort(reverse = True, key = lambda x: f(x))

fores = 0
ans = 0
for i in ''.join(s):
    if i == 's':
        fores += 1
    else:
        ans += fores
print(ans)
