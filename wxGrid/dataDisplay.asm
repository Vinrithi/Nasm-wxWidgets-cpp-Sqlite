; Disassembly of file: dataDisplay.o
; Sun Nov 27 13:38:16 2016
; Mode: 64 bits
; Syntax: YASM/NASM
; Instruction set: 80386, x64

default rel

extern DataArr
global retrieveData

extern __stack_chk_fail                                 ; near
extern sqlite3_finalize                                 ; near
extern sqlite3_step                                     ; near
extern sqlite3_column_text                              ; near
extern sqlite3_column_int                               ; near
extern sqlite3_prepare_v2                               ; near
extern strcpy                                           ; near
extern sqlite3_errmsg                                   ; near
extern sqlite3_close                                    ; near
extern sqlite3_open                                     ; near


SECTION .text  
retrieveData:; Function begin
        push    rbp                                     ; 0000 _ 55
        mov     rbp, rsp                                ; 0001 _ 48: 89. E5
        sub     rsp, 48                                 ; 0004 _ 48: 83. EC, 30
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
        mov     rax, qword [fs:abs 28H]                 ; 0008 _ 64 48: 8B. 04 25, 00000028
        mov     qword [rbp-8H], rax                     ; 0011 _ 48: 89. 45, F8
        xor     eax, eax                                ; 0015 _ 31. C0
        mov     dword [rbp-2CH], 0                      ; 0017 _ C7. 45, D4, 00000000
        lea     rax, [rbp-28H]                          ; 001E _ 48: 8D. 45, D8
        mov     rsi, rax                                ; 0022 _ 48: 89. C6
        mov     edi, ?_006                              ; 0025 _ BF, 00000000(d)
        call    sqlite3_open                            ; 002A _ E8, 00000000(rel)
        test    eax, eax                                ; 002F _ 85. C0
        jz      ?_001                                   ; 0031 _ 74, 2F
        mov     rax, qword [rbp-28H]                    ; 0033 _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 0037 _ 48: 89. C7
        call    sqlite3_close                           ; 003A _ E8, 00000000(rel)
        mov     rax, qword [rbp-28H]                    ; 003F _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 0043 _ 48: 89. C7
        call    sqlite3_errmsg                          ; 0046 _ E8, 00000000(rel)
        mov     rsi, rax                                ; 004B _ 48: 89. C6
        mov     edi, DataArr+134H                       ; 004E _ BF, 00000000(d)
        call    strcpy                                  ; 0053 _ E8, 00000000(rel)
        mov     eax, 4294967295                         ; 0058 _ B8, FFFFFFFF
        jmp     ?_004                                   ; 005D _ E9, 00000189

?_001:  mov     qword [rbp-10H], ?_007                 
        mov     rax, qword [rbp-28H]                    ; 006A _ 48: 8B. 45, D8
        lea     rcx, [rbp-18H]                          ; 006E _ 48: 8D. 4D, E8
        lea     rdx, [rbp-20H]                          ; 0072 _ 48: 8D. 55, E0
        mov     rsi, qword [rbp-10H]                    ; 0076 _ 48: 8B. 75, F0
        mov     r8, rcx                                 ; 007A _ 49: 89. C8
        mov     rcx, rdx                                ; 007D _ 48: 89. D1
        mov     edx, 128                                ; 0080 _ BA, 00000080
        mov     rdi, rax                                ; 0085 _ 48: 89. C7
        call    sqlite3_prepare_v2                      ; 0088 _ E8, 00000000(rel)
        test    eax, eax                                ; 008D _ 85. C0
        je      ?_003                                   ; 008F _ 0F 84, 00000126
        mov     rax, qword [rbp-28H]                    ; 0095 _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 0099 _ 48: 89. C7
        call    sqlite3_close                           ; 009C _ E8, 00000000(rel)
        mov     rax, qword [rbp-28H]                    ; 00A1 _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 00A5 _ 48: 89. C7
        call    sqlite3_errmsg                          ; 00A8 _ E8, 00000000(rel)
        mov     rsi, rax                                ; 00AD _ 48: 89. C6
        mov     edi, DataArr+134H                       ; 00B0 _ BF, 00000000(d)
        call    strcpy                                  ; 00B5 _ E8, 00000000(rel)
        mov     eax, 4294967295                         ; 00BA _ B8, FFFFFFFF
        jmp     ?_004                                   ; 00BF _ E9, 00000127

?_002:  mov     rax, qword [rbp-20H]                    ; 00C4 _ 48: 8B. 45, E0
        mov     esi, 0                                  ; 00C8 _ BE, 00000000
        mov     rdi, rax                                ; 00CD _ 48: 89. C7
        call    sqlite3_column_int                      ; 00D0 _ E8, 00000000(rel)
        mov     edx, eax                                ; 00D5 _ 89. C2
        mov     eax, dword [rbp-2CH]                    ; 00D7 _ 8B. 45, D4
        cdqe                                            ; 00DA _ 48: 98
        imul    rax, rax, 1308                          ; 00DC _ 48: 69. C0, 0000051C
        add     rax, DataArr                            ; 00E3 _ 48: 05, 00000000(d)
        mov     dword [rax], edx                        ; 00E9 _ 89. 10
        mov     rax, qword [rbp-20H]                    ; 00EB _ 48: 8B. 45, E0
        mov     esi, 1                                  ; 00EF _ BE, 00000001
        mov     rdi, rax                                ; 00F4 _ 48: 89. C7
        call    sqlite3_column_text                     ; 00F7 _ E8, 00000000(rel)
        mov     rdx, rax                                ; 00FC _ 48: 89. C2
        mov     eax, dword [rbp-2CH]                    ; 00FF _ 8B. 45, D4
        cdqe                                            ; 0102 _ 48: 98
        imul    rax, rax, 1308                          ; 0104 _ 48: 69. C0, 0000051C
        add     rax, DataArr                            ; 010B _ 48: 05, 00000000(d)
        add     rax, 4                                  ; 0111 _ 48: 83. C0, 04
        mov     rsi, rdx                                ; 0115 _ 48: 89. D6
        mov     rdi, rax                                ; 0118 _ 48: 89. C7
        call    strcpy                                  ; 011B _ E8, 00000000(rel)
        mov     rax, qword [rbp-20H]                    ; 0120 _ 48: 8B. 45, E0
        mov     esi, 2                                  ; 0124 _ BE, 00000002
        mov     rdi, rax                                ; 0129 _ 48: 89. C7
        call    sqlite3_column_text                     ; 012C _ E8, 00000000(rel)
        mov     rdx, rax                                ; 0131 _ 48: 89. C2
        mov     eax, dword [rbp-2CH]                    ; 0134 _ 8B. 45, D4
        cdqe                                            ; 0137 _ 48: 98
        imul    rax, rax, 1308                          ; 0139 _ 48: 69. C0, 0000051C
        add     rax, 96                                 ; 0140 _ 48: 83. C0, 60
        add     rax, DataArr                            ; 0144 _ 48: 05, 00000000(d)
        add     rax, 8                                  ; 014A _ 48: 83. C0, 08
        mov     rsi, rdx                                ; 014E _ 48: 89. D6
        mov     rdi, rax                                ; 0151 _ 48: 89. C7
        call    strcpy                                  ; 0154 _ E8, 00000000(rel)
        mov     rax, qword [rbp-20H]                    ; 0159 _ 48: 8B. 45, E0
        mov     esi, 3                                  ; 015D _ BE, 00000003
        mov     rdi, rax                                ; 0162 _ 48: 89. C7
        call    sqlite3_column_int                      ; 0165 _ E8, 00000000(rel)
        mov     edx, eax                                ; 016A _ 89. C2
        mov     eax, dword [rbp-2CH]                    ; 016C _ 8B. 45, D4
        cdqe                                            ; 016F _ 48: 98
        imul    rax, rax, 1308                          ; 0171 _ 48: 69. C0, 0000051C
        add     rax, DataArr+0CCH                       ; 0178 _ 48: 05, 00000000(d)
        mov     dword [rax], edx                        ; 017E _ 89. 10
        mov     rax, qword [rbp-20H]                    ; 0180 _ 48: 8B. 45, E0
        mov     esi, 4                                  ; 0184 _ BE, 00000004
        mov     rdi, rax                                ; 0189 _ 48: 89. C7
        call    sqlite3_column_text                     ; 018C _ E8, 00000000(rel)
        mov     rdx, rax                                ; 0191 _ 48: 89. C2
        mov     eax, dword [rbp-2CH]                    ; 0194 _ 8B. 45, D4
        cdqe                                            ; 0197 _ 48: 98
        imul    rax, rax, 1308                          ; 0199 _ 48: 69. C0, 0000051C
        add     rax, 208                                ; 01A0 _ 48: 05, 000000D0
        add     rax, DataArr                            ; 01A6 _ 48: 05, 00000000(d)
        mov     rsi, rdx                                ; 01AC _ 48: 89. D6
        mov     rdi, rax                                ; 01AF _ 48: 89. C7
        call    strcpy                                  ; 01B2 _ E8, 00000000(rel)
        add     dword [rbp-2CH], 1                      ; 01B7 _ 83. 45, D4, 01
?_003:  mov     rax, qword [rbp-20H]                    ; 01BB _ 48: 8B. 45, E0
        mov     rdi, rax                                ; 01BF _ 48: 89. C7
        call    sqlite3_step                            ; 01C2 _ E8, 00000000(rel)
        cmp     eax, 100                                ; 01C7 _ 83. F8, 64
        je      ?_002                                   ; 01CA _ 0F 84, FFFFFEF4
        mov     rax, qword [rbp-20H]                    ; 01D0 _ 48: 8B. 45, E0
        mov     rdi, rax                                ; 01D4 _ 48: 89. C7
        call    sqlite3_finalize                        ; 01D7 _ E8, 00000000(rel)
        mov     rax, qword [rbp-28H]                    ; 01DC _ 48: 8B. 45, D8
        mov     rdi, rax                                ; 01E0 _ 48: 89. C7
        call    sqlite3_close                           ; 01E3 _ E8, 00000000(rel)
        mov     eax, dword [rbp-2CH]                    ; 01E8 _ 8B. 45, D4
?_004:  mov     rcx, qword [rbp-8H]                     ; 01EB _ 48: 8B. 4D, F8
; Note: Address is not rip-relative
; Note: Absolute memory address without relocation
        xor     rcx, qword [fs:abs 28H]                 ; 01EF _ 64 48: 33. 0C 25, 00000028
        jz      ?_005                                   ; 01F8 _ 74, 05
        call    __stack_chk_fail                        ; 01FA _ E8, 00000000(rel)
?_005:  leave                                           ; 01FF _ C9
        ret                                             ; 0200 _ C3
; retrieveData End of function


SECTION .data                          ; section number 2, data
?_006:  
	db "Chelsea_Club.db",0,0                                                ; byte
       
?_007:  
	db "SELECT * FROM Player_Details ORDER BY PL_ID",10,0  
       

