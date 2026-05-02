# Food-Delivery-Operations-Dashboard-
# 🚀 Food Delivery Operations Dashboard

A console-based **Order Management System** built in C++ using core Data Structures implemented from scratch — no STL containers used.

---

## 📋 Table of Contents

- [About](#about)
- [Data Structures Used](#data-structures-used)
- [Features](#features)
- [Project Structure](#project-structure)
- [How to Run](#how-to-run)
- [What I Learned](#what-i-learned)
- [Preview](#preview)

---

## About

This project simulates a real-world food delivery backend system where an administrator can manage, process, sort, and track customer orders through a terminal-based dashboard.

---

## Data Structures Used

| Structure | Used For |
|-----------|----------|
| 🔗 **Linked List** | Main order storage |
| 📋 **Queue** | Order processing pipeline |
| 📚 **Stack** | Undo last action |
| 🔍 **Binary Search** | Fast order lookup by ID |

> Every data structure was implemented manually from scratch.

---

## Features

- ➕ Add / Remove orders
- 🔍 Search order by ID (Binary Search)
- 📊 Sort by Name, Price, or ID
- ⚡ Add orders to processing queue
- ✅ Process next order in queue
- ↩️ Undo last action (Add or Remove)
- 📈 Show order statistics (total revenue, avg price, order statuses)
- 💾 Auto save & load from file (`order.txt`)
- 🛡️ Input validation with attempt limits

---

## Project Structure

```
├── main.cpp                   # Entry point & menu logic
├── Order.h / .cpp             # Order class
├── Main_Storage.h / .cpp      # Linked List storage
├── Order_Processing.h / .cpp  # Queue for processing
├── Undo_Feature.h / .cpp      # Stack for undo
└── order.txt                  # Persistent data file
```

---

## How to Run

### Requirements
- C++17 or later
- Any C++ compiler (g++, MSVC, Clang)

### Compile & Run
```bash
g++ main.cpp Order.cpp Main_Storage.cpp Order_Processing.cpp Undo_Feature.cpp -o app
./app
```

---

## What I Learned

- Designing modular OOP systems in C++
- Implementing Data Structures manually without STL
- Exception handling with `try/catch` instead of `exit()`
- Clean resource management using destructors
- File persistence with save & load functionality

---

## Preview

```
====================================================
||       FOOD DELIVERY OPERATIONS DASHBOARD       ||
||         -- Internal Management v1.0 --         ||
====================================================
||      Administrator Access Granted... [OK]      ||
----------------------------------------------------
||         Logged in as: System Dispatcher        ||
|| Ready to process, sort, and manage daily orders||
====================================================
```

---

> Built with ❤️ using C++
