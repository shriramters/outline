# Outline
Still in development.

## [1. Introduction](#1-introduction)
Outline is a simple vector drawing application. This project is built around [RuiwenTang](https://github.com/RuiwenTang)'s spectacular vector graphics library [Skity](https://github.com/RuiwenTang/Skity).

## [2. Building](#2-building)
```bash
$ git clone --recursive https://github.com/shriramters/outline.git
$ git submodule update --init --recursive
$ mkdir build
$ cd build
$ cmake .. -DVULKAN_BACKEND=ON
# if using M1 Mac cmake .. -DVULKAN_BACKEND=ON -DPNG_ARM_NEON=on

$ make -j$(nproc)
$ ./outline
```
