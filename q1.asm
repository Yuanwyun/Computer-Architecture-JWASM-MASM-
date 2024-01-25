include \masm32\include\masm32rt.inc

.data 
    N DD 7

.code

main:
    push N
    call factorial
    print str$(eax)

factorial PROC

    push ebp            ;push ebp into the stack
    mov ebp, esp        ;move the location of esp to ebp
    mov eax, [ebp+8]    ;move the location ebp move up two space to eax, now eax is N
    cmp eax, 1          ;compare eax to 1
    je L1               ;if eax is equal to 1, jump to L1
    cmp eax, 0          ;compare eax to 0
    je L2               ;if eax is equal to 0 jump to L2
    jl L3               ;if eax is less than 0 jump to L3
    dec eax             ;decrese the eax by 1, now eax is N-1
    push eax            ;push 3 into the stack
    call factorial      ;do the function again and decrease eax and push new eax into the stack 
    
L1:
    mov ebx, [ebp+8]    ;else move eax into ebx, eax=ebx=4
    mul ebx             ;multiply ebx to eax(1*1)
    pop ebp             ;clean ebp so we can use the last ebp position
    ret 4               ;return to the caller
    
L2:
    print "1", 13, 10, 0    ;print 1, eax =0
    ret 0                      ;finish the code
    
L3:
    print " Error, input must be greater or equal to 0. ", 10, 13, 0

factorial ENDP


end main


