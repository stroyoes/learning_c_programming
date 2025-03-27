# Book Database Project

## Overview
This project is a simple book database that allows users to store book information, print it in a structured format, and sort the books by publication year. The project consists of C source files, a build script, and an uninstall script.

## Files and Structure

```
📂 Project Folder
├── build.sh         # Script to compile the project
├── uninstall.sh     # Script to remove the build files
├── main.c           # Main program logic
├── book_db.c        # Functions for book storage, sorting, and printing
├── book_db.h        # Header file with struct definitions
```

## Compilation and Execution

### Building the Project
To compile the project, run the `build.sh` script:

```sh
./build.sh
```

If successful, the compiled executable will be found in the `build/` directory under the name `book_db`.

### Running the Program
After building, execute the program using:

```sh
./build/book_db -n <number_of_books> [-add <Title> <Author> <Price> <Day> <Month> <Year>]...
```

Example:
```sh
./build/book_db -n 2 -add "Book A" "Author A" 9.99 01 01 2000 -add "Book B" "Author B" 19.99 15 06 2010
```

### Uninstalling (Cleaning Build Files)
To remove the compiled files and `build/` directory, run:

```sh
./uninstall.sh
```

## Code Overview

### main.c
- Parses command-line arguments to add books.
- Uses `str_to_intX()` for safe string-to-integer conversion.
- Calls `fill_book()` to store book details.
- Calls `print_book()` to display books.
- Calls `sort_by_year()` to sort books before displaying them again.

### book_db.c
- `print_book()`: Prints books in a tabular format.
- `sort_by_year()`: Sorts books in descending order by year.
- `fill_book()`: Stores book details and validates input.

### book_db.h
- Defines structs:
  - `date_t`: Stores publication date.
  - `book_t`: Stores book details.
  - `intX_t`: Union for flexible integer storage.
- Declares functions for printing, sorting, and adding books.

## Notes
- The program supports up to 100 books (`MAX_BOOKS`).
- Book titles and author names are limited to 100 characters.
- Sorting is done using a basic **bubble sort**.

## Future Improvements
- Implement a better sorting algorithm (e.g., quicksort or mergesort).
- Store books in a file instead of memory.
- Add search functionality.

---
Project created as a simple book database system in C.
