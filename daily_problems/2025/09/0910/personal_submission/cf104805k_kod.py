n, l = il()
x = il()
ans = set()
que = [1]
for a in que:
    for b in x:
        v = a * (b + 1)
        if v - 1 <= l and v not in ans:
            ans.add(v)
            que.append(v)
print(len(ans))
