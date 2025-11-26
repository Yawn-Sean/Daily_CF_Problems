'''
https://codeforces.com/gym/106015/submission/350641280
'''

# templates and globals are skipped
# class UnionFind:
selected_edges = set() 
# def build_mst(n: int, edges: list[list[int]]) -> list[list[int]]:
depth = [] 
dis_to_root = [] 
parent = [] 
# def tree_dfs(tg: list[list[int]]): 
nth_parent = []
# def init_lca():
# def lca(u, v):
    
def solve(n: int, m: int, edges: list[list[int]]) -> bool: 
    global dis_to_root, selected_edges
    mst = build_mst(n, edges)
    if n - 1 != len(selected_edges): 
        return False
    tree_dfs(mst)
    init_lca()
    for i in range(m):
        if not i in selected_edges:
            u, v, w = edges[i]
            l = lca(u, v)
            if dis_to_root[u] + dis_to_root[v] - 2 * dis_to_root[l] > w:
                return False
    return True
