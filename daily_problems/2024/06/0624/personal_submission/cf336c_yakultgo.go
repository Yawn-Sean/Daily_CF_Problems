package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	a := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &a[i])
	}
	ret := make([]int, 0)
	for i := 29; i >= 0; i-- {
		xor := (1 << i) - 1
		for j := 0; j < n; j++ {
			if a[j]>>i&1 == 1 {
				xor &= a[j]
				ret = append(ret, a[j])
			}
		}
		if xor == 0 {
			fmt.Fprintln(out, len(ret))
			for _, v := range ret {
				fmt.Fprint(out, v, " ")
			}
			return
		}
		ret = make([]int, 0)
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
