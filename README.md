# Delivery Management System (C++)

A small console-based Delivery Management System written in modern C++ (C++17). This repository contains the implementation split into headers (`include/`) and sources (`src/`) and uses CMake for building.

---

## Table of contents

* [Project overview](#project-overview)
* [Features](#features)
* [Project structure](#project-structure)
* [Requirements](#requirements)
* [Build & Run (Linux)](#build--run-linux)

---

## Project overview

This is a Delivery Management System project organized as a C++ command-line application. Headers live in `include/` and implementations live in `src/`. The project is configured with a `CMakeLists.txt` so it can be built on Linux (and other platforms) using CMake.

Use this README to build, run, and (optionally) package an executable for distribution.

---

## Features

* Core classes for orders, drivers, restaurants, and the delivery system.
* Separation of interface (`.h`) and implementation (`.cpp`).
* CMake-based build for easy, reproducible builds.

> Note: The exact runtime behavior depends on the implementation of `main.cpp`. This README focuses on building and running the project.

---

## Project structure

```
Delivery_Management_System/
├── CMakeLists.txt         # top-level CMake file
├── include/               # public headers
│   ├── DeliverySystem.h
│   ├── Driver.h
│   ├── Order.h
│   ├── Point.h
│   └── Restaurant.h
├── src/                   # source files
│   ├── DeliverySystem.cpp
│   ├── Order.cpp
│   └── main.cpp
└── README.md              # this file
```

---

## Requirements

* A recent C++ compiler (g++ >= 7 recommended) supporting C++17.
* CMake >= 3.10 (CMake 3.10+ recommended).
* `make` or `ninja` as build tool (on Linux `make` is fine).

On Ubuntu/Debian install the essentials:

```bash
sudo apt update
sudo apt install -y build-essential cmake
# optional faster builds using Ninja:
sudo apt install -y ninja-build
```

---

## Build & Run (Linux)

From the project root (the directory that contains `CMakeLists.txt`):

1. Configure the project (out-of-source build):

```bash
cmake -S . -B build
```

2. Build (Release configuration):

```bash
cmake --build build --config Release
```

3. Locate and run the executable. Typical locations:

* `./build/DeliveryManagementSystem` (Unix-like generators)
* `./build/Release/DeliveryManagementSystem` (multi-config generators)

Run it:

```bash
./build/DeliveryManagementSystem
```
