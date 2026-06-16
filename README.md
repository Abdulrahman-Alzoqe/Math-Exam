# 🧮 Math Exam Game 

A fun, interactive, and educational console-based math game built using **C++**. This project is designed to test and improve mental math skills by presenting users with dynamic arithmetic challenges based on their preferred settings.

---

## 🚀 Features

* **Customizable Quizzes:** Players can choose exactly how many questions they want to tackle per round.
* **4 Difficulty Levels:** Dynamic number generation tailored to different skill sets:
  * 🟢 **Easy:** Numbers from 1 to 10.
  * 🟡 **Normal:** Numbers from 10 to 20.
  * 🔴 **Hard:** Numbers from 20 to 100.
  * 🔀 **Mix:** Randomly rotates through all difficulty levels.
* **Multiple Operation Types:**
  * ➕ Addition
  * ➖ Subtraction
  * ✖️ Multiplication
  * ➗ Division
  * 🔄 **Mix:** Randomly shuffles operations for every question.
* **Instant Visual Feedback:** The console background color dynamically changes (Green for Correct answers, Red for Incorrect ones with the right answer displayed).
* **Comprehensive Performance Summary:** Displays a detailed final scorecard showing pass/fail status, accurate stats, and an option to instantly replay.

---

## 🛠️ Programming Concepts Applied

This project demonstrates strong foundational concepts in C++ development:
* **Structs & Enums:** Utilized to write clean, maintainable, and highly organized code by grouping related game and question attributes.
* **Control Flow:** Advanced implementation of `switch-case` statements and `if-else` logic for navigating user inputs and operation execution.
* **Loops:** Leveraged `do-while` and `for` loops for seamless input validation and game-state iteration.
* **Randomization:** Uses `rand()` seeded with `srand(time)` to ensure uniquely generated questions every time you play.

---

## 💻 How to Run

To run this game locally on your machine, follow these steps:

### Prerequisites
Make sure you have a C++ compiler installed (like `g++`).

### Installation & Execution
1. Clone this repository or copy the code into a file named `main.cpp`.
2. Open your Terminal / Command Prompt and compile the code:
```bash
   g++ -o MathGame main.cpp
