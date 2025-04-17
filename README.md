# 🗳️ Voting System (C++)

A simple command-line voting system written in C++. This project allows users to vote for predefined candidates, handles case-insensitive input, checks for invalid names, and displays the vote results along with the winner.

## ✨ Features
- Predefined list of candidates  
- Case-insensitive voting input  
- Validation for invalid candidate names  
- Displays individual scores and the winner  
- Uses modern C++ features like `vector`, `string`, `transform`, and `iomanip`

## ⚙️ How It Works
1. Enter the number of voters  
2. Each voter types in a candidate’s name  
3. Votes are counted and results are displayed  
4. Invalid names are rejected  


## 🚀 Getting Started

### Compile
Use any C++ compiler. Example with g++:

```bash
g++ -o voting voting_system.cpp
./voting
