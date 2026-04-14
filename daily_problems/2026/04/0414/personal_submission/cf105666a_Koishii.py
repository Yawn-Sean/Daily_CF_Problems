n = int(input())

se = set([1])
q = [1]

for x in q:
    for i in range(2, 10):
        nx = x * i
        if nx > n or nx in se:
            continue
        if str(i) in str(nx):
            q.append(nx)
            se.add(nx)

print(len(se))
