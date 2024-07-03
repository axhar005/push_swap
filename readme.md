# Push Swap

## Project Overview


The `push_swap` project is an algorithmic challenge from the 42 school. The goal is to sort a stack of integers using a limited set of operations on two stacks (a and b). The aim is to find the most efficient algorithm to sort the stack in the fewest moves possible.

<img src="https://imgur.com/hBIFWaD.gif" alt="visualizer image" width="400">

### Available Operations

- `sa`: swap the first two elements of stack a.
- `sb`: swap the first two elements of stack b.
- `ss`: swap the first two elements of both stack a and stack b.
- `pa`: push the first element of stack b onto stack a.
- `pb`: push the first element of stack a onto stack b.
- `ra`: rotate stack a upwards.
- `rb`: rotate stack b upwards.
- `rr`: rotate both stacks a and b upwards.
- `rra`: reverse rotate stack a downwards.
- `rrb`: reverse rotate stack b downwards.
- `rrr`: reverse rotate both stacks a and b downwards.

## The Visualizer

In this project, we integrate the visualizer developed by [o-reo](https://github.com/o-reo/push_swap_visualizer.git). This visualizer allows you to follow the execution of your sorting operations in real time.

<img src="https://imgur.com/mWwURLe.gif" alt="visualizer image" width="400">

## How to Install the Project and Run the Visualizer

### Prerequisites

- `git`
- `make`
- `cmake`
- `gcc` or any compatible C compiler

### Installation

Clone the project repository:

```sh
git clone https://github.com/axhar005/push_swap.git
cd push_swap
make
make visu
```

if make visu output sh: "../../push_swap": No such file or directory
You need to modify the file push_swap_visualizer/src/pushswap.cpp by changing the path from ../../push_swap to ./push_swap and then execute make visu_update.