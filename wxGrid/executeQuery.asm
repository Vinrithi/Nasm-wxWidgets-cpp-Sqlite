extern __stack_chk_fail                                 ; external sqlite3 function for checking for errors
extern sqlite3_free                                     ; sqlite3 function to unlock database if being used elsewhere
extern sqlite3_exec                                     ; sqlite3 function to execute queries
extern sqlite3_close                                    ; sqlite3 function to close the database connection
extern strcpy                                           ; c function to copy strings between variables
extern DataArr                                          ; external structure to store and pass values between executeQuery.asm and the c++ interface
extern sqlite3_errmsg                                   ; sqlite3 function to retrive and display the error
extern sqlite3_open                                     ; sqlite3 function to open connection with the database 


SECTION .text 
global executeQuery
executeQuery:  
        push    rbp                                     ; 0000 _ 55
        mov     rbp, rsp                                ; 0001 _ 48: 89. E5
        sub     rsp, 64                                 ; 0004 _ 48: 83. EC, 40
        mov     qword [rbp-38H], rdi                    ; 0008 _ 48: 89. 7D, C8
        mov     rax, qword [fs:abs 28H]                 ; 000C _ 64 48: 8B. 04 25, 00000028
        mov     qword [rbp-8H], rax                     ; 0015 _ 48: 89. 45, F8
        xor     eax, eax                                ; 0019 _ 31. C0
        mov     byte [rbp-2DH], 0                       ; 001B _ C6. 45, D3, 00
        mov     qword [rbp-20H], 0                      ; 001F _ 48: C7. 45, E0, 00000000
        lea     rax, [rbp-28H]                          ; 0027 _ 48: 8D. 45, D8
        mov     rsi, rax                                ; 002B _ 48: 89. C6
        mov     edi, dbName                              ; 002E _ BF, 00000000(d)
        call    sqlite3_open                            ; 0033 _ E8, 00000000(rel)
        mov     dword [rbp-2CH], eax                    ; 0038 _ 89. 45, D4
        cmp     dword [rbp-2CH], 0                      ; 003B _ 83. 7D, D4, 00
        jz      doQuery                                   ; 003F _ 74, 32
        mov     rax, qword [rbp-28H]                    ; 0041 _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 0045 _ 48: 89. C7
        call    sqlite3_errmsg                          ; 0048 _ E8, 00000000(rel)
        mov     rsi, rax                                ; 004D _ 48: 89. C6
        mov     edi, DataArr+134H                       ; 0050 _ BF, 00000000(d)
        call    strcpy                                  ; 0055 _ E8, 00000000(rel)
        mov     rax, qword [rbp-28H]                    ; 005A _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 005E _ 48: 89. C7
        call    sqlite3_close                           ; 0061 _ E8, 00000000(rel)
        mov     byte [rbp-2DH], 0                       ; 0066 _ C6. 45, D3, 00
        movzx   eax, byte [rbp-2DH]                     ; 006A _ 0F B6. 45, D3
        jmp     funcReturn                                   ; 006E _ E9, 00000092

doQuery:  mov     rax, qword [rbp-38H]                    ; 0073 _ 48: 8B. 45, C8
        mov     qword [rbp-18H], rax                    ; 0077 _ 48: 89. 45, E8
        mov     qword [rbp-10H], msgQuerySuccess                  ; 007B _ 48: C7. 45, F0, 00000000(d)
        mov     rax, qword [rbp-28H]                    ; 0083 _ 48: 8B. 45, D8
        lea     rdx, [rbp-20H]                          ; 0087 _ 48: 8D. 55, E0
        mov     rsi, qword [rbp-18H]                    ; 008B _ 48: 8B. 75, E8
        mov     r8, rdx                                 ; 008F _ 49: 89. D0
        mov     ecx, 0                                  ; 0092 _ B9, 00000000
        mov     edx, 0                                  ; 0097 _ BA, 00000000
        mov     rdi, rax                                ; 009C _ 48: 89. C7
        call    sqlite3_exec                            ; 009F _ E8, 00000000(rel)
        mov     dword [rbp-2CH], eax                    ; 00A4 _ 89. 45, D4
        cmp     dword [rbp-2CH], 0                      ; 00A7 _ 83. 7D, D4, 00
        jz      querySuccess                                   ; 00AB _ 74, 33
        mov     rax, qword [rbp-20H]                    ; 00AD _ 48: 8B. 45, E0
        mov     rsi, rax                                ; 00B1 _ 48: 89. C6
        mov     edi, DataArr+134H                       ; 00B4 _ BF, 00000000(d)
        call    strcpy                                  ; 00B9 _ E8, 00000000(rel)
        mov     rax, qword [rbp-20H]                    ; 00BE _ 48: 8B. 45, E0
        mov     rdi, rax                                ; 00C2 _ 48: 89. C7
        call    sqlite3_free                            ; 00C5 _ E8, 00000000(rel)
        mov     rax, qword [rbp-28H]                    ; 00CA _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 00CE _ 48: 89. C7
        call    sqlite3_close                           ; 00D1 _ E8, 00000000(rel)
        mov     byte [rbp-2DH], 0                       ; 00D6 _ C6. 45, D3, 00
        movzx   eax, byte [rbp-2DH]                     ; 00DA _ 0F B6. 45, D3
        jmp     funcReturn                                   ; 00DE _ EB, 25

querySuccess:  mov     rax, qword [rbp-10H]                    ; 00E0 _ 48: 8B. 45, F0
        mov     rsi, rax                                ; 00E4 _ 48: 89. C6
        mov     edi, DataArr+134H                       ; 00E7 _ BF, 00000000(d)
        call    strcpy                                  ; 00EC _ E8, 00000000(rel)
        mov     byte [rbp-2DH], 1                       ; 00F1 _ C6. 45, D3, 01
        mov     rax, qword [rbp-28H]                    ; 00F5 _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 00F9 _ 48: 89. C7
        call    sqlite3_close                           ; 00FC _ E8, 00000000(rel)
        movzx   eax, byte [rbp-2DH]                     ; 0101 _ 0F B6. 45, D3
funcReturn:  mov     rcx, qword [rbp-8H]                     ; 0105 _ 48: 8B. 4D, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
        xor     rcx, qword [fs:abs 28H]                 ; 0109 _ 64 48: 33. 0C 25, 00000028
        jz      Exit                                   ; 0112 _ 74, 05
        call    __stack_chk_fail                        ; 0114 _ E8, 00000000(rel)
Exit:  leave                                           ; 0119 _ C9
        ret                                             ; 011A _ C3
; executeQuery End of function


SECTION .data                    ; section number 2, data
dbName:  
	db "Chelsea_Club.db",0,0
        
msgQuerySuccess: 
	db "Query executed successfully",10,0
       
