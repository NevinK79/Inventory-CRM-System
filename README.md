# Inventory & CRM System

A command-driven inventory and customer relationship management (CRM) system written in C++, built for a hypothetical small business, **The Green Dragon Game House and Inn**.

The program reads a sequence of text commands from an input file, processes each one, and maintains an in-memory database of store inventory and customer purchase history.

## Overview

The system tracks:

- **Store inventory** across four item types: Books, Dice, Figures, and Towers
- **Customer records**, including each customer's name and cumulative purchases per item type

Commands are read from a plain-text input file, parsed, and executed one at a time until a `Quit` command is reached.

## Features

- Add new inventory shipments
- Record customer purchases, automatically creating new customer records as needed
- Process customer returns, with inventory and purchase counts updated accordingly
- Print a full store summary: current inventory levels, total distinct customers, and top purchaser per item type
- Graceful handling of invalid operations (insufficient inventory, unknown customers, over-returns, non-positive purchase amounts)
- Clean memory management with no leaks (verified via Valgrind)

## Data Model

```c
typedef struct Customer {
  String name;
  int books;
  int dice;
  int figures;
  int towers;
} Customer;
```

Customer names are case-sensitive — `"Dan"` and `"dan"` are treated as different customers.

Item quantities and customer records are stored using a custom `String` abstract data type (`MyString.h` / `MyString.cpp`), rather than raw C-strings.

## Commands

| Command | Format | Description |
|---|---|---|
| `Inventory` | `Inventory <type> <#>` | Adds `<#>` units of `<type>` to store inventory |
| `Purchase` | `Purchase <name> <type> <#>` | Records a purchase; creates a new customer if needed and decreases inventory |
| `Return` | `Return <name> <type> <#>` | Records a return; increases inventory and decreases the customer's purchase count |
| `Summarize` | `Summarize` | Prints current inventory, total customer count, and top purchaser per item |
| `Quit` | `Quit` | Ends command processing |

### Example

```
Inventory Books 4
Purchase Sue Books 1
Purchase Dan Books 2
Summarize
Purchase Sue Books 1
Summarize
Quit
```

### Error Handling

- **Purchase exceeds inventory:**
  ```
  Sorry <name>, we only have <#> <type>
  ```
  (No inventory or customer record is updated.)

- **Return from an unknown customer:**
  ```
  Sorry <name>, we do not have you in our database
  ```

- **Return exceeds what a customer has purchased:**
  ```
  <name>, you do not have <#> <type>
  ```

- **Purchases of zero or negative items** are silently ignored (no output).

- **Ties for most purchases of an item** are broken in favor of whichever customer was added to the database first.

### Sample Summary Output

```
There are 96 Books 80 Dice 50 Figures and 100 Towers in inventory
we have had a total of 1 different customers
Craig has purchased the most Books (4)
Craig has purchased the most Dice (120)
no one has purchased any Figures
no one has purchased any Towers
```

## Project Structure

| File | Description |
|---|---|
| `Project4.cpp` | Core inventory/CRM logic — command handlers and helper functions |
| `Invent.h` | Struct and function declarations |
| `MyString.h` / `MyString.cpp` | String ADT used throughout the program |
| `main.cpp` | Input file parsing and program driver |
| `test1.txt` – `test4.txt` | Sample input files with expected output |

## Building

Compile all `.cpp` files together, for example:

```bash
g++ -o inventory main.cpp Project4.cpp MyString.cpp
./inventory < test1.txt
```

(Adjust the compile command as needed for your environment/IDE.)

## Memory Management

All dynamically allocated `String`s (e.g., customer names, values returned by `readString`) are properly destroyed when no longer needed, including during a full state `reset()`. No memory leaks — verified with:

```bash
valgrind ./inventory
```

## Notes on I/O

- `readString(&in)` reads the next whitespace-delimited word from the input file into a `String`.
- `readNum(&in2)` reads and converts the next number from the input file.
- Strings returned by `readString` are **not** null-terminated — use `StringPrint` (not `printf`) to print them correctly, relying on the string's `len` field.
