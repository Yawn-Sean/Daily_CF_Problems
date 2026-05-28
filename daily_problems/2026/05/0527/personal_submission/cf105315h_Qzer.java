import java.util.*;
import java.io.*;
import java.math.*;

//有时候啊，TLE的点不在算法实现本身，可能在输出的方式上，试试把所有输出链接为StringBuilder在一下子输出~~~
//数的level更新要在递归子树之前
//提交实在MLE，需要检查：1、数据结构长度过长；2、将long改为int；；3、实在不行改成char或者short甚至byte类型试试哇~~~
//指针型的数据结构体，如线段树或者字典树，效率有时会很低，可以考虑数组模拟，并且注意数组维度的先后
//取模次数过多耗时会大幅增加，可以设一个取模的阈值，并用减，最后答案在取总模
//取模的数字，别少写(int)1e9+7，inf别写错类型(long)8e18
//初始化数据的时候，最小值不要傻乎乎的默认为0，因为可能有负数
//记住看数字范围，需要开long吗，需要用BigInteger吗，需要手动处理字符串吗，复杂度数量级控制在1e7或者以下了吗
//开数组的数据范围最高不能超过1e7，数据范围再大就要用哈希表离散化了
//基本数据类型不能自定义sort排序，二维数组就可以了，顺序排序的时候是小减大，注意返回值应该是int
//BFS的时候记得在循环里要往队列里push，拓扑排序要确认无环
//“>>”运算的时候，int和long类型得到的数字可能是不同的
//(a + b) mod m = ((a mod m) + (b % m)) mod m
//(a * b) mod m = ((a mod m) * (b % m)) mod m
public class Main {
    public static int mod = 998244353;
    public static int[] dirs = {-1, 0, 1, 0, -1};

    public static void main(String[] args) throws IOException {
        Read sc = new Read();

        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            int k = sc.nextInt();
            long[][] arr = new long[n][2];
            for (int i = 0; i < n; i++) {
                arr[i][0] = sc.nextLong();
                arr[i][1] = sc.nextLong();
            }
            Arrays.sort(arr, (o1, o2) -> Long.compare(o1[1], o2[1]));
            PriorityQueue<Long> pq = new PriorityQueue<>();
            long sumA = 0;
            long sum = Long.MIN_VALUE;
            for (int i = 0; i < n; i++) {
                pq.offer(arr[i][0]);
                sumA += arr[i][0];
                if (pq.size() > k) {
                    sumA -= pq.poll();
                }
                if (pq.size() == k) {
                    sum = Math.max(sum, sumA - arr[i][1]);
                }
            }
            sc.println(sum);
        }

        sc.flush();
        sc.bw.close();
    }
}

class Read {
    BufferedReader bf;
    StringTokenizer st;
    BufferedWriter bw;

    public Read() {
        bf = new BufferedReader(new InputStreamReader(System.in));
        st = new StringTokenizer("");
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        //什么时候才能持续稳定ak力扣、AcWing呢？
        //什么时候才能ak cf的div2，（div1）呢？才能打div2不计rating呢？
        //什么时候才能ak  abc  arc 不计rating呢？
        //什么时候才能ak 牛客练习赛不计rating呢?
        //什么时候才能ak 洛谷的div2呢？才能打div2不计rating呢？
    }

    //输入部分：

    public String nextLine() throws IOException {
        return bf.readLine();
    }

    public String next() throws IOException {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(bf.readLine());
        }
        return st.nextToken();
    }

    public char nextChar() throws IOException {
        //确定下一个token只有一个字符的时候再用
        return next().charAt(0);
    }

    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    public float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }

    public byte nextByte() throws IOException {
        return Byte.parseByte(next());
    }

    public short nextShort() throws IOException {
        return Short.parseShort(next());
    }

    public BigInteger nextBigInteger() throws IOException {
        return new BigInteger(next());
    }

    public BigDecimal nextDecimal() throws IOException {
        return new BigDecimal(next());
    }

    //以下为输出部分：：

    public void println(int a) throws IOException {
        print(a);
        println();
        return;
    }

    public void print(int a) throws IOException {
        bw.write(String.valueOf(a));
        return;
    }

    public void println(String a) throws IOException {
        print(a);
        println();
        return;
    }

    public void print(String a) throws IOException {
        bw.write(a);
        return;
    }

    public void println(long a) throws IOException {
        print(a);
        println();
        return;
    }

    public void print(long a) throws IOException {
        bw.write(String.valueOf(a));
        return;
    }

    public void println(double a) throws IOException {
        print(a);
        println();
        return;
    }

    public void print(double a) throws IOException {
        bw.write(String.valueOf(a));
        return;
    }

    public void print(BigInteger a) throws IOException {
        bw.write(a.toString());
        return;
    }

    public void print(char a) throws IOException {
        bw.write(String.valueOf(a));
        return;
    }

    public void println(char a) throws IOException {
        print(a);
        println();
        return;
    }

    public void println() throws IOException {
        bw.newLine();
        return;
    }

    //其他调试命令：
    public void flush() throws IOException {
        //交互题分组调试，或者提前退出的情况下可以先运行此语句再推出
        bw.flush();
        return;
    }

    public boolean hasNext() throws IOException {
        //本地普通IDE难以使用这个方法调试，需要按照数据组flush，刷新语句:
        //sc.flush()
        //调试完可删去
        return bf.ready();
    }
}