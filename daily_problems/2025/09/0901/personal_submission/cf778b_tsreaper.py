n, m = map(int, input().split())
A, OP = [], []
d = {}
for i in range(n):
    parts = input().split()
    d[parts[0]] = i
    for i in range(2, len(parts), 2):
        if not parts[i].isdigit() and parts[i] != '?':
            parts[i] = d[parts[i]]
    if len(parts) == 3:
        A.append([parts[2]])
        OP.append('')
    else:
        A.append([parts[2], parts[4]])
        OP.append(parts[3])

def gao(s, i, v):
    if s == '?':
        return v
    elif isinstance(s, str):
        return ord(s[i]) - ord('0')
    else:
        return w[s]

ans1, ans2 = '', ''

for i in range(m):
    res = [0, 0]
    for v in range(2):
        w = [0] * n
        for j in range(n):
            if OP[j] == '':
                w[j] = gao(A[j][0], i, v)
            else:
                a = gao(A[j][0], i, v)
                b = gao(A[j][1], i, v)
                if OP[j] == 'AND':
                    w[j] = a & b
                elif OP[j] == 'OR':
                    w[j] = a | b
                else:
                    w[j] = a ^ b
        res[v] = sum(w)

    if res[0] < res[1]:
        ans1 += '0'
        ans2 += '1'
    elif res[0] == res[1]:
        ans1 += '0'
        ans2 += '0'
    else:
        ans1 += '1'
        ans2 += '0'

print(ans1)
print(ans2)
