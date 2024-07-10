import java.util.*;
import java.io.*;

public class Main {
    
    static void solve() {
        int n = sc.nextInt(), m = sc.nextInt();
        char[] str = sc.next().toCharArray();
        int sum = 0;
        int[][] val = new int[n][];
        TreeSet<Integer> set = new TreeSet<>();
        for (int i = 0, j = i; i < n; i = j) {
            while (j < n && str[i] == str[j]) {
                j++;
            }
            if (str[i] == '.') {
                sum += j - i - 1;
                val[i] = new int[]{i, j - 1};
                set.add(i);
            }
        }
        while (m-- > 0) {
            int x = sc.nextInt() - 1;
            char c = sc.next().charAt(0);
            if (str[x] == '.' && c != '.') {
                str[x] = 'a';
                int floor = set.floor(x);
                set.remove(floor);
                int[] tup = val[floor];
                int l = tup[0], r = tup[1];
                sum -= r - l;
                int a = l, b = x - 1;
                if (a <= b) {
                    sum += b - a;
                    val[a] = new int[]{a, b};
                    set.add(a);
                }
                a = x + 1; b = r;
                if (a <= b) {
                    sum += b - a;
                    val[a] = new int[]{a, b};
                    set.add(a);
                }
            } else if (str[x] != '.' && c == '.') {
                str[x] = '.';
                Integer floor = set.floor(x), ceiling = set.ceiling(x);
                if (floor == null && ceiling == null) {
                    val[x] = new int[]{x, x};
                    set.add(x);
                } else if (floor == null) {
                    int[] tup = val[ceiling];
                    if (tup[0] == x + 1) {
                        sum++;
                        set.remove(tup[0]);
                        tup[0] = x;
                        set.add(x);
                        val[x] = tup;
                    } else {
                        val[x] = new int[]{x, x};
                        set.add(x);
                    }
                } else if (ceiling == null) {
                    int[] tup = val[floor];
                    if (tup[1] == x - 1) {
                        sum++;
                        tup[1] = x;
                    } else {
                        val[x] = new int[]{x, x};
                        set.add(x);
                    }
                } else {
                    int[] left = val[floor], right = val[ceiling];
                    if (left[1] < x - 1 && right[0] > x + 1) {
                        val[x] = new int[]{x, x};
                        set.add(x);
                    } else if (left[1] < x - 1) {
                        sum++;
                        set.remove(right[0]);
                        right[0] = x;
                        set.add(x);
                        val[x] = right;
                    } else if (right[0] > x + 1) {
                        sum++;
                        left[1] = x;
                    } else {
                        sum += 2;
                        set.remove(right[0]);
                        left[1] = right[1];
                    }
                }
            }
            out.println(sum);
        }
    }

}
