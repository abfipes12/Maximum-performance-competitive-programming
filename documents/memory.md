
### Custom allocators

TODO

---

### Access sequentially

```cpp
for (int i{}; i < n; ++i)
    for (int j{}; j < m; ++j)
        arr[i][j];
```

note that [-floop-interchange](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html#index-floop-interchange) is enabled by default at -O3

or even better

// pointer based approach and span/range approach

---
  
### Free memory is wasted memory

example

```cpp
int cnt[26];
for (char c : string)
    ++cnt2[c - 'a'];

int cnt2[256];
for (char c : string)
    ++cnt2[c];

// the compiler will probably be smart enough to 
&cnt_tmp = &cnt - 'a';
for (char c : string)
    ++cnt_tmp[c];
```

exmaple 2

unordered_map vs array or unordered_map, but with more .reserve()

TODO