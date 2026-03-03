# Simple Persistent Key-Value Store

A lightweight, command-line key‑value database written in modern C++ (C++20). It supports basic CRUD operations (`set`, `get`, `delete`, `rename`), persistence to a file, and several utility commands — all from the terminal.

Built as a learning project with a clean CMake build system and simple persistent storage.

## Features

- **Set** / **Get** / **Delete** / **Rename** key-value pairs
- Short aliases: `s`, `g`, `d`, `rn`
- Persistent storage — data saved to `store.txt` (survives program restart)
- Input validation (no empty keys, no spaces in keys)
- Auto-trim leading/trailing spaces
- Commands: `list`, `count`, `clear`, `save`, `help`, `quit`
- Case-insensitive commands
- Built with CMake — easy to build & run

## Build & Run

### Prerequisites

- C++20-capable compiler (GCC 11+, Clang 13+, MSVC 2019+)
- CMake 3.20+
- Git (optional)

### Steps

```bash
# 1. Clone or download the repository (or skip if you already have the source)
git clone https://github.com/yourusername/key-value-store.git
cd key-value-store

# 2. Create build directory and enter it
mkdir build && cd build

# 3. Configure the project (generates build files)
cmake ..

## 4. Build
cmake --build .   # or just make (Linux/macOS) / open .sln (Windows)

## 5. Run
./kvstore         # Linux/macOS
## or
kvstore.exe       # Windows
```
If using VS Code + CMake Tools:

1. Open the project folder in VS Code
2. Press Ctrl+Shift+P → `CMake: Configure`
3. Press Ctrl+Shift+P → `CMake: Build` (or click the hammer icon)
4. Run from the integrated terminal: `./kvstore` (Linux/macOS) or `kvstore.exe` (Windows)

The program automatically creates/uses `store.txt` in the same folder.

## Commands

| Command | Alias | Description | Example |
|---|---:|---|---|
| `set <key> <value>` | `s` | Store key-value pair | `set name Preet` |
| `get <key>` | `g` | Retrieve value | `get name` |
| `delete <key>` | `d` | Remove key | `delete city` |
| `rename <old_key> <new_key>` | `rn` | Change key name | `rename name full_name` |
| `list` | `l` | Show all stored pairs | `list` |
| `count` | — | Show number of keys | `count` |
| `clear` | — | Delete all entries | `clear` |
| `save` | — | Manually save to file | `save` |
| `help` | `h` | Show this help | `help` |
| `quit` | `q` | Exit (auto-saves) | `quit` |

## Notes

- Keys cannot contain spaces or be empty.
- Values can contain spaces.
- Data is saved automatically on quit (or manually with `save`).
- `store.txt` is plain text (one `key:value` pair per line).
- Commands are case-insensitive.

## Build Artifacts

Ignore these folders/files (they are generated):

- `build/`
- `*.exe` / `kvstore` (built binaries)
- `store.txt` (optional — contains your data)

Use a `.gitignore` with at least:

```
build/
*.exe
kvstore
store.txt
.vscode/
```

Enjoy!
