
### ++i vs. i++

 - ++i; increments the value, then returns it.
 - i++; returns the value, and then increments it.

```
int i = 1;  
int j = i++;  
(i is 2, j is 1)
```

"i++ could potentially be slower than ++i, since the old value of i might need to be saved for later use"

In practice compilers are smart enought to rearange instructions to avoid temprorary copies, but ++i often expresses intentions better.

### a /= 2 vs. a >>= 1

compiler cannot optimise first into second because this will produce differend results for negative values.

for unsigned compiler can optimise, but using unsigned [may be not ideal either.](types.md)

---

### Division and modulo by Compile-time constant

The idea is that we can turn division into multiplication by the inverse (Reciprocal Multiplication).

[blog explaining how it works](https://ridiculousfish.com/blog/posts/labor-of-division-episode-i.html)

division and modulo by compile-time constant are not that slow because it is multiplication and some other fast instructions.

---

### Division and modulo

If we work with numbers smaller than mod

```cpp 
// about ??? times faster
if (a > mod)
    a -= mod; 
```

also outsmarting g++ isn't that smart

```cpp
// about ??? times SLOWER (link)
if (a > mod)
    a % mod;
```

---

### __buildin instructions

Be sure to have pragmas targeting popcnt-alike instructions.

__buildin_popcnt();

__buildin_ etc..

TODO

---

### std::move()

TODO