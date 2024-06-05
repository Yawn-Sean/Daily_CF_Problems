//离散化+树状数组  待补
//记得开long
import java.util.*;

public class e2_1579 {
    static final int N = 200010;
    static int T, n;
    static long ans;
    static int[] a = new int[N];
    static int[] b = new int[N];
    static int[] cnt = new int[N];
    static int[] d = new int[N << 1];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = read(sc);
        while (T-- > 0) {
            Arrays.fill(cnt, 0);
            Arrays.fill(d, 0);
            ans = 0;
            n = read(sc);
            for (int i = 1; i <= n; i++) a[i] = read(sc);
            for (int i = 1; i <= n; i++) b[i] = a[i];
            Arrays.sort(b, 1, n + 1);
            for (int i = 1; i <= n; i++) a[i] = lowerBound(b, 1, n + 1, a[i]);
            add(a[1]);
            cnt[a[1]]++;
            for (int i = 2; i <= n; i++) {
                int s = sum(a[i]);
                ans += Math.min(s - cnt[a[i]], i - s - 1);
                add(a[i]);
                cnt[a[i]]++;
            }
            System.out.println(ans);
        }
    }

    static void add(int x) {
        for (; x <= n; x += lowbit(x)) d[x]++;
    }

    static int sum(int x) {
        int cnt = 0;
        for (; x > 0; x -= lowbit(x)) cnt += d[x];
        return cnt;
    }

    static int lowbit(int x) {
        return x & (-x);
    }

    static int read(Scanner sc) {
        return sc.nextInt();
    }

    static int lowerBound(int[] arr, int fromIndex, int toIndex, int key) {
        int low = fromIndex;
        int high = toIndex - 1;
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (arr[mid] < key) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
}
