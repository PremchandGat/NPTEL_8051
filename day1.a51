ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL TAKE_INP
HERE: SJMP HERE
ORG 130H
// *****************


DELAY:
// ADD YOUR CODE HERE


TAKE_INP:
	mov 70H, #16;
	mov r1, #60H;
	mov r5, #10
	TakeIn:
		//mov p1, 70H
		acall Indicator
		//acall delay_10sec
		mov p1, #0ffh
		//acall delay_250msec;
		mov r3, p1
		acall Indicator
		//mov p1, 70H
		//acall delay_10sec
		mov p1, #0ffh
		//acall delay_250msec;
		mov r4, p1
		clr A
		mov A, r3
		swap A
		add A, r4
		mov @r1, A
		INC r1
		djnz r5, TakeIn

TAKE_INDEX:
	mov p1, #0ffh
	//acall delay_250msec;
	mov r4, p1
	cjne r4 , #10, nnn
	nnn:
	jnc nextt
		mov r1, #60H;
		mov A, r1;
		add A, r4;
		mov r1, A
		mov p1, @r1;
		mov A, @r1
		swap A;
		mov p1, A;
		//acall delay_250msec;
	nextt:
	mov p1, #0
	HERESS: SJMP HERESS
	RET
		


Indicator:
	mov r7 , 70H
	mov p1 , r7
	mov A, r7
	add A, #16
	mov 70H, A
	RET

delay_10sec:
	mov r7, #5
	h5: acall delay_1sec
		djnz r7, h5
		ret

delay_1sec:
	mov r6, #4
	h4: acall delay_250msec
		djnz r6, h4
		ret

delay_250msec:
	push 004
	mov r0, #250
	h3: acall delay_1ms
		djnz r0, h3
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



RET
END