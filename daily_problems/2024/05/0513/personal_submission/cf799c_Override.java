//二分 或者 树状数组
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class c799 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int SIZE = 100010;

    static int[] tree1 = new int[SIZE];
    static int[] tree2 = new int[SIZE];
    public static void main(String[] args) throws Exception {
        String[] te = br.readLine().split(" ");

        int n =  Integer.parseInt(te[0]);
        int c =  Integer.parseInt(te[1]);
        int d =  Integer.parseInt(te[2]);

        for (int i=0; i<SIZE; i++) {
            tree1[i] = -1000000;
            tree2[i] = -1000000;
        }
        int ans = 0;

        for (int i = 0; i < n; i++) {
            String[] values = br.readLine().split(" ");
            int b = Integer.parseInt(values[0]), p = Integer.parseInt(values[1]);
            char v = values[2].charAt(0);

            if (v == 'C' && p<= c) {
                ans = Math.max(ans,b+getmax(tree2,d));
                ans = Math.max(ans,b+getmax(tree1,c-p));
                update(tree1,p,b);
            } else if(v == 'D' && p<=d){
                ans = Math.max(ans,b+getmax(tree1,c));
                ans = Math.max(ans,b+getmax(tree2,d-p));
                update(tree2,p,b);
            }
        }

        System.out.println(ans);
    }
    public static int lowbit(int x) {
        return x & (-x);
    }

    public static int getmax(int[] tree, int x) {
        int ans = -10000000;
        while(x >0) {
            ans = Math.max(ans, tree[x]);
            x -= lowbit(x);
        }
        return ans;
    }

    public static void update(int[] tree, int x, int value) {
        while(x < SIZE) {
            tree[x] = Math.max(tree[x], value);
            x += lowbit(x);
        }
    }
}
