# 🧠 Dynamic List in C (Python-style)

This project implements a dynamic array in C that mimics Python's `list` behavior. It supports the following operations:

- ✅ `append()` — Add elements to the end
- ❌ `remove()` — Remove the first occurrence of a value
- 🔍 `contains()` — Check if a value exists in the list
- 🔢 `count()` — Count occurrences of a value
- 🔎 `get()` — Access by index (supports negative indexing)
- 🍕 `slice()` — Get a sub-list from a range (like Python slicing)

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
Removes the first occurrence of a value and shifts the rest left.

### `List* slice(List *list, int start, int end)`
Creates a new list containing elements from index `start` to `end - 1`. Negative indices are supported.

### `void free_list(List *list)`
Frees all memory allocated to the list.

---

## 📦 Memory Management

- Uses `malloc` to create list and data buffers  
- Uses `calloc` to initialize zeroed memory on creation  
- Uses `realloc` to expand the list during `append`  
- `free_list()` should always be called to avoid memory leaks

---

## 🧪 Example Usage

```c
List *mylist = create_list();
append(mylist, 10);
append(mylist, 20);
append(mylist, 10);

printf("Contains 20? %d\n", contains(mylist, 20));
printf("Count of 10: %d\n", count(mylist, 10));
printf("Last element: %d\n", get(mylist, -1));

remove_item(mylist, 10);

List *sub = slice(mylist, 0, 2);
if (sub) {
    for (int i = 0; i < sub->size; i++) {
        printf("sub[%d] = %d\n", i, sub->data[i]);
    }
    free_list(sub);
}

free_list(mylist);
```
