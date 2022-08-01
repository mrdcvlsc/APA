- [ ] - use packed radix

```c++
size_t add_packed_radix(uint64_t* output, uint64_t* add, size_t add_len) {
    uint64_t carry = 0;
    for(size_t i=0; i<add_len; ++i) {
        __uint128_t sum = (__uint128_t) output[i] + add[i] + carry;
        output[i] = sum;
        carry = sum >> 64;
    }
    output[add_len] += carry;
    return add_len + !!carry;
}
```