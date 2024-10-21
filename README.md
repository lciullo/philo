# 

<h1 align="center">🍝 Philosophers</h1>
<p align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C"/>
  <img src="https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white" alt="42"/>
</p>

A solution to the dining philosophers problem implementing thread synchronization and mutex locks, developed as part of the 42 curriculum.

## 📋 Overview

The Philosophers project tackles the classic dining philosophers problem, demonstrating process synchronization, mutual exclusion, and deadlock prevention. Each philosopher must eat, sleep, and think while sharing forks with their neighbors, all without starving.

## ✨ Features

### Core Functionality
* Multi-threaded simulation
* Mutex lock implementation
* Death detection system
* Timestamp monitoring
* Resource sharing management

### Philosopher States
* 🍴 Eating (requires two forks)
* 😴 Sleeping
* 🤔 Thinking
* ⚰️ Dead (if starved)

### Simulation Parameters
* Number of philosophers
* Time to die (in milliseconds)
* Time to eat (in milliseconds)
* Time to sleep (in milliseconds)
* Number of times each philosopher must eat (optional)

## 🚀 Getting Started

### Prerequisites
* GCC compiler
* Make
* Unix-like operating system
* pthread library

### Installation

```bash
# Clone the repository
git clone https://github.com/lciullo/philo
cd philosophers

# Compile the project
make
```

### Usage

```bash
# Basic usage
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

# Example
./philo 5 800 200 200 7
```

## 🎯 Project Objectives
* Understand threading concepts
* Implement mutex locks
* Handle race conditions
* Prevent deadlocks
* Manage shared resources
* Monitor process states
* Handle program termination

## 🛠️ Technical Implementation

### Threading
* Thread creation and management
* Mutex implementation
* Race condition prevention
* Deadlock avoidance
* Resource allocation

### Monitoring System
* Death detection
* Meal counting
* Time management
* State transitions
* Resource availability


## 🧠 Learning Outcomes
This project provides experience in:
* Thread synchronization
* Mutex locks
* Race condition handling
* Deadlock prevention
* Resource sharing
* Process monitoring
* Time management
* System programming

## 🔍 Error Handling
* Invalid arguments
* Thread creation failures
* Mutex initialization errors
* Memory allocation failures
* System call errors
* Edge cases

## ✅ Testing
### Test Cases
* Basic functionality
  * `./philo 5 800 200 200`
* With meal limit
  * `./philo 5 800 200 200 7`
* Edge cases
  * One philosopher
  * Maximum values
  * Minimum values

## 📝 License
This project is part of the 42 school curriculum.

## 📈 Optimization Techniques
* Efficient thread management
* Minimal mutex locking time
* Reduced context switching
* Optimal resource sharing
* Precise timing implementation

## 🤝 Contributors
- **Lisa Ciullo** - [@lciullo](https://github.com/lciullo)
