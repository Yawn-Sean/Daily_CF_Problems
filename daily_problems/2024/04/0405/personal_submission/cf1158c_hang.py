def main():
    n = int(input())
    nxt = list(map(int, input().split()))
    nxt = [x - 1 for x in nxt]
    for i in range(n):
        if nxt[i] == -2:
            nxt[i] = i + 1
    z = [[] for _ in range(n + 1)]
    p = [0] * (n)
    for i in range(n):
        z[nxt[i]].append(i)
    idx = 1
    for i in range(n + 1):
        for j in reversed(z[i]):
            p[j] = idx
            idx += 1
    st = [n]
    for i in range(n - 1, - 1, -1):
        while st[-1] != n and p[i] > p[st[-1]]:
            st.pop()
        if nxt[i] != st[-1]:
            return [-1]
        st.append(i)
    return p



t = int(input())
while t:
    t -= 1
    print(*main())