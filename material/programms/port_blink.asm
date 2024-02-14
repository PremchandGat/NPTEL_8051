
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL PORT_BLINK
HERE: SJMP HERE
ORG 130H



delay_1s:
push 00h
mov r0,#4
h4:acall delay_250ms
djnz r0,h4
pop 00h
ret 

delay_250ms:
push 00h
mov r0,#250
h3:acall delay_1ms
djnz r0,h3
pop 00h
ret 

delay_1ms:
push 00h
mov r0, #4
h2: acall delay_250us
djnz r0, h2
pop 00h
ret

delay_250us:
push 00h
mov r0, #244
h1: djnz r0, h1
pop 00h
ret

PORT_BLINK:

SETB P1.4
SETB P1.5
SETB P1.6
SETB P1.7

CALL delay_1s

CLR P1.4
CLR P1.5
CLR P1.6
CLR P1.7
CALL delay_1s

JMP PORT_BLINK

RET 

END