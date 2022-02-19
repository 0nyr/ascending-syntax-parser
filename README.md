# Ascending Syntax Parser LR(1)

This project is a **specific LR(1) (LALR optimized) Ascending Syntax Parser** for the grammar provided in the subject (see `docs/sujet_tp.pdf`).

> circular imports, templating, template specialisation, state DP, singleton DP, GDB debugging

![make run output example](./img/make_run_example.png)

This program has been tested and built for Linux (tested on Ubuntu 20.04).

### Useful links

[solve circular imports](https://pvigier.github.io/2018/02/09/dependency-graph.html)

[Use GDB debugger](https://www.bitdegree.org/learn/gdb-debugger)

## Compile and run

To run the main program:

1. `make dirs` inside the root folder of the project.
2. `make` or `make build`
3. Run the program directly using `./bin/main <expression>` or use `make run`.

To run the tests:

1. `make build_test` or `make all`
2. Run the program using `./bin/test` or `make run_test`.

## Notes

##### template specialization

[Multiple definition of template specialization](https://stackoverflow.com/questions/4445654/multiple-definition-of-template-specialization-when-using-different-objects)

When using template specialization, the specializations must be declared after the generic one. To be able to include the template in multiple files, use the keyword `inline` in the specializations to make the compiler understand that the symbol will be present in more than one object file without violating the One Definition Rule.
