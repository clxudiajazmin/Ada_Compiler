.data
# variables
a: .byte 'c'
b: .float 2.500000
c: .float 7.200000
# messages

.text
main:
lwc1 $f0, c
lwc1 $f0, b
add.s $f2, $f0 $f0 
mov.s $f0, $f2
