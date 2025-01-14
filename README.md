# C++ methodology
This methodology is used for practical study of C++. Project contains code examples of language elements, paradigms, design patterns. Additionaly there could be found usage of boost library, implementation of sorting and searching algorithms, exercises and applications. Implementation usage is demonstrated with unit tests. Project could be usefull for study of language or for training purposes.


## Sources

### Documentation

https://cplusplus.com/doc/tutorial/

https://en.cppreference.com/w/cpp

### Design Patterns

https://sourcemaking.com/design_patterns

https://refactoring.guru/design-patterns

### Boost Library

https://www.boost.org/

### Unit Tests

https://google.github.io/googletest/primer.html

### Clean Code

https://cleancoders.com/episode/clean-code-episode-1

## Usage

Usage is demonstrated through unit tests implemented with googletest framework. It is necessary to clone googletest as subrepository as first step before project compilation.

```bash
cd lib
git clone https://github.com/google/googletest
cd ..
```

After that you can manualy compile the project with cmake.
```bash
cmake .
make
```

