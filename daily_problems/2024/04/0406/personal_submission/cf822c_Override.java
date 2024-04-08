import java.io.*;
import java.util.*;

public class Main {

    static long MAX = 1l<<60;

    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(reader.readLine());
        int total = Integer.parseInt(st.nextToken());
        int target = Integer.parseInt(st.nextToken());

        Coupon[] coupons = new Coupon[total];

        for (int i = 0; i < total; i++) {
            st = new StringTokenizer(reader.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            int price = Integer.parseInt(st.nextToken());
            coupons[i] = new Coupon(start, end, price, end - start + 1, price);
        }

        Arrays.sort(coupons, new CouponComparator());
        for (int i = 0; i < total; i++) {
            if (i > 0 && coupons[i].duration == coupons[i - 1].duration) {
                coupons[i].minPrice = Math.min(coupons[i].minPrice, coupons[i - 1].minPrice);
            }
        }

        long result = MAX;
        for (int i = 0; i < total; i++) {
            result = Math.min(findCheapestPair(coupons, i, 0, total - 1, target), result);
        }
        if (result == MAX) {
            writer.write("-1");
        } else {
            writer.write(Long.toString(result));
        }
        writer.flush();
        writer.close();
    }

    private static long findCheapestPair(Coupon[] coupons, int index, int left, int right, int target) {
        int middle;
        long cheapest = MAX;
        while (left <= right) {
            middle = (left + right) / 2;
            if (coupons[index].duration + coupons[middle].duration < target) {
                left = middle + 1;
            } else if (coupons[index].duration + coupons[middle].duration == target) {
                if (coupons[index].start <= coupons[middle].end) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                    cheapest = Math.min(cheapest, coupons[index].price + coupons[middle].minPrice);
                }
            } else {
                right = middle - 1;
            }
        }
        return cheapest;
    }

    static class Coupon {
        int start, end, price, duration, minPrice;

        Coupon(int start, int end, int price, int duration, int minPrice) {
            this.start = start;
            this.end = end;
            this.price = price;
            this.duration = duration;
            this.minPrice = minPrice;
        }
    }

    static class CouponComparator implements Comparator<Coupon> {
        @Override
        public int compare(Coupon o1, Coupon o2) {
            if (o1.duration == o2.duration) {
                return o1.end - o2.end;
            }
            return o1.duration - o2.duration;
        }
    }
}
