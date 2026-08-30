# CS2040C Assignment 1 - Basic Linked List

TODO:
[] Test cases
[] Error handling
[] Insert at tail
[] Get tail

## Test Cases

This repository uses [GoogleTest](https://google.github.io/googletest/quickstart-cmake.html) for unit testing, run the commands below to test: 
```bash
cmake -S . -B build
cmake --build build
ctest --test-dir ./build
```

## Error Handling

An empty `std::vector` throws an out-of-bounds error when attempting to access or `pop_back()`.
