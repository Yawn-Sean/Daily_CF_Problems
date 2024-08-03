# Submission link: https://codeforces.com/contest/1010/submission/257107851
def main():
    n = II()

    ops = [-1] * n
    tree = [[] for _ in range(n)]
    parent = [-1] * n

    op_map = dict(zip('AONX', [2, 3, 4, 5]))

    for i in range(n):
        op, *vals = LI()
        vals = [int(x) - 1 for x in vals]
        
        if op[0] == 'I':
            ops[i] = vals[0] + 1
        
        else:
            tree[i] = vals
            for v in vals:
                parent[v] = i
            ops[i] = op_map[op[0]]

    order = []
    stack = [0]
    while stack:
        u = stack.pop()
        for v in tree[u]:
            stack.append(v)
        order.append(u)

    cur_res = [-1] * n

    for i in reversed(order):
        if len(tree[i]) == 0:
            cur_res[i] = ops[i]
        else:
            if ops[i] == 2: cur_res[i] = cur_res[tree[i][0]] & cur_res[tree[i][1]]
            elif ops[i] == 3: cur_res[i] = cur_res[tree[i][0]] | cur_res[tree[i][1]]
            elif ops[i] == 4: cur_res[i] = cur_res[tree[i][0]] ^ 1
            else: cur_res[i] = cur_res[tree[i][0]] ^ cur_res[tree[i][1]]

    stack = [0]
    reverse_note = [0] * n
    reverse_note[0] = 1

    while stack:
        u = stack.pop()
        if len(tree[u]):
            f = 0
            if ops[u] == 2:
                v, w = tree[u][0], tree[u][1]
                if cur_res[u] == 0:
                    if cur_res[v]:
                        stack.append(w)
                        reverse_note[w] = 1
                    elif cur_res[w]:
                        stack.append(v)
                        reverse_note[v] = 1
                else:
                    stack.append(v)
                    stack.append(w)
                    reverse_note[v] = reverse_note[w] = 1
            elif ops[u] == 3:
                v, w = tree[u][0], tree[u][1]
                if cur_res[u] == 1:
                    if cur_res[v] == 0:
                        stack.append(w)
                        reverse_note[w] = 1
                    elif cur_res[w] == 0:
                        stack.append(v)
                        reverse_note[v] = 1
                else:
                    stack.append(v)
                    stack.append(w)
                    reverse_note[v] = reverse_note[w] = 1
            else:
                for v in tree[u]:
                    stack.append(v)
                    reverse_note[v] = 1

    print(''.join(str(reverse_note[i] ^ cur_res[0]) for i in range(n) if len(tree[i]) == 0))