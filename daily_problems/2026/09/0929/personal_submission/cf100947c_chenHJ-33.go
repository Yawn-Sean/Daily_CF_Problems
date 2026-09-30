package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var T int
	fmt.Fscan(in, &T)
	for ; T > 0; T-- {
		var n int
		fmt.Fscan(in, &n)
		arr := make([]int, n)
		for i := range arr {
			fmt.Fscan(in, &arr[i])
		}
		sum1, sum2 := 0, 0
		for i, v := range arr {
			if i%2 == 0 {
				sum1 += v
			} else {
				sum2 += v
			}
		}
		if n%2 == 0 {
			fmt.Fprintln(out, max(sum1, sum2))
			return
		}
		ans := sum1
		for _, v := range arr {
			sum1 -= v
			sum1, sum2 = sum2, sum1
			sum1 += v
			ans = max(ans, sum1)
		}
		fmt.Fprintln(out, ans)
	}

}
