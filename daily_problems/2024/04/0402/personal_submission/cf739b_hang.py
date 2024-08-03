# https://codeforces.com/contest/739/submission/254679970
# 树上差分 + 二分
# 2e5的数据量，注意python不能使用递归

class Node:
    def __init__(self, val) -> None:
        self.val = val
        self.child = []
        self.weigth = []
        self.parent = None
        self.dex = 0
        self.flag = 0
        self.depth = 0
def  main():
    n = II()
    a = LII()
    a = [0] + a
    nodes = []
    for i in range(n + 1):
        nodes.append(Node(a[i]))
    nodes[1].parent = nodes[0]
    for i in range(n - 1):
        c = i +  2
        p,w =MII()
        nodes[p].child.append(nodes[c])
        nodes[p].weigth.append(w)
        nodes[c].parent = nodes[p]
        nodes[p].dex += 1
    # 非递归遍历树
    ts = []
    stack = [(0, nodes[1])]
    while stack:
        depth,root = stack.pop()
        if root == None:
            ts.pop()
            continue
        root.depth += depth
        ts.append(root)
        l,r = 0, len(ts)-1
        while l < r:
            mid = (l + r) >> 1
            if ts[-1].depth - ts[mid].depth > ts[-1].val:
                l = mid + 1
            else:
                r = mid
        ts[l].parent.flag -= 1
        ts[-1].parent.flag += 1
        # 标记子节点访问完了
        stack.append((0,None))
        for i in range(len(root.child)):       
            stack.append((ts[-1].depth + root.weigth[i] ,root.child[i]))

    from queue import Queue
    q = Queue()
    for i in range(1, n + 1):
        if nodes[i].dex == 0:
            q.put(nodes[i])
    while not q.empty():
        cur = q.get()
        cur.parent.flag += cur.flag
        cur.parent.dex -= 1
        if cur.parent.dex == 0:
            q.put(cur.parent)
    ans = []
    for i in range(1, n+1):
        ans.append(nodes[i].flag)
    print(*ans)
    

main()
