# Submission link: https://codeforces.com/contest/1133/submission/264089918
class Solution {
    public List<int[]> solve(int[][] edges, int n, int d) {
        List<int[]> list = new ArrayList<>();
        Set<Integer>[] sets = new Set[n];
        for (int i = 0; i < n; i++) {
            sets[i] = new HashSet<>();
        }
        for (int[] edge : edges) {
            sets[edge[0]].add(edge[1]);
            sets[edge[1]].add(edge[0]);
        }
        if (sets[0].size() < d) {
            return null;
        }
        UnionFind unionFind = new UnionFind(n);
        for (int[] edge : edges) {
            if (edge[0] != 0 && edge[1] != 0) {
                unionFind.union(edge[0], edge[1]);
            }
        }
        int t = unionFind.size - 1;
        if (d < t) {
            return null;
        }
        t = d;
        boolean[] vis = new boolean[n];
        vis[0] = true;
        ArrayDeque<Integer> deque = new ArrayDeque<>();
        for (Integer v : sets[0]) {
            if (unionFind.isUnion(0, v)) {
                continue;
            }
            unionFind.union(0, v);
            list.add(new int[]{0, v});
            deque.add(v);
            vis[v] = true;
            t--;
        }
        for (Integer v : sets[0]) {
            if (t == 0) {
                break;
            }
            if (vis[v]) {
                continue;
            }
            list.add(new int[]{0, v});
            deque.add(v);
            vis[v] = true;
            t--;
        }
        while (!deque.isEmpty()) {
            Integer remove = deque.remove();
            for (Integer w : sets[remove]) {
                if (vis[w]) {
                    continue;
                }
                list.add(new int[]{remove, w});
                deque.add(w);
                vis[w] = true;
            }
        }
        return list;
    }
}
