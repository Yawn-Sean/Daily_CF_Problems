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
	var n, c int
	fmt.Fscan(in, &n, &c)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])
	}
	ans := 0
	cur := 0
	for i := n - 1; i >= 0; i-- {
		if arr[i] > cur {
			arr[i] -= cur
			w := (arr[i] + c - 1) / c
			ans += w * (i + 1)
			cur = c*w - arr[i]
		} else {
			cur -= arr[i]
		}
	}
	fmt.Fprintln(out, ans*2)
}
