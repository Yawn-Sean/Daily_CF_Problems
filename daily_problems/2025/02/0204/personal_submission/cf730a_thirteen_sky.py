N = int(input())
R = [*map(int, input().split())]
ans = []
while not all(x == R[0] for x in R):
    m = max(R)
    i = [i for i, x in enumerate(R) if x == m]
    if len(i) == 1:
        j = R.index(sorted(R)[-2])
        curr = [i[0],j]
    elif len(i) == 3:
        curr = i[:3]
    else:
        curr = i[:2]
    for j in curr:
        R[j] = max(0, R[j]-1)
    ans.append("".join("01"[j in curr] for j in range(len(R))))
print(R[0])
print(len(ans))
print(*ans, sep="\n")
