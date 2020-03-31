		.arch msp430g2553

		.data
state:		.word 0

		.text
switch:		.word default
		.word case0
		.word case1

		.global
toggle_red:
		/* I should change first the blink.c into goto */

	
/*		.global state
toggle_red:	nop
state:	        .byte 0
	mov     SWITCH, state	; switch(state)
	add     CASE0		; case 0:
	mov     &1, &red_on   	; red_on = 1
	mov     &1, &state	; state = 0
	jmp     buzzer_set_period(2000, 1)
	
	add     CASE1
	mov     &0, &red_on	; red_on = 0
	mov     &0, &state	; state = 0
	jmp     buzzer_set_period(2000, 3)

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
