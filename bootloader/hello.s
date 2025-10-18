org 0x0

_start:
    jmp start     
    nop

times 33 db 0

jmp main

msgInicial: db "Digite seu nome: ", 0
ola:      db  0x0D, 0x0A, "Ola, ", 0

msgMeio: db "Seja bem vindo(a) a Casa de Apostas da Quadrinha!", 0x0D, 0x0A, "No jogo de hoje: Murilo x Nicola", 0x0D, 0x0A, "Em qual voce vai apostar hoje?", 0

msgFinalpt1:      db  "Ok, aposta feita em ", 0
msgFinalpt2:      db  "No final do dia voce recebera um sms com o resultado", 0x0D, 0x0A, "Muito Obrigado por escolher a Casa de Apostas da Quadrinha!", 0


buffer:   times 20 db 0   

print_str:
    lodsb
    call print_char
    cmp al, 0
    jnz print_str
    ret

print_char:
    mov ah, 0x0e
    int 0x10
    ret

input:
    xor cx, cx             
.read_loop:
    mov ah, 0x00            
    int 0x16
    cmp al, 13              
    je .done
    mov [si], al
    call print_char         
    inc si
    inc cx
    cmp cx, 20              
    jl .read_loop
.done:
    mov byte [si], 0        
    ret

newline:
    mov al, 0x0D
    call print_char
    mov al, 0x0A
    call print_char
    ret

start:
    jmp 0x7c0:main

main:
    cli
    mov ax, 0x7c0
    mov ds, ax
    mov es, ax
    mov ax, 0x00
    mov ss, ax
    mov sp, 0x7c00
    sti

    mov si, msgInicial
    call print_str

    mov si, buffer
    call input

    mov si, ola
    call print_str

    mov si, buffer
    call print_str

    call newline

    mov si, msgMeio
    call print_str
    
    call newline

    mov si, buffer
    call input

    call newline

    mov si, msgFinalpt1
    call print_str

    mov si, buffer
    call print_str

    call newline

    mov si, msgFinalpt2
    call print_str

    jmp $

times 510 - ($ - $$) db 0
dw 0xAA55
