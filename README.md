# Ascending Syntaxt Parser LR(1)

> circular imports, templating, template specialisation, state DP, singleton DP, GDB debugging

### Useful links

[solve circular imports](https://pvigier.github.io/2018/02/09/dependency-graph.html)

[Use GDB debugger](https://www.bitdegree.org/learn/gdb-debugger)


## Notes

##### template specialization

[Multiple definition of template specialization](https://stackoverflow.com/questions/4445654/multiple-definition-of-template-specialization-when-using-different-objects)

When using template specialization, the specializations must be declared after the generic one. To be able to include the template in multiple files, use the keyword `inline` in the specializations to make the compiler understand that the symbol will be present in more than one object file without violating the One Definition Rule.
