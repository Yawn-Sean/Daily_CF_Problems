package main

import (
	"bufio"
	"fmt"
	"os"
	"slices"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	var n int
	fmt.Fscan(in, &n)
	arr := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &arr[i])
	}
	ans := int64(0)
	for len(arr) > 1 {
		slices.Sort(arr)
		temp := make([]int, 0, len(arr)/2)
		for i, j := 0, len(arr)-1; i < j; {
			ans += int64(arr[j] - arr[i])
			temp = append(temp, arr[j])
			i++
			j--
		}
		arr = temp
	}
	fmt.Fprintln(out, ans)
}
