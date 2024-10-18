import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt(); // 读取元素个数
        int k = scanner.nextInt(); // 读取需要选择的元素个数

        List<Integer> ls = new ArrayList<>(); // 存储元素的左边界
        List<Integer> rs = new ArrayList<>(); // 存储元素的右边界
        for (int i = 0; i < n; i++) {
            ls.add(scanner.nextInt());
            rs.add(scanner.nextInt());
        }

        List<Integer> sortedRange = new ArrayList<>(); // 存储排序后的索引
        for (int i = 0; i < n; i++) {
            sortedRange.add(i);
        }
        Collections.sort(sortedRange, new Comparator<Integer>() {
            @Override
            public int compare(Integer i, Integer j) {
                return ls.get(i) - ls.get(j);
            }
        }); // 对元素的左边界进行排序

        int ans = -1; // 初始化最大差值
        int chosenL = -1; // 初始化最大差值对应的左边界
        PriorityQueue<Integer> pq = new PriorityQueue<>(); // 初始化最小堆

        // 遍历所有元素
        for (int i : sortedRange) {
            pq.offer(rs.get(i)); // 将元素的右边界添加到最小堆
            if (pq.size() > k) {
                pq.poll(); // 如果堆中元素数量超过 k，则弹出最小值
            }
            if (pq.size() == k && pq.peek() - ls.get(i) > ans) { // 如果堆中元素数量等于 k，则更新最大差值
                ans = pq.peek() - ls.get(i);
                chosenL = ls.get(i);
            }
        }

        if (ans == -1) { // 如果没有找到满足条件的元素
            System.out.println(ans + 1);
            for (int i = 1; i <= k; i++) {
                System.out.print(i + " ");
            }
        } else { // 找到满足条件的元素
            System.out.println(ans + 1);
            for (int i = 0; i < n; i++) {
                if (k > 0 && ls.get(i) <= chosenL && rs.get(i) >= chosenL + ans) {
                    k--;
                    System.out.print(i + 1 + " ");
                }
            }
        }
    }
}
