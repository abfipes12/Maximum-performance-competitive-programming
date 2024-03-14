
### Sorting

#### Counting sort

You probably know how it works. Radix sort uses count sort as a subroutine.

#### Radix sort

a non-comparative sorting algorithm that sorts data with integer keys by grouping the keys by individual digits that share the same significant position and value. It processes from the least significant digit to the most significant digit.

with complexity O(n) and "large constant"

```cpp
// eyes warning
void radixsort(span<int> arr)
{
    int cnt[32768]{};
    static int t[max_n];
    auto tmp = span(t, t + arr.size());
    fill(cnt, cnt + 32768, 0);
    for (int e : arr)
        ++cnt[e & 0x7FFF];

    partial_sum(cnt, cnt + 32768, cnt);
    for (int e : ranges::reverse_view(arr))
        t[--cnt[e & 0x7FFF]] = e;

    fill(cnt, cnt + 32768, 0);
    for (int e : tmp)
        ++cnt[e >> 15];

    partial_sum(cnt, cnt + 32768, cnt);
    for (int e : ranges::reverse_view(tmp))
        arr[--cnt[e >> 15]] = e;
}
```

For small arrays it is better to use std::sort. TODO how small.

[more code](../templates%20and%20examples/radixsort.cpp)

---

### Hashing

TODO

---

### Online vs Offline

TODO

