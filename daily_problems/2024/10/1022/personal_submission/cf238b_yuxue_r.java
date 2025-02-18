import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int h = scanner.nextInt();

        ArrayList<Integer> nums = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            nums.add(scanner.nextInt());
        }

        int inf = (int) 1e8;
        int mi1 = inf, mi2 = inf, mi3 = inf, ma1 = 0, ma2 = 0;

        for (int v : nums) {
            if (v <= mi1) {
                mi3 = mi2;
                mi2 = mi1;
                mi1 = v;
            } else if (v <= mi2) {
                mi3 = mi2;
                mi2 = v;
            } else if (v < mi3) {
                mi3 = v;
            }

            if (v >= ma1) {
                ma2 = ma1;
                ma1 = v;
            } else if (v > ma2) {
                ma2 = v;
            }
        }

        int f1 = (ma1 + ma2) - (mi1 + mi2);
        int f2 = Math.max(ma1 + ma2, mi1 + ma1 + h) - Math.min(mi2 + mi3, mi1 + mi2 + h);

        if (f1 <= f2) {
            System.out.println(f1);
            for (int i = 0; i < n; i++) {
                System.out.print("1 ");
            }
        } else {
            System.out.println(f2);
            boolean flg = true;
            for (int i = 0; i < n; i++) {
                if (flg && nums.get(i) == mi1) {
                    flg = false;
                    System.out.print("2 ");
                } else {
                    System.out.print("1 ");
                }
            }
        }

        scanner.close();
    }
}
