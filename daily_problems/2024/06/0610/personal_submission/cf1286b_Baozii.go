package main
 
import (
	"fmt"
	"os"
)
 
func main() {
	var n int
	fmt.Scan(&n)
 
	g := make([][]int, n+1)
	c := make([]int, n+1)
	a := make([]int, n+1)
 
	for i := 1; i <= n; i++ {
		var fa int
		fmt.Scan(&fa, &c[i])
		g[fa] = append(g[fa], i)
	}
 
	var dfs func(int) []int
	dfs = func(x int) []int {
		res := []int{}
		for _, v := range g[x] {
			res = append(res, dfs(v)...)
		}
		if len(res) < c[x] {
			fmt.Println("NO")
			os.Exit(0)
		}
		res = append(res[:c[x]], append([]int{x}, res[c[x]:]...)...)
		return res
	}
 
	vec := dfs(g[0][0])
	for i := 0; i < n; i++ {
		a[vec[i]] = i + 1
	}
	fmt.Println("YES")
	for i := 1; i <= n; i++ {
		fmt.Printf("%d ", a[i])
	}
}
