n = int(input())
v = [2] * 10

for _ in range(n):
    c, t = input().split()
    t = int(t)

    if c == '|':
        for i in range(10):
            if (t >> i) & 1:
                v[i] = 1
    elif c == '&':
        for i in range(10):
            if not (t >> i) & 1:
                v[i] = 0
    elif c == '^':
        for i in range(10):
            if (t >> i) & 1:
                v[i] ^= 1

v1 = 0
v2 = 0
v3 = 0
for i in range(10):
    if v[i] == 0:
        v1 |= 1 << i
    if v[i] == 1:
        v2 |= 1 << i
    if v[i] == 3:
        v3 |= 1 << i

print("3")
print(f"& {1023 ^ v1}")
print(f"| {v2}")
print(f"^ {v3}")
