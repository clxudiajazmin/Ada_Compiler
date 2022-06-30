.data
# variables
a: .byte 'c'
b: .float 2.500000
c: .float 7.200000
# messages

.text
main:
BEQ $s0, 99, Temp_Label
BNE $s0, 98, Temp_Label
AND $s0, $s0, $s0
li $v0, 10
syscall
Temp_Label: 
add.s $f2, $f0 $f0 
mov.s $f0, $f2
li $v0, 1
add $a0, $zero, $s1
syscall