package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

const maxN = int(1e7) // 假设一个较大的常数值作为上限

var factorSum = make([]int, maxN+1)
var prime []int // 现在已经筛出的素数列表 // 上限，即筛出<=n的素数
var arr = make([]int, maxN+1)

func init() {
	factorSum[1] = 1 // 1不是素数
	arr[1] = 1

	for i := 2; i < maxN; i++ { // i从2循环到n（外层循环）
		if factorSum[i] == 0 {
			prime = append(prime, i)
			factorSum[i] = i + 1
		} else {
			cur := factorSum[i]
			sm := 1 + cur
			for i%(cur*factorSum[i]) == 0 {
				cur *= factorSum[i]
				sm += cur
			}
			if cur == i {
				factorSum[i] = sm
			} else {
				factorSum[i] = factorSum[cur] * factorSum[i/cur]
			}
		}
		if factorSum[i] <= maxN && arr[factorSum[i]] == 0 {
			arr[factorSum[i]] = i
		}
		// 如果i没有被前面的数筛掉，则i是素数
		for j := 0; j < len(prime) && i*prime[j] <= maxN; j++ {
			// 筛掉i的素数倍，即i的prime[j]倍
			// j循环枚举现在已经筛出的素数（内层循环）
			factorSum[i*prime[j]] = prime[j]
			// 倍数标记为合数，也就是i用prime[j]把i * prime[j]筛掉了
			if i%prime[j] == 0 {
				break
			}
			// 最神奇的一句话，如果i整除prime[j]，退出循环
			// 这样可以保证线性的时间复杂度
		}
	}
}

func main() { CF1512G(os.Stdin, os.Stdout) }

func CF1512G(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var t, c int
	fmt.Fscan(in, &t)

	for i := 0; i < t; i++ {
		fmt.Fscan(in, &c)
		if arr[c] > 0 {
			fmt.Fprintf(out, "%d\n", arr[c])
		} else {
			fmt.Fprintf(out, "-1\n")
		}
	}
}
