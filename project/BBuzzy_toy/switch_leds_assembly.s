#include "switch_leds_assembly.h"
#include "stateMachines.h"
	
	.arch msp430g2553
	.p2align 1,0
	
	.data
state:	.word 0

	.text
jt:
	.word case1 	; 1
	.word case2 	; 2 
	.word case3	; 3
	.word case4	; 4
	
	.global switch_leds
switch_leds:
	;; range check on selector (state)
	cmp #4, &state 	; state-4
	jc end		; 

	;; index into jt 
	mov &state, r12 
	add r12, r12	; r12 = 2 * state
	mov jt(r12), r0 ; jmp jt[s]
	
	;; switch table cases
case1:	mov #1, &red_on 	; red_on = 1
	mov #1, &green_on 	; green_on = 1
	mov #20, r12 		; 2 seconds delay
	call #delay
	mov #1, &state 		; state = 1
	jmp end 		; break
	
case2:	mov #1, &green_on 	; green_on = 1
	mov #0, &red_on 	; red_on = 0
	mov #20, r12	 	; 2 seconds delay
	call #delay
	mov #2, &state 		; state = 2
	jmp end 		; break

case3:	mov #1, &red_on 	; red_on = 1
	mov #0, &green_on 	; green_on = 0
	mov #30, r12	 	; 3 second delay
	call #delay
	mov #3, &state 		; state = 0
	jmp end 		; break


case4:	mov #0, &red_on 	; red_on = 0
	mov #1, &green_on 	; green_on = 1
	mov #50, r12	 	; 5 second delay
	call #delay
	mov #0, &state 		; state = 0
	jmp end 		; break
	
end:	pop r0 			; return r0
	


















































	
