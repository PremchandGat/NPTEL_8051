// SAMPLE CODE TO GIVE INPUTS THROUGH DIP SWITCHES

ORG 00H
LJMP MAIN
ORG 30H
    MAIN: 
          MOV R7,#4           // SINCE WE HAVE TO READ FOUR INPUTS OF 8 BITS.
		  MOV R0,#60H
		  
		  UPP:
		  
		  MOV P1, #0FH        // SETTING UPPER NIBBLE (4 BITS) OF PORT 1 AS INPUT
		  SETB P1.7          // SWITCHING ON LED TO INDICATE INPUT IS BEING TAKEN
          ACALL DEL_10s     // 5 SECONDS DELAY TO PROVIDE INPUTS THROUGH THE DIP SWITCHES
		  CLR P1.7         // SWITCHING OFF LED TO INDICATE INPUT READING IS DONE
		  
		  MOV A,P1
		  SWAP A           // SWAPPING THE LOWER 4 BITS WITH UPPER 4 BITS
		  
		  ACALL DEL_5s    // WAIT FOR 5 SECONDS.
		  
		  MOV P1, #0FH        // SETTING LOWER NIBBLE (4 BITS) OF PORT 1 AS INPUT
		  SETB P1.7          // SWITCHING ON LED TO INDICATE INPUT IS BEING TAKEN
          ACALL DEL_10s     // 5 SECONDS DELAY TO PROVIDE INPUTS THROUGH THE DIP SWITCHES
		  CLR P1.7         // SWITCHING OFF LED TO INDICATE INPUT READING IS DONE
		  
		  ORL A,P1        //MERGING /COMBINING THE TWO 4 BITS INPUT THAT WE TOOK TO FORM ONE 8 BIT INPUT
		  MOV @R0,A			// STORING THE 8 BIT INPUT AT MEMORY LOCATION POINTED BY R0.
		  
		  INC R0
		  
		  DJNZ R7,UPP
	      
	HERE: SJMP HERE

	//250 uS delay	  
	DEL_250us: PUSH 00H
	           MOV R0,#244
               L250us: DJNZ R0,L250us
               POP 00H
               RET


    //1mS delay
    DEL_1ms: PUSH 00H
	         MOV R0, #4
			 L1ms: acall DEL_250us
				   DJNZ R0 ,L1ms	 
			 POP 00H
			 RET	

			 
	//250mS delay		 
    DEL_250ms: PUSH 00H
               MOV R0, #250
               L250ms: acall DEL_1ms
				     DJNZ R0 ,L250ms	 
			   POP 00H
			   RET	

	//1S delay		 
	DEL_1s: PUSH 00H
            MOV R0, #4
            L1s: acall DEL_250ms
				 DJNZ R0 ,L1s	 
			POP 00H
			RET	


	//5S delay		 
	DEL_5s: PUSH 00H
            MOV R0, #5
            L5s: acall DEL_1S
				 DJNZ R0 ,L5s	 
			POP 00H
			RET	

	//10S delay 
	DEL_10s: PUSH 00H
            MOV R0, #10
            L10s: acall DEL_1s
				 DJNZ R0 ,L10s	 
			POP 00H
			RET	

END	

