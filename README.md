<p align="center">
<h1>0x19. C - Stacks, Queues - LIFO, FIFO</h1>
An interpreter for Monty ByteCodes files.</p>
  
<h2>Table of Contents</h2>
<p align="center">
<a href="#overview">Overview</a> | <a href="#glossary">Glossary</a> | <a href="#compilers">Compiler</a> | <a href="#authors">Authors</a>
</p>

<p align="center">
<h2>Overview</h2> </p>
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.


Monty byte code files


Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
``` 
