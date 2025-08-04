# Custom GLM Reimplementation

A ground-up re-implementation of the core modules from the OpenGL Mathematics (GLM) library in modern C++17, with comprehensive unit tests and performance benchmarks.

---

## 📖 Overview

This project recreates the essential vector, matrix, quaternion, and extended math routines from [GLM](https://github.com/g-truc/glm) in C++17:

- **Core math types**: `vec2`, `vec3`, `vec4`, `mat2`, `mat3`, `mat4`
- **Quaternion support**: rotation, SLERP, axis-angle conversion
- **Advanced functions**: `transform`, `perspective`, `lookAt`, `inverse`, `transpose`
- **Utility**: common constants (`pi`, `epsilon`), helper traits
- Also it supports swizzle functions.

All algorithms are hand-translated from GLM’s spec, with a focus on numerical correctness and easy-to-follow implementation.

---

## ⚙️ Features

- ✔️ **Self-contained**: No external dependencies beyond the C++17 standard library  
- 🔍 **Unit-tested**: Full coverage via Google Test  
- 🏎️ **Benchmarks**: Critical kernels measured for performance  
- 📚 **Well-documented**: Inline comments explain algorithmic choices and edge-case handling  

---

## 🚀 Getting Started

### Prerequisites

- A C++17-capable compiler (GCC ≥ 7.0, Clang ≥ 5.0, MSVC ≥ 2017)  
- [CMake](https://cmake.org/) ≥ 3.10  
- [Google Test](https://github.com/google/googletest) (installed or added as submodule)  

### Clone & Build

```bash
git clone https://github.com/<your-username>/custom-glm.git
cd custom-glm
mkdir build && cd build
cmake ..
make
