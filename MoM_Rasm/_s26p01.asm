TITLE _s26p01.asm VGA_SetDirectDraw
; ST_VGA.H

.MODEL LARGE, C

EXTRN g_DrawScreenPage_SgmtAddr:WORD
EXTRN g_RenderScreenPage:WORD

.CODE
;segment seg026 byte public 'CODE' use16
;    assume cs:seg026
;    ;org 0Ah
;    assume es:nothing, ss:nothing, ds:dseg, fs:nothing, gs:nothing

PUBLIC VGA_SetDirectDraw

proc VGA_SetDirectDraw
    
    mov ax, [g_RenderScreenPage]
    mov ah, al
    xor al, al
    shl ax, 1
    shl ax, 1
    add ax, 0A000h                          ; e_GRAPHICS_MODE_VIDEO_RAM
    mov [g_DrawScreenPage_SgmtAddr], ax
    ret

endp VGA_SetDirectDraw

;ends seg026

end
