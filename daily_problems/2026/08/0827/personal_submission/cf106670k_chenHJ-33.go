package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var t int
	fmt.Fscan(in, &t)
	for ; t > 0; t-- {
		var n int
		fmt.Fscan(in, &n)
		r := make([]int64, n)
		c := make([]int64, n)
		min_r := int64(math.MaxInt64)
		min_c := int64(math.MaxInt64)
		sum_r := int64(0)
		sum_c := int64(0)
		for i := range n {
			fmt.Fscan(in, &r[i])
			min_r = min(min_r, r[i])
			sum_r = sum_r + r[i]
		}
		for i := range n {
			fmt.Fscan(in, &c[i])
			min_c = min(min_c, c[i])
			sum_c = sum_c + c[i]
		}
		ans := r[0] + c[n-1]
		ans = min(ans, r[n-1]+c[0])
		ans = min(ans, min_r+c[n-1]+c[0])
		ans = min(ans, min_c+r[n-1]+r[0])
		ans = min(ans, sum_r)
		ans = min(ans, sum_c)
		fmt.Fprintln(out, ans)
	}

}
