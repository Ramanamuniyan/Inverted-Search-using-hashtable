# 🧠 Inverted Search using Hashtable

## 📘 Overview
**Inverted Search using Hashtable** is a C-based data structure project designed to create an **inverted index** from multiple text files.  
It maps each word to the list of files in which it appears, allowing users to quickly search and retrieve file references for any given word.  
This project demonstrates the efficient use of **hash tables**, **linked lists**, and **file handling** in C.

---

## 🎯 Objective
The main goal of this project is to:
- Index multiple text files efficiently.
- Store and manage words using hash-based indexing.
- Enable fast searching of words across files.
- Practice and demonstrate strong understanding of pointers, dynamic memory allocation, and data structure design in C.

---

## ⚙️ Features
✅ **Multi-file Support** – Reads and indexes multiple files at once.  
✅ **Fast Lookup** – Uses a hash table for O(1) average word lookup time.  
✅ **Duplicate Handling** – Tracks word occurrences across multiple files.  
✅ **Linked List Chaining** – Handles hash collisions efficiently.  
✅ **Case-Insensitive Search** – Ensures uniform indexing and searching.  
✅ **Memory-Safe Design** – Includes dynamic allocation and clean deallocation.  
✅ **User-Friendly Output** – Displays results in a well-formatted table view.  

---

## 🧩 Data Structures Used
| Structure | Purpose |
|------------|----------|
| `hash_t` | Represents a hash table bucket. |
| `main_t` | Holds a word and its linked list of file references. |
| `sub_t` | Represents each file node containing filename and word count. |

### **Hash Table Design**
- The hash table has fixed-size buckets (e.g., 27 or 28 for A–Z and other characters).  
- Each bucket contains a linked list of words starting with that alphabet.

---

## 🧮 Workflow

1. **File Input Phase**
   - User provides multiple text files.
   - The program reads each file and extracts words.

2. **Index Creation**
   - Each word is converted to lowercase and inserted into the hash table.
   - The hash index is calculated using the first character of the word.
   - If the word already exists, the corresponding file node is updated.

3. **Display Phase**
   - After building the inverted index, users can view:
     - Index position  
     - Word  
     - File count  
     - File names  
     - Word frequency per file

---

## 🧾 Example Output
```
[Index] [Word] [FileCount] [Filenames] [WordCount]
[10]    hello      2        file1.txt, file2.txt    5
[14]    world      1        file1.txt               3
[25]    search     3        file1.txt, file3.txt    7
```

---

## 🧠 Hashing Logic
- Hash value is calculated based on the first character of each word:
  ```c
  int index = tolower(word[0]) % 97; // For 'a' -> 0, 'b' -> 1, etc.
  ```
- Non-alphabetic characters are mapped to a special index (e.g., 26 or 27).

---

## 🧹 Memory Management
- Every dynamically allocated node (main and sub) is freed at program exit.
- Functions like `free_main()` and `free_sub()` ensure recursive cleanup.

---

## 📂 Project Structure
```
Inverted-Search-using-Hashtable/
├── main.c
├── hash.h
├── create.c
├── display.c
├── search.c
├── update.c
├── delete.c
├── free.c
├── Makefile
└── README.md
```

---

## 🧰 Compilation and Execution

### **Build using Makefile**
```bash
make
```

### **Run the program**
```bash
./inverted_search file1.txt file2.txt file3.txt
```

### **Clean build files**
```bash
make clean
```

---

## 📋 Sample Functions

### `create_main(char *word, char *filename)`
Creates a new main node (word node) for the hash table.

### `create_sub(char *filename)`
Creates a sub-node for a given filename and links it to the word.

### `insert_to_hash_table()`
Inserts words into the appropriate hash index based on their first character.

### `display_database()`
Prints all indexed words, files, and frequencies.

### `search_word()`
Allows the user to search for any word across indexed files.

---

## 🧩 Example Flow Diagram

```
          ┌─────────────┐
          │  Input Files│
          └──────┬──────┘
                 │
                 ▼
        ┌──────────────────┐
        │ Tokenize Words    │
        └──────┬───────────┘
                 │
                 ▼
        ┌──────────────────┐
        │ Hash Function     │
        └──────┬───────────┘
                 │
                 ▼
        ┌──────────────────┐
        │ Store in Hashtable│
        └──────┬───────────┘
                 │
                 ▼
        ┌──────────────────┐
        │ Display / Search  │
        └──────────────────┘
```

---

## 🧑‍💻 Example Usage
```bash
./inverted_search notes.txt data.txt report.txt
```

**Sample Interaction:**
```
Enter choice:
1. Create database
2. Display database
3. Search word
4. Save database
5. Exit
```

---

## 📈 Future Enhancements
- [ ] Add file change detection to auto-update index  
- [ ] Export database to JSON or XML format  
- [ ] Implement partial-word and phrase search  
- [ ] Add user interface with command history  
- [ ] Integrate stop-word removal (ignore common words like "the", "and")  

---

## 🤝 Contributors
- **Ramana Muniyan** – Developer & Maintainer  

---


---

## 💬 Feedback
If you find any bugs or have feature suggestions, feel free to open an issue or contribute via pull request.

📍 **GitHub Repository:**  
[https://github.com/Ramanamuniyan/Inverted-Search-using-hashtable](https://github.com/Ramanamuniyan/Inverted-Search-using-hashtable)

---

⭐ If you found this project useful, please consider giving it a **star** on GitHub!
