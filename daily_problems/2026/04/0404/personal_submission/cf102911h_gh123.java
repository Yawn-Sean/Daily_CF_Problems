
import java.util.Arrays;
import java.util.Scanner;


public class cf102911h {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int[]v1=new int[n];
        int[]v2=new int[n];
        for (int i = 0; i < n; i++) {
            v1[i]=sc.nextInt();
        }   
        for (int i = 0; i < n; i++) {
            v2[i]=sc.nextInt();
        }
        int[][]arr=new int[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0]=v1[i];
            arr[i][1]=i;
        }
        Arrays.sort(arr,(a,b)->a[0]-b[0]);
        long ans=0;
        FenwickTree fen=new FenwickTree(n);
        for (int i = 0; i < n; i++) {
            int idx=arr[i][1];
            long cur=fen.queryRange(idx, n-1);
            ans+=cur*v2[idx];
            fen.add(idx, v2[idx]);
        }
        System.out.println(ans);
        sc.close();
    }
     static class FenwickTree {
        int n;
        long[] tree;
        public FenwickTree(int n) {
            this.n = n;
            this.tree = new long[n + 1];
        }
        public void add(int i, int val) {
            i++; 
            while (i <= n) {
                tree[i] += val;
                i += i & -i;
            }
        }
        private long query(int i) {
            i++;
            long s = 0;
            while (i > 0) {
                s += tree[i];
                i -= i & -i;
            }
            return s;
        }
        public long queryRange(int l, int r) {
            if (l > r) return 0;
            return query(r) - query(l - 1);
        }
    }

}
