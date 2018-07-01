org  0x0100

; ceci est un programme affichant
; simplement "Hello World"

mov  dx, texte
mov  ah, 0x09
int  0x21      ; afficher le hello world
ret            ; fin du programme

texte: db 'Hello, World !!', 10, 13, '$'