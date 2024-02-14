ORG 0H
LJMP MAIN
ORG 100H
MAIN:
mov r0 , #60H
mov r1, #70H
mov r3 , #3
mov r4, #1;

acall MULTI
HERE: SJMP HERE
ORG 130H


MULTI:
	mov A, @r0;
	mov B, @r1;
	MUL AB;
	acall Save
	INC r1
	INC r0
	INC r4
	djnz r3, MULTI

Save:
	PUSH 00H				
	MOV R0,#65H
	MOV R5, #0;
	increase:
		INC R0;
		INC R5;
		djnz r4, increase
	mov @R0, B
	INC R0
	mov @R0, A
	MOV A, r4;
	add A, r5;
	mov r4, A;
	POP 00H
	RET


RET
END