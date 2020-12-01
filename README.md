# Reach

A learning project to create a contacts for linux using C++ and gtkmm.

## Building

### Install Dependencies
main application dependencies:
- https://github.com/libvc/libvc
- `libconfig++-dev` (https://hyperrealm.github.io/libconfig/)
- libglibmm-2.4-dev

testing dependencies:
- gtest and gmock

### Setup Build Directory
```
mkdir build
cd build
cmake ..
```
### Compile

to compile everything, run `make`

to compile just the app itself, run `make reach`

to compile the tests, run `make test`
