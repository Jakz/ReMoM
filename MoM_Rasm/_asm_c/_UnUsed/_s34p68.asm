TITLE _s34p.asm 

.MODEL LARGE, C

.CODE
;segment seg034 byte public 'CODE' use16
; 	 assume cs:seg034
; 	 ;org 0Eh
; 	 assume es:nothing, ss:nothing, ds:dseg, fs:nothing, gs:nothing

PUBLIC

proc UU_GUI_GetDelay far
push bp
mov bp, sp
mov ax, [GUI_Delay]
jmp short $+2
pop bp
retf
endp UU_GUI_GetDelay

;ends seg034

end
