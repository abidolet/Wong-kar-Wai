# Wong-kar-Wai

A terminal-based recreation of the [2048](https://github.com/gabrielecirulli/2048) game, built in C using the ncurses library.

---

## How to play

- Use the arrow keys to slide all tiles on the board.
- When two tiles with the same number collide, they merge into one.
- Each move spawns a new tile (2 or 4) on an empty spot.
- The goal is to reach the 2048 tile.
- The game ends when no more moves are possible.

---

## Build

### Requirements

- A C compiler (`cc` / `gcc` / `clang`)
- [`ncurses`](https://invisible-island.net/ncurses/) development library

**Linux (Debian/Ubuntu)**
```bash
sudo apt-get install libncurses5-dev libncursesw5-dev
```

**Windows / MacOS**

Just install linux

### Compilation

```bash
git clone https://github.com/abidolet/Wong-kar-Wai.git
cd Wong-kar-Wai
make
```

### Run

```bash
./2048
```

### Makefile targets

| Target | Description |
|--------|-------------|
| `make` / `make all` | Compile the project |
| `make clean` | Remove build files |
| `make fclean` | Remove build files + binary |
| `make re` | Remove build files + binary then recompile |

---

## Previews
![Game Screenshot](https://raw.githubusercontent.com/abidolet/Wong-kar-Wai/assets/game.png) 

![Leaderboard Screenshot](https://raw.githubusercontent.com/abidolet/Wong-kar-Wai/assets/leaderboard.png)  

![Menu Screenshot](https://raw.githubusercontent.com/abidolet/Wong-kar-Wai/assets/menu.png)

---

## Authors

**abidolet** — [github.com/abidolet](https://github.com/abidolet)  
**yamorett**

---