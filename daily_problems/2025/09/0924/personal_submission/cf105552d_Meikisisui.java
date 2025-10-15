import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());
        double max = 0.0;
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            // 对于每条直线，计算圆心到直线的距离d
            // 如果d=0，直线通过圆心，圆被平分，两部分比例均为0.5
            // 否则，较小部分的面积比例由公式计算，[arccos(d/r) - (d/r) * sin(arccos(d/r))] / π
            double d = Math.abs(c) / Math.sqrt(a * a + b * b);
            if (d >= r)
                continue;
            double d1 = Math.acos(d / r);
            double area = (d1 - (d / r) * Math.sin(d1)) / Math.PI;
            if (area > max)
                max = area;
        }
        if (max == 0.0)
            max = 0.5;
        pw.print(max + " " + (1 - max));
        pw.close();
    }

}
