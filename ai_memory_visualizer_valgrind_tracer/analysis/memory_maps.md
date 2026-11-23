# Memory Maps Analysis

## Stack Example

The stack stores local variables.

Each recursive call has its own variables.

When a function returns, its local
variables are no longer valid.

## Aliasing Example

Two pointers can point to the same memory.

After free, the allocated memory is no longer valid.

Using a pointer to access freed memory
is a use-after-free.
