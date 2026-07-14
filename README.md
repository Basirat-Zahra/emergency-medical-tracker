# 🚑 Emergency Medical Services (EMS) Resource & Patient Tracker

A C++ console application that simulates an Emergency Medical Services (EMS) dispatch system. The project models patient triage, resource allocation, and emergency dispatch using modern C++ and STL data structures.

---

## Overview

Emergency response systems must rapidly prioritize patients while efficiently allocating limited medical resources.

This project simulates that workflow by:

- Registering incoming patients
- Prioritizing patients based on injury severity
- Managing medical resources
- Dispatching available resources
- Maintaining an archive of resolved emergency cases

The goal of this project was to strengthen my understanding of **object-oriented design**, **STL containers**, and **algorithmic thinking** while building a practical simulation.

---

## Features

- Patient registration
- Severity-based triage queue
- Resource inventory management
- Automatic emergency dispatch
- Resolved case archive
- Interactive command-line interface
- Modular object-oriented architecture

---

## Technologies

- C++17
- Standard Template Library (STL)

Containers used:

- `std::unordered_map`
- `std::map`
- `std::set`
- `std::vector`

Other concepts:

- Object-Oriented Programming
- Custom Comparators
- Encapsulation
- Constructor Initialization Lists
- Resource Scheduling
- Priority Queue Simulation

---

## System Architecture
<img width="735" height="488" alt="ems sys arch" src="https://github.com/user-attachments/assets/48d23496-e40a-44f2-8119-b676223374ca" />

## Workflow Diagram
<img width="503" height="820" alt="ems workflow" src="https://github.com/user-attachments/assets/27803224-14ac-413c-9415-8c88b2ceb622" />

---

## Data Structures

| Component | STL Container | Purpose |
|-----------|--------------|---------|
| Patients | `unordered_map` | Fast lookup by Patient ID |
| Resources | `map` | Ordered resource management |
| Triage Queue | `set` | Automatically sorted by severity |
| Archive | `vector` | Stores completed dispatches |

---

## Triage Algorithm

Patients are automatically ordered using a custom comparator.

Priority Rules:

1. Higher injury severity first
2. If severity is equal, lower Patient ID first

This ensures deterministic and predictable dispatch order.

---


## Sample Output

```
=== Welcome to Emergency Medical Resource & Patient Tracker ===

1. Admit Patient
2. Add Resource
3. Run Next Triage Dispatch
4. Show System Status
5. Exit

Running Triage Dispatch Engine...

[DISPATCH SUCCESS]
Patient John Smith (Severity 5)
allocated to resource ICU_BED_01
```

---

## Project Structure

```
EMS/
│
├── ems.cpp
├── README.md

```

---

## Skills Demonstrated

- Object-Oriented Programming
- C++ Class Design
- STL Container Selection
- Custom Sorting
- Algorithm Design
- Resource Scheduling
- Command-Line Application Development
- Data Management
- Software Architecture

---

## Future Improvements

Planned enhancements include:

- Care staff assignment
- Patient discharge workflow
- Resource release mechanism
- Persistent storage using files or SQLite
- Search functionality
- Exception handling
- Smart pointers
- Unit testing
- Multi-threaded dispatch simulation
- GUI version using Qt

---

## Learning Outcomes

This project helped strengthen my understanding of:

- Choosing appropriate STL containers
- Modeling real-world systems in C++
- Designing modular software
- Managing object relationships
- Implementing scheduling logic
- Building maintainable console applications

---
## 🚀 Getting Started

### Prerequisites

Before running the project, make sure you have:

- A C++17 compatible compiler (GCC 7+ or later)
- Git
- A terminal or command prompt

---

## 🐧 Running on Linux

### 1. Clone the repository

```bash
git clone https://github.com/Basirat-Zahra/emergency-medical-tracker.git
cd emergency-medical-tracker
```

### 2. Compile the project

```bash
g++ -std=c++17 -Wall -Wextra -o ems.cpp
or 
g++ ems.cpp -o ems.exe
```

### 3. Run the application

```bash
./ems
```

---

## 🪟 Running on Windows (MinGW)

### 1. Clone the repository

```bash
git clone https://github.com/Basirat-Zahra/emergency-medical-tracker.git
cd emergency-medical-tracker
```

### 2. Compile the project

```bash
g++ -std=c++17 -Wall -Wextra -o ems.exe main.cpp
or 
g++ ems.cpp -o ems.exe
```

### 3. Run the application

```bash
ems.exe
```

---

## 📌 Notes

- This project is written using **C++17** and requires a compiler that supports the C++17 standard. :contentReference[oaicite:0]{index=0}
- The project has no external dependencies and uses only the C++ Standard Library.
- The application is entirely console-based and can be compiled with any modern GCC/MinGW compiler supporting C++17. :contentReference[oaicite:1]{index=1}

---

## Author

**Basirat Z**

Software Quality Assurance Engineer with an interest in C++, systems programming, and embedded systems.

