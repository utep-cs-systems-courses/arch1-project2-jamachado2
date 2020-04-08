#include <msp430.h>
#include "blink.h"
#include "switches.h"
#include "stateMachines.h"
#include "toggle_red_assembly.h"
#include "led.h"	


		.arch msp430g2553
		.data
state:		.word 0

		.text
jt:		/*.word default /*0*/
		.word case0   /*1*/
		.word case1   /*2*/

		.global toggle_red_assembly
toggle_red_assembly:	
		;; range check on selector (state)
		;; index into jt 
		mov &state, r12
		cmp #3, &state 	; state-3
		jnc default 	; default before
		add r12, r12 	; r12=2*state
		/* | 3 | 2 | 
		   | 1 | 0 | */
	        mov jt(r12), r0 ; jmp jt[s]
		/*mov r12(jt), r0 ; not correct syntax */

		;;switch table cases
case0:		mov #1, &red_on ; red_on = 1
		/*how to do buzzer?*/
		mov #1, &state 	; state = 1
		jmp end 	; break

case1:		mov #0, &red_on	
		/*buzzer*/
		mov #0, &state
		jmp end 	; break
	
default:	/*mov &red_on, r12
	call #toggle_green*/
		mov #0, &state
	
		jmp end
		pop r0
	
end:		pop 1 		; return 1
	
/*
		.global changed
toggle_green:   nop
changed:	.byte 0
		cmp     &0, &red_on
		jne     ch
		bis     &1, &green_on
		cmp     &1, &changed

ch:     	pop     changed

		//.global changed
state_advance:
		.data
R:		.word 0
G:		.word 1
		mov 	&G, &color

	
		/* I should change first the blink.c into goto */

	
/*		.global state
toggle_red:	nop
state:	        .byte 0
	mov     SWITCH, state	; switch(state)
	add     CASE0		; case 0:
	mov     &1, &red_on   	; red_on = 1
	mov     &1, &state	; state = 0
	//jmp     buzzer_set_period(2000, 1)
	
	add     CASE1
	mov     &0, &red_on	; red_on = 0
	mov     &0, &state	; state = 0
	//jmp     buzzer_set_period(2000, 3)

	ret     1

		.global changed
toggle_green:   nop
changed:	.byte 0
	cmp     &0, &red_on
	jne     end
	bis     &1, &green_on
	cmp     &1, &changed
end:
	ret     changed

		//.global changed
state_advance:	nop
changed:	.byte 0
/* static enum ?*/
/*	mov     &0, &R
	mov     &1, &G
	mov     &G, &color

	mov     SWITCH, color
	add     CASER
	mov     &toggle_red, &changed
	mov     &G, &color

	add     CASEG
	mov     &toggle_green, &changed
	mov     &R, &color

	jmp     lst
lst:
	mov     &changed, &led_changed
		led_update
*/
