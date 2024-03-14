
### Segmented vs Fenwick tree

Segment trees and Fenwick trees (also known as binary indexed trees or BITs) are data structures used for range queries and updates.

#### Advantages of SegTree:
- Segmented trees are very flexible and can be applied to a wide range of problems.

#### Advantages of Fenwick:
- Fenwick trees are easier to code and understand than segment trees once you understand the basic principle.
- Uses less memory compared to segment trees.

Fenwick Trees are about ??? faster than SegTrees

[Code for everything Fenwick](../templates%20and%20examples/fenwick.cpp)

#### 0 vs. 1 indexed Fenwick Trees 

TODO

#### Min/max queries using BIT vs. SegTree

TODO

#### Range Updates and Range Queries in Log(n)

TODO

---

### Priority queue vs map/set

TODO

---

### Disjoint union set rank vs size

TODO

---


### Policy based data structures

TODO

---

### Stack vs vector

TODO

---

### Hahstables

Some users use custom hashtables in their solutions

TODO

---

### Queue

TODO

```cpp
T que[max_n];
T *iq = &que;
T *eq = &que;

// emplacing
*eq++ = var;

// traversing
while (iq != eq)
{
    auto var = *iq++;
}
```