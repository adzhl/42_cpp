# 42 C++ Modules

This repository contains my solutions to the 42 C++ Modules
 projects.
The modules are designed to gradually introduce object-oriented programming concepts, templates, the STL and advanced C++ features through hands-on exercises.

## 📚 Overview of Modules
<details>
<summary> Module 00: Basics </summary>
  
- Introduction to C++ syntax and compilation

- Understanding namespaces, classes, member functions, and the orthodox canonical form

- Implemented a simple phonebook and account management system
- ([Go to Module](./module_00))
</details>

<details>
<summary>Module 01: Memory, References, Pointers</summary>
  
- Stack vs Heap allocation

- Pointers, references, and their differences

- Dynamic memory management with new and delete

- Exercises: Zombie creation, random heap/stack allocation

- ([Go to Module](./module_01))
</details>

<details>
<summary>Module 02: Ad-hoc Polymorphism, Operator Overloading</summary>
  
- Operator overloading (assignment, insertion <<, etc.)

- Fixed-point number implementation

- Learning how to work with canonical form + copy semantics
- ([Go to Module](./module_02))
</details>

<details>
<summary>Module 03: Inheritance</summary>
  
- Introduction to inheritance and virtual functions

- Diamond problem and multiple inheritance

- ClapTrap, ScavTrap, FragTrap, DiamondTrap class hierarchy
- ([Go to Module](./module_03))
</details>

<details>
<summary>Module 04: Subtype Polymorphism, Abstract Classes, Interfaces</summary>
  
- Polymorphism via virtual functions

- Abstract base classes and pure virtual functions

- Deep copy vs shallow copy

- Exercises: Animals, Materia (inspired by RPG inventory system)
- ([Go to Module](./module_04))
</details>

<details>
<summary>Module 05: Exceptions</summary>
  
- Exception handling with try/catch

- Throwing custom exceptions

- Bureaucrat and Form classes with grade restrictions
- ([Go to Module](./module_05))
</details>

<details>
<summary>Module 06: C++ Casts</summary>
  
- static_cast, dynamic_cast, reinterpret_cast, and const_cast

- Handling polymorphism safely with casting

- Serialization and type identification
- ([Go to Module](./module_06))
</details>

<details>
<summary>Module 07: Templates</summary>
  
- Function and class templates

- Template specialization

- Custom array class with deep copy, iterator support

- easyfind (search function using STL algorithms)
- ([Go to Module](./module_07))
</details>

<details>
<summary>Module 08: Templated Containers, Iterators and Algorithms</summary>
  
- Using STL containers & algorithms idiomatically

- Exercises:

  - easyfind: find value in a container using std::find

  - Span: shortest/longest spans using sorting & std::adjacent_difference

  - MutantStack: iterable std::stack via c/container_type exposure
- ([Go to Module](./module_08))
</details>

<details>
<summary>Module 09: STL Containers & Algorithms</summary>
  
- Using STL containers (vector, list, map, stack, deque)

- Implemented:

  - BitcoinExchange: map-based lookup for BTC value by date

  - RPN: Reverse Polish Notation calculator

  - PmergeMe: merge-insertion sort (Ford-Johnson algorithm) with Jacobsthal sequence

- Heavy use of STL algorithms (std::find, std::sort, etc.)
- ([Go to Module](./module_09))
</details>


## 🛠️ Tech & Rules

- **Language:** C++98 (strict standard)

- **Compilation:** `-Wall -Wextra -Werror`

- **Restrictions:**

  - No external libraries outside standard C++

  - Certain exercises forbid reusing the same STL container

- **Orthodox Canonical Form** followed across classes:

  - Default constructor

  - Copy constructor

  - Assignment operator

  - Destructor

## ✨ Key Learnings

- Object-Oriented Programming in C++

- Canonical class form & deep copies

- Exception handling

- Operator overloading & polymorphism

- Templates and STL algorithms

- Efficient sorting algorithms (Ford-Johnson with Jacobsthal sequence)

- Real-world data parsing and validation

## Compilation

1. Clone this repository:

    ```bash
    git clone github.com/adzhl/42_cpp
    ```

2. Navigate to a module:
   
   _Below is an example if you want to go to ex00 of module 00_

    ```bash
    cd module_00/ex00
    ```

4. Compile and run tge program:

    ```bash
    make
    ```
    ```bash
    ./[executable name] (check newly created executable in directory)
    ```
