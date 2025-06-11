import java.io.PrintWriter;
import java.util.Scanner;

public class Test3 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] res = new int[n + 1];
        Test3 test = new Test3();
        test.init(n);
        int a, b;
        for (int i = 0; i < n - 1; i++) {
            a = sc.nextInt();
            b = sc.nextInt();
            a = test.find(a);
            b = test.find(b);
            test.union(b, a);
            res[right[a]] = left[b];
            right[a] = right[b];
        }
        a = left[test.find(1)];
        while (a != 0) {
            System.out.printf("%d ", a);
            a = res[a];
        }
        pw.close();
        sc.close();
    }

    private int[] father;
    private static int[] left, right;

    private void init(int n) {
        this.father = new int[n + 1];
        this.left = new int[n + 1];
        this.right = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            father[i] = i;
            left[i] = right[i] = i;
        }
    }

    private int find(int x) {
        if (father[x] == x)
            return x;
        return father[x] = find(father[x]);
    }

    private boolean isSameSet(int a, int b) {
        return find(a) == find(b);
    }

    private void union(int a, int b) {
        father[a] = b;
    }

}
