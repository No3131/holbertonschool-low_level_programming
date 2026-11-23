# Memory Maps Analysis

## 1. Stack Example

The program uses recursion.

main calls walk_stack(0, 3).

Each call has its own local variables.

### Step 1 - First Call

walk_stack(0, 3)

STACK:

main
walk_stack(0)
    depth = 0
    marker = 0

### Step 2 - Recursive Calls

The function calls itself until depth is 3.

STACK:

walk_stack(3) -> marker = 30
walk_stack(2) -> marker = 20
walk_stack(1) -> marker = 10
walk_stack(0) -> marker = 0
main

Each marker is a different variable.

The previous calls are still active.

### Step 3 - dump_frame

dump_frame creates local variables:

- local_int
- local_buf
- p_local

p_local points to local_int.

STACK:

dump_frame
    local_int = 100 + depth
    local_buf = char array
    p_local ----> local_int

These variables are only valid
while dump_frame is running.

### Step 4 - Function Return

When dump_frame returns, its local
variables are no longer valid.

When walk_stack(3) returns, its local
variables are no longer valid.

Then walk_stack(2), walk_stack(1)
and walk_stack(0) return.

The stack frames end one by one.

No heap memory is allocated
in this example.

## 2. Aliasing Example

### Step 1 - Allocation

make_numbers uses malloc to create
an array of 5 integers.

Each integer uses 4 bytes on my system.

The array uses 20 bytes.

HEAP:

[0, 11, 22, 33, 44]

### Step 2 - Pointer Aliasing

The program executes:

b = a;

STACK                 HEAP

a --------+
          +---------> [0, 11, 22, 33, 44]
b --------+

Both pointers contain the same address.

There is only one array.

### Step 3 - Free

The program executes:

free(a);

The heap array is freed.

a and b still contain the old address.

Both pointers are now dangling pointers.

The array is no longer valid.

### Step 4 - Invalid Access

The program reads b[2].

It also writes to b[3].

These operations access freed memory.

This is called use-after-free.

The behavior is undefined.

## 3. AI Critical Review

I used AI to help explain the memory maps.

The AI first gave a very short explanation:

"The stack stores local variables.
Each recursive call has its own variables."

This explanation was correct but incomplete.

It did not show the different stack frames.

It also did not explain when each frame ends.

I corrected the explanation by showing
the four recursive calls separately.

Each call has its own marker variable.

The variables stop being valid
when their function call returns.

## 4. Conclusion

The stack is used for local variables
and function calls.

The heap is used for dynamic allocations.

Two pointers can point to the same memory.

After free, the allocated memory
must not be accessed again.
