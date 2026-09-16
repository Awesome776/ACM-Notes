# 排序算法

## 概述

排序是竞赛中最基础也最常用的算法之一。实际竞赛中**绝大多数情况直接使用 `std::sort`**，但理解各排序算法的原理对解决特定问题（如求逆序对）至关重要。

## 常见排序算法对比

| 算法 | 平均时间 | 最坏时间 | 空间 | 稳定性 |
|------|---------|---------|------|--------|
| 冒泡排序 | O(n²) | O(n²) | O(1) | 稳定 |
| 选择排序 | O(n²) | O(n²) | O(1) | 不稳定 |
| 插入排序 | O(n²) | O(n²) | O(1) | 稳定 |
| 快速排序 | O(n log n) | O(n²) | O(log n) | 不稳定 |
| 归并排序 | O(n log n) | O(n log n) | O(n) | 稳定 |
| 堆排序 | O(n log n) | O(n log n) | O(1) | 不稳定 |

## STL 排序

竞赛中最常用的排序方式：

```cpp
// 数组排序（升序）
int a[n];
std::sort(a, a + n);

// 数组排序（降序）
std::sort(a, a + n, std::greater<int>());

// vector 排序
std::vector<int> v;
std::sort(v.begin(), v.end());

// 自定义比较函数
struct Node { int x, y; };
bool cmp(const Node &a, const Node &b) {
    if (a.x != b.x) return a.x < b.x;  // x 升序
    return a.y > b.y;                   // x 相同时 y 降序
}
std::sort(v.begin(), v.end(), cmp);
```

## 逆序对（归并排序应用）

求序列中逆序对的数量是归并排序的经典应用：

```cpp
long long merge_sort(int a[], int l, int r) {
    if (l >= r) return 0;
    int mid = (l + r) / 2;
    long long cnt = merge_sort(a, l, mid) + merge_sort(a, mid + 1, r);
    int temp[r - l + 1];
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else { temp[k++] = a[j++]; cnt += mid - i + 1; }
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= r) temp[k++] = a[j++];
    for (i = l, k = 0; i <= r; i++, k++) a[i] = temp[k];
    return cnt;
}
```

## 典型例题

- **逆序对**：[洛谷 P1908](https://www.luogu.com.cn/problem/P1908)
- **不重复排序去重**：使用 `sort` + `unique` + `erase`

## 总结

| 场景 | 推荐方法 |
|------|---------|
| 普通排序 | `std::sort` |
| 需要稳定性 | `std::stable_sort` |
| 部分排序 | `std::partial_sort` |
| 求逆序对 | 归并排序 / 树状数组 |
| 第 k 大 | `std::nth_element` |
