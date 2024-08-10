import java.io.PrintWriter;
import java.util.Scanner;

public class Test3 {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[] nums = new int[n];
        int[] pos = new int[n + 1];
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            nums[i] = a;
            pos[a] = i;
        }
        char[] cc = new char[n];
        for (int value = n; value >= 1; value--) {
            int i = pos[value];
            boolean awin = false;
            for (int j = i % value; j < n; j += value) {
                if (j != i && cc[j] == 'B') {
                    awin = true;
                    break;
                }
            }
            cc[i] = awin ? 'A' : 'B';
        }
        pw.println(cc);
        pw.close();
    }

}
