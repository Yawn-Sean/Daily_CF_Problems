package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
)

func main() { CF1151D(os.Stdin, os.Stdout) }

func CF1151D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	type pair struct{ a, b int }
	arr := make([]pair, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i].a, &arr[i].b)
	}
	sort.Slice(arr, func(i, j int) bool {
		return arr[i].a-arr[i].b > arr[j].a-arr[j].b
	})
	ans := 0
	for i := 0; i < n; i++ {
		ans += arr[i].a*i + arr[i].b*(n-i-1)
	}
	fmt.Fprintf(out, "%d", ans)
}
