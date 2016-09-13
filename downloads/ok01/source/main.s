.section .init
.globl _start
_start:

b main

.section .text

main:
/*
*	Setting up the stack befor calling the execute function as per C calling conventions.
*/
mov sp,#0x8000
bl execute 
