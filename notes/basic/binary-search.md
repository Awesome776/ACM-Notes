# 二分查找

## 概述

二分查找的核心思想：在**单调序列**上，每次将搜索范围缩小一半，从而在 O(log n) 时间内定位目标。竞赛中二分常用于「最大化最小值」「最小化最大值」等答案二分场景。

## 整数二分模板

### 模板一：找第一个 >= x 的位置（lower_bound）

```cpp
int lower_bound(int a[], int n, int x) {
    int lo = 0, hi = n;  // 注意 hi = n，不是 n-1
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    return lo;  // lo == hi，若 == n 则所有元素 < x
}
```

### 模板二：找第一个 > x 的位置（upper_bound）

```cpp
int upper_bound(int a[], int n, int x) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (a[mid] <= x) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}
```

## 答案二分

将答案作为二分对象，验证 mid 是否可行：

```cpp
// 模型：求满足条件的最小值
// check(mid) 为 true 时答案在 [lo, mid]，否则在 (mid, hi]
bool check(int mid);

int binary_answer() {
    int lo = MIN, hi = MAX;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}
```

## 浮点二分

求浮点答案时，控制精度或固定迭代次数：

```cpp
double lo = 0, hi = 1e9;
for (int i = 0; i < 100; i++) {  // 迭代100次，精度足够
    double mid = (lo + hi) / 2;
    if (check(mid)) hi = mid;
    else lo = mid;
}
// 答案为 lo（或 hi，此时 lo ≈ hi）
```

## STL 用法

```cpp
// 在有序数组中查找
int pos = lower_bound(a, a + n, x) - a;  // 第一个 >= x 的下标

// 在 vector 中
int pos = lower_bound(v.begin(), v.end(), x) - v.begin();

// 二分查找是否存在
bool found = binary_search(a, a + n, x);
```

## 常见应用

| 场景 | 说明 |
|------|------|
| 最大值最小化 | 二分答案 + 贪心验证 |
| 分数规划 | 二分比率 + 验证 |
| 求第 k 小 | 配合划分 |
| 求方程根 | 浮点二分 |

## 注意事项

1. **死循环陷阱**：整数二分时 `mid = (lo + hi + 1) / 2` 和 `mid = (lo + hi) / 2` 的选择取决于更新方式，否则可能死循环
2. **边界处理**：`lo` 和 `hi` 的初始值要覆盖所有可能答案
3. **单调性**：确保二分的对象（序列或答案）具有单调性
