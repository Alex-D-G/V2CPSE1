.cpu cortex-m0
.text
.align 2
.global print_asciz
.global application

asc:
   .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"

print_asciz:
   push { r5, lr }
   mov  r5, r0
loop: 
   ldrb r0, [ r5 ]
   add  r0, r0, #0
   beq  done
   bl   uart_put_char
   add  r5, r5, #1
   b    loop
done: 
   pop  { r5, pc }

application:
   ldr r0, =asc
   push {lr}
   bl   print_asciz
   pop  {pc}
