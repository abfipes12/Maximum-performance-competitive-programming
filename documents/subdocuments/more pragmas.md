
### Graphit

GCC has to be configured with --with-isl to enable the Graphite, that is often the case, Gentoo users may complain that this is "mech tier"

-graphite-identity  
-loop-nest-optimize // experimental

---

### safe Ofast

Ofast flags that are not about floats

-no-semantic-interposition  
-allow-store-data-races

---

### Rice

-gcse-sm  
-gcse-las

-tree-loop-im  
-tree-loop-ivcanon  
-ivopts  

-modulo-sched  
-modulo-sched-allow-regmoves

---

### Lto

Link-Time Optimizations

In competitive programming, we only have one source file,
LTO only makes sense when the standard library is statically linked (g++ -static or g++ -static-libstdc++)

-lto

// how often do you use virtual functions?  
-devirtualize-at-ltrans

---

### Pgo

Profile-guided optimization

I don't think this would be easy to achieve in competitive programming

-auto-profile

---

### Bonus

-trivial-auto-var-init=zero  

"Initialize automatic variables with zeroes.", this is not an optimization but you can write (int i; i < n; ++i) with i zero initialized by default.

---

### Conclusion

~~I personally use:~~  
```#pragma GCC optimize("Ofast,unroll-loops,ipa-pta,graphite-identity,loop-nest-optimize")```

and for programs that use floats

```#pragma GCC optimize("O3,no-semantic-interposition,loop-nest-optimize,unroll-loops,ipa-pta,graphite-identity,loop-nest-optimize")```

you are officially a ricer now
