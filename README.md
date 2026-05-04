# 📚 Sistema de Biblioteca em C

A simple command-line **Library Management System** written in C, built using dynamic memory allocation and structured data types. This project allows users to add books, list available titles, and register loans — all through an interactive terminal menu.

---

## Features

- ➕ Add books (title, author, edition)
- 📋 List all books in the library
- 🤝 Register book loans to named users
- 📌 List currently borrowed books
- 🧹 Proper dynamic memory management with `malloc`/`calloc` and `free`

---

## 🗂️ Project Structure

```
.
├── main.c          # Entry point — menu loop and program flow
├── biblioteca.c    # Core library functions (add, list, loan, free)
└── biblioteca.h    # Header file — structs, constants, and prototypes
```

---

## ⚙️ How to Build & Run

### Prerequisites
- A C compiler (e.g. `gcc`)

### Compile

```bash
gcc main.c biblioteca.c -o biblioteca
```

### Run

```bash
./biblioteca
```

---

## 📝 Notes

- This project uses **dynamic memory allocation** (`calloc` for books, `malloc` for loans).
- Input is handled via `scanf` with a buffer-clearing utility (`limparBuffer`) to prevent input issues.
- The project is written in **Portuguese** but is straightforward to follow.

---
