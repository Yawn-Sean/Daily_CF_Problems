package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1059C(os.Stdin, os.Stdout) }

func CF1059C(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	var f func(n int) []int
	f = func(n int) []int {
		res := make([]int, n)
		if n <= 3 {
			for i := 0; i < n-1; i++ {
				res[i] = 1
			}
			res[n-1] = n
			return res
		}
		i := 0
		for ; i < n-n/2; i++ {
			res[i] = 1
		}
		arr := f(n / 2)
		for j := 0; j < len(arr); i, j = i+1, j+1 {
			res[i] = arr[j] * 2
		}
		return res
	}
	res := f(n)
	for i := 0; i < n; i++ {
		fmt.Fprintf(out, "%d ", res[i])
	}
}
