#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    vector<pair<int, int>> tasks;
    vector<vector<int>> ans;
    tasks.emplace_back(1, n);
    
    while (tasks[0].second != tasks[0].first) {
        ans.emplace_back(vector<int>());
        vector<pair<int, int>> new_tasks;
        for (const auto task: tasks)
            if (task.first != task.second) {
                int mid = (task.first + task.second) / 2;
                new_tasks.emplace_back(task.first, mid);
                new_tasks.emplace_back(mid + 1, task.second);
                for (int i = task.first; i <= mid; ++i)
                    ans[ans.size() - 1].push_back(i);
            }
        tasks = new_tasks;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i].size());
        for (const auto x : ans[i])
            printf(" %d", x);
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}