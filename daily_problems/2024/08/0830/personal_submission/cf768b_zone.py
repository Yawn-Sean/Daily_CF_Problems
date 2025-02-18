# 问题中的列表可以转换为满二叉树的中序遍历序列
# 只需要确定每个节点的访问编号即可，由于除完后的每个数必然都是1，只需要用递归判断编号在[l, r]内所有非叶子节点的奇偶性
# https://codeforces.com/contest/768/submission/278711521

n, l, r = map(int, input().split())

ans = r - l + 1

def dfs(v: int, c: int): 
    if v == 0 or v == 1: 
        return 1 - v

    res = 0
    cnt = (1 << (v >> 1).bit_length()) - 1 + c # 可能访问的节点总个数

    if l <= cnt + 1: 
        # 访问左子树
        if cnt < r: 
            # 判断当前节点
            res += 1 - v % 2
        res += dfs(v >> 1, c)
        # 访问右子树
        if cnt + 1 < r: 
            res += dfs(v >> 1, cnt + 1)
    else: 
        # 访问右子树
        res += dfs(v >> 1, cnt + 1)
    
    return res
    
res = dfs(n, 0)
print(ans - res)
