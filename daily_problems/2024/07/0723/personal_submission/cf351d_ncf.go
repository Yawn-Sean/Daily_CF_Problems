package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"strconv"
	"strings"
)

func main() { CF351D(os.Stdin, os.Stdout) }

func CF351D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	var s string
	fmt.Fscan(in, &n)
	nums := make([]int, 2*n)
	for i := 0; i < 2*n; i++ {
		fmt.Fscan(in, &s)
		nums[i], _ = strconv.Atoi(strings.Split(s, ".")[1])
	}

	var tot, cnt int
	for i := 0; i < 2*n; i++ {
		tot += nums[i]
		if nums[i] == 0 {
			cnt += 1
		}
	}

	ans := int(1e9)
	for i := max(n-cnt, 0); i <= min(2*n-cnt, n); i++ { // 根据向上取整个数范围来枚举可能性
		ans = min(ans, abs(1000*i-tot))
	}

	fmt.Fprintf(out, "%d.%03d\n", ans/1000, ans%1000)
}

func abs(a int) int {
	if a >= 0 {
		return a
	}
	return -a
}
