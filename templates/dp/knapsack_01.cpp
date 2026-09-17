/*
 * 01 背包
 * Time: O(nW)  Space: O(W)
 *
 * 功能：每个物品最多取一次，求容量 W 下最大价值
 *
 * 关键步骤：
 *   - 倒序遍历 j（保证每个物品只取一次）
 *   - dp[j] = max(dp[j], dp[j-w] + v)
 *
 * 完全背包：将 j 的遍历改为正序即可
 * 编译：g++ -std=c++17 -O2 -o knapsack_01 knapsack_01.cpp
 */

#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1010, MAXW = 10010;

int n, W;
int w[MAXN], v[MAXN];
int dp[MAXW];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> W;
    for (int i = 1; i <= n; i++) cin >> w[i] >> v[i];

    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)  // 倒序
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);

    cout << dp[W] << "\n";
    return 0;
}
