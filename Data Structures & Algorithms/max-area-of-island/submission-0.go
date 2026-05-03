func dfs(grid [][]int, i int, j int, m int, n int) int {
    if(i<0 || j<0 || i>=m || j>=n || (grid)[i][j]!=1) {
        return 0
    }
    (grid)[i][j] = 2
    return 1 + dfs(grid, i+1, j, m, n) + dfs(grid, i-1, j, m, n) + dfs(grid, i, j+1, m, n) + dfs(grid, i, j-1, m, n)
}

func maxAreaOfIsland(grid [][]int) int {
    m := len(grid)
    n := len(grid[0])
    mx := 0

    for i:=0; i < m; i++ {
        for j:=0; j<n; j++ {
            if grid[i][j] == 1 {
                c := dfs(grid, i, j, m, n)
                mx = max(mx, c)
            }
        }
    }

    return mx;
}