# 🎮 Quiz Game in C++

This project is a terminal-based quiz game developed in C++ using object-oriented programming principles. It allows users to start a quiz, pause/resume the game, and view a help screen, all from a clean main menu interface.

---

## 🚀 Motivation

As part of my journey learning C++—especially following The Cherno's C++ tutorial series—I wanted to challenge myself with a **project that combines control flow (conditionals, loops, switches), file I/O, string parsing, and OOP**. I aimed to build something practical but expandable.

I chose a quiz game for several reasons:
- It lets me practice real input/output flow with users.
- It involves reading structured data (question-answer pairs).
- It makes me work with vectors, file streams, and logic structures like `switch`, loops, and `struct`s.

---

## 🧱 Project Structure and Design

### 📁 Files

| File                     | Purpose                                                        |
|--------------------------|----------------------------------------------------------------|
| `MainGame.cpp`           | Entry point. Manages the main menu and user navigation.        |
| `GameLoop.cpp`           | Handles quiz gameplay: displaying questions, taking input.     |
| `GetQuestionById.cpp`    | Reads specific question data from a `.txt` database.           |
| `LoadRandomQuestions.cpp`| Loads and shuffles a specified number of questions.            |
| `Question.cpp`           | Implements logic for `Question` class methods.                 |
| `Question.h`             | Declares the `Question` class and I/O functions.               |
| `GameState.h`            | Contains the `GameState` struct to track game progress.        |
| `GameScreens.h`          | Declares `GameLoop` function.                                  |
| `Database/questionDB.txt`| Text-based database of quiz questions.                         |

---

## 🧠 Key Design Decisions

### 🟡 Text-Based Database (for now)

I chose to use a simple `.txt` file to store questions using this format:

```
###4 What is the capital of France?
0 Berlin_1 Rome_2 Paris_3 Madrid_##2
```

- Each question is prefixed with a tag like `###4` and followed by a line of answers.
- `_` separates the answers, and `##` marks the correct answer’s index (e.g., `##2`).

✅ This format was quick to parse and flexible enough for early development.

🛠️ I **plan to upgrade this to a real SQL database** (e.g., SQLite or PostgreSQL) in future versions.

---

### 🧩 Game State Management

To support features like **pausing and resuming**, I introduced the `GameState` struct:

```cpp
struct GameState {
    std::vector<Question> Questions;
    int currentIndex = 0;
    int score = 0;
    bool isActive = false;
};
```

This allows the player to:
- Start a new game (`case 1` in main menu).
- Pause a game (by entering `0` during a question).
- Resume the game from where they left off (`case 2` in menu).

This was a deliberate and thoughtful design choice to separate game logic from game data, making future upgrades (e.g., saving game state to disk) easier.

---

### 🧮 Main Menu with `switch`

The menu is built using a `while (running)` loop and `switch` statement, offering options:

```
1. Start Game
2. Resume Game
3. Help
4. Exit
```

A `bool running = true` flag ensures the game keeps looping until the user chooses to exit.

---

## 🧪 Key Concepts Practiced

- `switch`, `if`, `while`, `for` control structures
- File reading with `std::ifstream` and line parsing
- Object-oriented design with constructors and encapsulated logic
- Vector manipulation (`push_back`, `resize`, `shuffle`)
- Basic string parsing (splitting using `_` delimiters)
- Separating concerns into multiple `.cpp` and `.h` files

---

## 🔄 Future Improvements

- ✅ Convert text-based DB to a real SQL database
- 💾 Save paused game state to file and load later
- 🧠 Add difficulty levels or timed questions
- 🎨 Build a graphical UI with SFML or Qt
- 🌐 Add support for loading questions from online sources

---

## 📸 Example Gameplay

```
Welcome to the Quiz Game!
1. Start Game
2. Resume Game
3. Help
4. Exit
Enter your choice
> 1
How many questions you want to answer?
> 3

Question: What is the capital of France?
1. Berlin - 2. Rome - 3. Paris - 4. Madrid
Your answer (0 to pause): > 3
It's correct!
...
```

---

## 💬 A Note on Learning

I built this game not just to complete a project, but to **internalize key C++ principles** and build a foundation for more serious application development. Every part of this codebase reflects decisions I made deliberately, through experimentation, feedback, and iteration.

Thanks for checking it out! 🚀
