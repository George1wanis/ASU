# Logic Resistance Calculator in C++

**Author:** George Wanis Ayed Wanis  
**Student ID:** 2300280  
**Project:** C++ Programming Project  

---

## Overview

This program calculates the total electrical resistance of a circuit that contains resistors connected in **series** and **parallel**.  
The user provides a single input string that describes the circuit, and the program evaluates it step by step until the final equivalent resistance is obtained.

The program supports:
- Series operations using `S` or `s`
- Parallel operations using `P` or `p`
- End of operation using `E` or `e`

---

## Input Format

You must enter the circuit description as a single line.

### Rules
- Use `S` (or `s`) for series group  
- Use `P` (or `p`) for parallel group  
- End each group with `E` (or `e`)  
- Separate resistor values using spaces or commas  
- Only numbers, `S`, `P`, `E`, spaces, commas and dots are allowed  
- Any other character will result in **"Wrong Description"**

### Examples

S 10 20 E

Means: 10Ω and 20Ω in series

P 10 20 30 E

Means: 10Ω, 20Ω, 30Ω in parallel

Nested example:
S 10 P 20 30 E 40 E

Means: 10Ω in series with (20Ω || 30Ω) in series with 40Ω

---

## How the Program Works

1. The program first checks the input for invalid characters.  
   If something invalid is found, it prints:
Wrong Description


2. It repeatedly finds the last `S` or `P` in the string.  
3. It finds the matching `E` after it.  
4. It extracts the numbers between them.  
5. It calculates:
- Series:  
  R = R1 + R2 + ...
- Parallel:  
  R = 1 / (1/R1 + 1/R2 + ...)

6. It replaces the whole operation with the computed equivalent value.  
7. This continues until no `S` or `P` remain.

Finally, it prints:
The total resistance = <value>


---

## Compilation and Run

Compile:
```bash```
g++ -o resistance main.cpp
Run:

./resistance
Then paste your circuit description and press Enter.

Example Runs
Input:

S 10 20 30 E
Output:

The total resistance = 60
Input:

P 10 20 30 E
Output:

The total resistance = 5.45455
Input:

S 10 P 20 30 E 40 E
Output:

The total resistance = 50
Important Notes
Series must contain at least 2 resistors, otherwise:

Incorrect Input
Parallel must contain at least 3 resistors, otherwise:

Incorrect Input
The program supports nested operations naturally

Input must strictly follow the described format

License
This project was created for educational purposes as part of a university assignment.


---

If you want, I can also make:
- a shorter GitHub-style README  
- a more academic/professor-style README  
- or a version with screenshots/examples  

Just tell me which style you want.
