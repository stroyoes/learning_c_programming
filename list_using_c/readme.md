Got it — you want me to **expand** and **modify** your documentation to also include these new functions:

- `concatenate`
- `filter`
- `length`
- `map`
- `reverse`

I'll keep your style (emoji sections, detailed explanations) and add these functions properly, updating the whole doc so it's neat and complete.

---

# 🧠 Dynamic List in C (Python-style)

This project implements a dynamic array in C that mimics Python's `list` behavior.  
It supports a wide range of operations to make working with dynamic arrays in C easier and more intuitive.

---

## ✅ Features

- `append()` — Add elements to the end
- `remove()` — Remove the first occurrence of a value
- `contains()` — Check if a value exists in the list
- `count()` — Count occurrences of a value
- `get()` — Access by index (supports negative indexing)
- `slice()` — Get a sub-list from a range (like Python slicing)
- `concatenate()` — Merge multiple lists into one
- `filter()` — Select elements matching a condition
- `length()` — Get the number of elements
- `map()` — Apply a function to all elements
- `reverse()` — Reverse the elements of a list

---

## ⚙️ Functions

### `List* create_list()`
Creates and initializes a new dynamic list using `malloc` and `calloc`.

### `void append(List *list, int value)`
Adds a value to the end of the list, resizing with `realloc` if needed.

### `int get(List *list, int index)`
Returns the element at a given index. Negative indices are allowed.

### `int contains(List *list, int value)`
Returns `1` if the value exists in the list, else `0`.

### `int count(List *list, int value)`
Returns how many times a value appears in the list.

### `void remove_item(List *list, int value)`
Removes the first occurrence of a value and shifts the remaining elements left.

### `List* slice(List *list, int start, int end)`
Creates a new list containing elements from index `start` to `end - 1`.  
Negative indices are supported for flexible slicing.

### `void free_list(List *list)`
Frees all memory allocated to the list.

---

## ➕ Advanced Functions

### `List* concatenate(int num_lists, List **lists)`
Combines multiple lists into a single new list, preserving the order of elements.

| Parameter | Description |
|:---|:---|
| `num_lists` | Number of lists to merge |
| `lists` | Array of pointers to `List` |

### `List* filter(List *list, int (*predicate)(int))`
Creates a new list containing only elements for which `predicate(element)` returns `true`.

| Parameter | Description |
|:---|:---|
| `list` | The source list |
| `predicate` | A function pointer that returns `1` if the item should be included |

### `int length(List *list)`
Returns the total number of elements in the list.

### `List* map(List *list, int (*func)(int))`
Applies a function to each element of the list and returns a new list of the results.

| Parameter | Description |
|:---|:---|
| `list` | The source list |
| `func` | A function pointer that modifies each item |

### `List* reverse(List *list)`
Creates a new list with all the original elements but in reversed order.

---

## 📦 Memory Management

- Uses `malloc` to create list structures and buffers
- Uses `calloc` to initialize memory when creating new lists
- Uses `realloc` for dynamic resizing during `append()`
- `free_list()` must be called on any list created to avoid memory leaks
- All functions that return a new `List*` allocate fresh memory (caller must `free_list()` after use)

---

## 🧪 Example Usage

```c
List *mylist = create_list();
append(mylist, 10);
append(mylist, 20);
append(mylist, 30);

printf("Length: %d\n", length(mylist));

List *reversed = reverse(mylist);
for (int i = 0; i < reversed->size; i++) {
    printf("reversed[%d] = %d\n", i, reversed->data[i]);
}
free_list(reversed);

int is_even(int x) { return x % 2 == 0; }
List *even_list = filter(mylist, is_even);
for (int i = 0; i < even_list->size; i++) {
    printf("even_list[%d] = %d\n", i, even_list->data[i]);
}
free_list(even_list);

free_list(mylist);
```

---

## ✨ TODO (Future Enhancements)

- Add support for generic types (using `void*` instead of `int`)
- Implement iterator-like behavior for easier list traversals

