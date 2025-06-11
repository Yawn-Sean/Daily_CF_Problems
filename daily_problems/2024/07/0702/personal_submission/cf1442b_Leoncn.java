public class cf1442b_Leoncn {
    public static void solve() {
        int mod = 998244353;
        int n = sc.ni(), k = sc.ni();
        int[] g = sc.na(n);
        int[] tar = sc.na(k);
        Node[] arr = new Node[n+2];
        Node pre = new Node(0);
        arr[0] = pre;
        for (int i = 0; i < n; i++) {
            Node node = new Node(g[i]);
            pre.next = node;
            node.pre = pre;
            pre = node;
            arr[g[i]] = node;
        }
        Node last = new Node(n+1);
        last.pre = pre;
        pre.next = last;
        arr[n+1] = last;
        long ans = 1;

        boolean[] vis = new boolean[n+1];
        for (int i = 0; i < k; i++) {
            vis[tar[i]] = true;
        }
        for (int i = 0; i < k; i++) {
            int a = tar[i];
            int cnt = 0;
            Node node = arr[a];
            if(node.pre.val>0 && ! vis[node.pre.val]){
                cnt++;
            }
            if(node.next.val<=n&& !vis[node.next.val]){
                cnt++;
            }
            ans = ans * cnt %mod;
            arr[node.next.val].pre = arr[node.pre.val];
            arr[node.pre.val].next = arr[node.next.val];
        }
        out.println(ans);
    }
    static class Node{
        int val;
        Node pre;
        Node next;

        Node (int v){
            val = v;
        }
    }
}
