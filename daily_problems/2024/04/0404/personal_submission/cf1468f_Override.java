//
//将初始位置看成向量的起点 末尾位置看成向量的终点 构造出一个向量 对这个向量进行归一化
//注意不能将其标准化 即横纵坐标同时除以其长度  而是用横纵坐标的gcd 对其进行归一化
//在旋转中和别人进行眼神接触的数量为 其对应的向量的负向量个数


import java.awt.Point;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static void main(String[] args) {
        try (Scanner sc = new Scanner(System.in)) {
            int testCases = sc.nextInt();
            while (testCases-- > 0) {
                Map<Point, Integer> directionCounts = new HashMap<>();
                int numberOfPairs = sc.nextInt();

                for (int i = 0; i < numberOfPairs; i++) {
                    int x1 = sc.nextInt();
                    int y1 = sc.nextInt();
                    int x2 = sc.nextInt();
                    int y2 = sc.nextInt();

                    int gcd = gcd(Math.abs(x2 - x1), Math.abs(y2 - y1));
                    int dx = (x2 - x1) / gcd;
                    int dy = (y2 - y1) / gcd;
                    Point direction = new Point(dx, dy);

                    directionCounts.put(direction, directionCounts.getOrDefault(direction, 0) + 1);
                }

                long overlappingPairs = 0;
                for (Map.Entry<Point, Integer> entry : directionCounts.entrySet()) {
                    Point currentDirection = entry.getKey();
                    int countForCurrentDirection = entry.getValue();
                    int countForOppositeDirection = directionCounts.getOrDefault(
                            new Point(-currentDirection.x, -currentDirection.y), 0);

                    overlappingPairs += (long) countForCurrentDirection * countForOppositeDirection;
                }

                System.out.println(overlappingPairs / 2);
            }
        }
    }
}
