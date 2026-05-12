# P1: File Management System — Project Plan

## What the project actually demands 

Building a fake "file explorer" that runs in the terminal. Think of it like a derived version of Windows File Explorer, but the user controls it by typing commands instead of clicking.

### The big picture

- The program has a folder called `root/` that is considered to be the "C: drive."
- Inside `root/`, the user can make folders, make files, delete things, rename things, search, navigate in and out — all by typing commands like `mkdir`, `cd`, `ls`, `rm`, etc. (Same commands as a real Linux terminal.)
- Everything the user creates is a **node**. A node is either a **folder** (can hold other nodes) or a **file** (a leaf).

### The OOP shape of it

This project is basically a **tree data structure**.

```
        Node (abstract) 
        /            \
    Folder          File (abstract)
                   /   |    \    \
                Txt  Audio Private  Zip
```

- `Node` is the abstract base — every item has a `name` and a `parent` pointer.
- `Folder` holds a vector of child `Node*` pointers. This is how the tree is built.
- `File` has 4 types, and each behaves differently when created / opened / deleted:
  - **Txt** → empty `.txt` file, opens in terminal as a mini text editor (move up/down lines, edit, add).
  - **Audio** → records 5 seconds from the mic on creation (using `ffmpeg`), plays via speakers when opened.
  - **Private** → password-protected text file (`.priv` extension). Asks for passkey to open or delete.
  - **Zip** → wraps an existing node. Can't be opened directly; can be unzipped.

### The CommandManager

This is the "brain" that listens for what the user types and decides what to do. It tracks **which folder is currently open** (a pointer called `currentFolder`). Commands it must handle:

| `ls` | Show what's in the current folder |
| `mkdir <name>` | Make a folder |
| `touch <type> <name>` | Make a file (txt / audio / priv / zip) |
| `cd <name>` / `cd ..` | Go into a folder / go back up |
| `search <name>` | Recursively look through all subfolders for a node, print its full path |
| `rm <name>` | Delete a node |
| `rename <new_name>` | Rename current open node |


### Required folder layout

OOP project/
├── main.cpp        ← entry point (small file, just starts the program)
├── src/            ← all your .h and .cpp files live here
│   ├── Node.h / .cpp
│   ├── Folder.h / .cpp
│   ├── File.h / .cpp
│   ├── TxtFile.h / .cpp
│   ├── AudioFile.h / .cpp
│   ├── PrivateFile.h / .cpp
│   ├── ZipFile.h / .cpp
│   └── CommandManager.h / .cpp
└── root/           ← the simulated "C: drive" — also where actual real files get saved
```


## Quick reference — file type behavior summary

| Type | Extension | On Create | On Open | On Delete |

| Txt | `.txt` | Empty file | Terminal editor (up/down/edit/add lines) | Normal delete |
| Audio | `.mpg` | Record 5 sec from mic via ffmpeg | Play via speakers | Normal delete |
| Private | `.priv` | Prompt for passkey | Ask passkey, then text editor | Ask passkey + confirm |
| Zip | `<name>-zip.zip` | Wrap existing node | Print "zipped files cannot be opened, unzip first" | Normal delete |
