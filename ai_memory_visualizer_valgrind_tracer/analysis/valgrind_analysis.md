
# Valgrind Analysis

## 1. Heap Example

Command used:

valgrind --leak-check=full --show-leak-kinds=all ./heap_example

### Valgrind Result

Valgrind found a memory leak.

6 bytes in 1 block are definitely lost.

The memory was allocated in person_new
at line 21.

### Explanation

The program creates Alice and Bob.

Each person has a name stored on the heap.

For Bob, the program frees the name
and the Person structure.

For Alice, person_free_partial only
frees the Person structure.

Alice's name is not freed.

This causes a memory leak of 6 bytes.

The name "Alice" needs 6 bytes,
including the '\0' character.

## 2. Aliasing Example

Command used:

valgrind --leak-check=full --show-leak-kinds=all ./aliasing_example

### Before free

a and b point to the same array.

STACK                  HEAP

a --------+
          +----------> [0, 11, 22, 33, 44]
b --------+

The array uses 20 bytes.

### After free

free(a) releases the array.

Both pointers still contain the old address.

The memory is no longer valid.

### Error 1 - Invalid Read

Line 42: b[2]

The program reads memory after free(a).

This is a use-after-free.

### Error 2 - Invalid Write

Line 44: b[3] = 1234

The program writes to freed memory.

This is also a use-after-free.

### Error 3 - Invalid Read

Line 45: b[3]

The program reads the freed memory again.

This is another use-after-free.

### Memory Leaks

Valgrind reports 0 bytes in use at exit.

There are no memory leaks in this example.

But there are 3 invalid memory accesses.

## 3. AI Critical Review

The AI explanation said:

"After free(a), b becomes NULL."

This explanation is incorrect.

free(a) releases the memory but does
not automatically set b to NULL.

The pointer b still contains the old
address.

It is now a dangling pointer.

Reading or writing through b is
undefined behavior.

The correct explanation is that
the memory is freed, but b still
contains an invalid address for access.

## 4. Conclusion

Valgrind helped me find memory errors.

In heap_example, Alice's name is not freed.

In aliasing_example, the program accesses
memory after free.

I learned that a memory leak and a
use-after-free are different errors.

