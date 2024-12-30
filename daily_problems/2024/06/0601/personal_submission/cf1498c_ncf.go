package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1498C(os.Stdin, os.Stdout) }

func CF1498C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, n, k int
	fmt.Fscan(in, &t)
	mod := int(1e9 + 7)
	for ; t > 0; t -= 1 {
		fmt.Fscan(in, &n, &k)
		a1 := make([]int, n)     // 上一个数组的值
		a2 := make([]int, n)     // 下一个数组的差分
		for i := 0; i < n; i++ { // 最开始只有一个向右的粒子
			a1[i] = 1
		}
		ans := 1                 // 初始有一个粒子
		for i := 1; i < k; i++ { // 有k-1个会产生新粒子的年龄
			for j := 0; j < n; j++ { // 对于第j块挡板，给0~j-1都用差分加上1，并且产生了a1[j]个粒子，答案加上
				a2[0] += a1[j]
				a2[j] -= a1[j]
				ans = (ans + a1[j]) % mod
			}
			cur := 0
			for j := 0; j < n; j++ { // 对差分求前缀和，并更新a1
				cur += a2[j]
				a1[j] = cur % mod
			}
			for j := 0; j*2 < n; j++ { // 反转数组并将差分数组清零
				a1[j], a1[n-j-1] = a1[n-j-1], a1[j]
				a2[j], a2[n-j-1] = 0, 0
			}
		}
		fmt.Fprintf(out, "%d\n", ans)
	}
}
