import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int x = 0, y = 0, z;
        int[] a = new int[n], b = new int[n];
        ArrayList<Pair<Integer, Integer>> c = new ArrayList<>(), d = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
            b[i] = scanner.nextInt();
            if (a[i] > b[i]) {
                x++;
                c.add(new Pair<>(a[i], i));   //其中一种
            } else {
                y++;
                d.add(new Pair<>(b[i], i));
            }
        }

        z = c.size();
        if (x >= y) {
            System.out.println(x);
            Collections.sort(c, (p1, p2) -> p1.getKey() - p2.getKey());
            for (int i = 0; i < z; ++i) {
                System.out.print((c.get(i).getValue() + 1) + " ");
            }
        } else {
            System.out.println(y);
            Collections.sort(d, (p1, p2) -> p1.getKey() - p2.getKey());
            for (int i = n - z - 1; i >= 0; --i) {
                System.out.print((d.get(i).getValue() + 1) + " ");
            }
        }

        scanner.close();
    }

    static class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}
