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

## System Architecture and Workflow Diagram
<img width="1536" height="1024" alt="ems sawf" src="https://github.com/user-attachments/assets/23635749-0c61-4ba6-bcc3-8d41c27f5797" />

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

## Author

**Basirat**

Software Quality Assurance Engineer with an interest in C++, systems programming, and embedded systems.

