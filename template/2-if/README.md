# `2-if-for-array`

## `min-of-two.c`

- `if-else`
- code style
  - tab vs. space video
  - google format
  - format on save
- `?:`: conditional operator; ternary operator
- `fmin, fmax` for doubles

## `min-of-three.c`

- nested `if-else`
- `if-else` template
- comment for `else`

## `leap-if-else.c`

- flowchart
- `leap`: 0/1 integer as a flag
- `if-else`
  - easier cases go first
- code style
  - spaces
- `==`: 0 == leap
- `if (leap == 0)` vs `if (leap != 0)`

## `leap-else-if.c`

- easier cases go first (Flatten Arrow Code)

## `leap-elseif.c`

- `else if` (Cascading If Statements)
  - `{ }` removed
  - `if` and `else` in the same line
  - `Code => Format Code (Ctrl + Alt + L)`
- find the iff condition for leap

## `leap.c`

- `&&`, `||` operator
  - operator precedence (https://en.cppreference.com/w/c/language/operator_precedence)
- short-circuit
  - test: 25, 80, 100, 400
  - TODO: order of evaluation (https://en.cppreference.com/w/c/language/eval_order)
    - `i = ++i + i++;`
- Code improvements
  - `if`: without `else`
  - `int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);`
  - `?:` in `printf`
 
## Additional
- `Settings` => `Code Style` (Google)
- `Settings` => `Action on Save` (Formatting Code)
- TODO (hfwei): CLion code template