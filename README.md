```
S := INSTR [SEP INSTR]* #

INSTR :=
      push VALUE
    | pop
    | dump
    | assert VALUE
    | add
    | sub
    | mul
    | div
    | mod
    | print
    | exit

VALUE :=
      int8(N)
    | int16(N)
    | int32(N)
    | float(Z)
    | double(Z)

N := [-]?[0..9]+

Z := [-]?[0..9]+.[0..9]+

SEP := '\n'+
```

todo:
* better errors
* get rid of trailing zeros when printing floats
* should not treat exit as end of input

missing error types: 
* Overflow on a value or the result of an operation
* Underflow on a value or the result of an operation
* The program doesn’t have an exit instruction is executed.
