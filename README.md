# README: Automaton Project

## Overview
This project implements a Finite State Automaton (Automate à États Finis) using a linked list data structure in C. Each node in the list represents a character of an input word. The program evaluates the input word and verifies its compliance with predefined constraints, such as:

- Recognizing a well-formed pseudo-identifier.
- Detecting specific patterns of letters and digits.
- Handling inputs consisting of odd or even numbers.

## Features
1. **Dynamic Linked List:** Stores input characters dynamically as a sequence of nodes.
2. **Automaton Logic:** Processes the input word and evaluates constraints.
3. **Error Detection:** Provides clear error messages for invalid inputs.
4. **Memory Management:** Ensures proper allocation and deallocation of memory for efficient performance.

## Prerequisites
- A C compiler (e.g., GCC).
- Basic understanding of C programming.

## How to Run
1. Clone or download this repository.
2. Open a terminal or command prompt.
3. Navigate to the directory containing the source file.
4. Compile the program using:
   ```bash
   gcc -o automaton automaton.c
   ```
5. Run the program:
   ```bash
   ./automaton
   ```

## Usage
1. The program prompts you to enter a word.
2. Enter a word consisting of letters and digits.
3. The program evaluates the word and outputs:
   - If the input is a well-formed pseudo-identifier.
   - If there are errors, such as consecutive letters or digits.
   - If the input is an odd or even number.

## Code Structure
- **Main Logic:** Handles user input, automaton creation, and processing.
- **Functions:**
  - `createAutomaton()`: Initializes a new automaton.
  - `addCharacter()`: Adds a character to the automaton.
  - `displayAutomaton()`: Displays the characters in the automaton.
  - `processAutomaton()`: Evaluates the input word based on predefined rules.

## Example Output
```text
This is my project based on the AEF (Automate à États Finis) associated with it.
It is designed using linked lists, where each node represents a character.
Houssem Bouagal

Please enter a word to test: test123
Input recognized as a well-formed pseudo-identifier!

Please enter a word to test: ab12
ERROR: Input is a mix of letters and digits that violates the constraint!

Please enter a word to test: 135
Input recognized: odd number!
```

## Notes
- Input should not exceed 254 characters.
- Proper memory management ensures no memory leaks.

## Author
Houssem Bouagal

