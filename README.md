## Overview
Expanded a C++ program that added an undo feature that allows players to undo the most recent move to a console-based game called Halfgammon.

## Skills Demonstrated
- Custom Linked List & Nodes
- State management

## What is HalfGammon?
Half Gammon is a simplified version of Backgammon where the goal is to move all of your checkers across the board and off the end to win. Players take turns rolling a die and moving one checker forward by the value shown. If you land on a space with exactly one opponent checker, you bump it into the bumped area, and it must re-enter before that player can move other pieces. If a space has two or more opponent checkers, that space is blocked, so you can’t land there; if no legal moves are available for your roll, you lose your turn.

## Run Program
1. Compile in the terminal
  - g++ -std=c++17 -Wall -Wextra -O2 main.cpp HalfGammonBoard.cpp GameList.cpp GameNode.cpp -o halfgammon
2. ./halfgammon

