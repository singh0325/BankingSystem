# Banking System

A console based Banking System developed in C++ as part of an Object-Oriented Programming coursework. This project demonstrates key OOP principles combined with modern C++ features including templates, STL algorithms, and robust exception handling.

---

## Features

- **Multiple Account Types**
  - Savings Account
  - Premium Savings Account  
  - Current Account

- **Object-Oriented Design**
  - Multi-level inheritance hierarchy
  - Runtime polymorphism via base class pointers
  - Encapsulation and data abstraction

- **Modern C++ Implementation**
  - STL containers (`std::vector`)
  - STL algorithms (`std::sort`, `std::find_if`)
  - Generic programming with templates
  - Exception handling for safe transactions

- **Additional Highlights**
  - Generic manager class using templates
  - Preloaded dataset for demonstration (no manual input required)
  - Type-safe transaction processing

---

## OOP Concepts Demonstrated

| Concept | Implementation |
|---------|----------------|
| **Encapsulation** | Private member variables with public getters |
| **Inheritance** | Multilevel hierarchy (Account -> SavingsAccount -> PremiumSavingsAccount) |
| **Polymorphism** | Virtual functions for account specific behavior |
| **Abstraction** | Base class with pure virtual functions |
| **Templates** | Generic manager class for type independent operations |

---

## Compilation & Execution
 
### Prerequisites
- C++17 compatible compiler (g++ 7+, clang 5+, or MSVC 2017+ is ok)
- CMD

### Easy setup

```bash
# Compile all source files 
browse to local folder
g++ -std=c++17 *.cpp -o bank
./bank (OR) bank.exe # Depending on your OS

