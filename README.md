# LRU Cache Implementation in C++

## Overview
This project implements an **LRU (Least Recently Used) Cache** using **doubly linked list** and **hash map (std::map)** in C++. It efficiently manages cache storage with a fixed capacity, ensuring that the least recently accessed items are removed when the cache is full.

## Features
- Implements **get()** and **put()** operations with an average time complexity of **O(1)**.
- Uses a **doubly linked list** to maintain the order of recently used items.
- Utilizes a **hash map (std::map)** to provide fast lookups for cache keys.
- Automatically removes the **least recently used (LRU) entry** when the cache reaches its capacity.
- Supports **interactive user input** for inserting, retrieving, and displaying cache contents.

## Data Structures Used
1. **Doubly Linked List**
   - Stores cache entries.
   - Enables efficient insertion and deletion of nodes.
   - Maintains the order of access to determine the LRU item.

2. **Hash Map (std::map)**
   - Stores key-node pairs for **O(1) lookups**.
   - Facilitates fast access and update of cache entries.

## How It Works
- **Insertion (`put(key, value)`)**
  - If the key exists, update the value and move the node to the front.
  - If the key is new and the cache is full, remove the **LRU node** (i.e., `tail->prev`) and insert the new node at the head.

- **Retrieval (`get(key)`)**
  - If the key is found, move the corresponding node to the front (most recently used position) and return the value.
  - If the key does not exist, return `-1`.

- **Cache Printing (`printCache()`)**
  - Displays the key-value pairs currently stored in the cache, in order of recent use.

## Sample Input/Output
```
1) Insert a value
2) Get a value
3) Print the cache
Enter your choice: 1
Enter the key and value: 1 10
Enter your choice: 1
Enter the key and value: 2 20
Enter your choice: 1
Enter the key and value: 3 30
Enter your choice: 1
Enter the key and value: 4 40
Enter your choice: 3
Cache contents:
2 -> 20
3 -> 30
4 -> 40
```

## Future Improvements
- Use **unordered_map** instead of `std::map` to improve performance.
- Implement a **thread-safe version** using mutex locks for concurrent use.
- Extend the cache to support **dynamic capacity adjustment**.
---
Let me know if you need any modifications! 🚀

