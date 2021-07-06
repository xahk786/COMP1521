# read a mark and print the corresponding UNSW grade

main:
    la   $a0, prompt    # printf("Enter a mark: ");
    li   $v0, 4
    syscall

    li   $v0, 5         # scanf("%d", mark);
    syscall

    blt $v0, 50, fail
    blt $v0, 65, pass
    blt $v0, 75, credit
    blt $v0, 85, distinction
    ble $v0, 100, high_dist

    jr   $ra            # return

fail:
    la   $a0, fl        # printf("FL\n");
    li   $v0, 4
    syscall
    jr		$ra					# jump to $ra
    
pass:
    la   $a0, ps        # printf("FL\n");
    li   $v0, 4
    syscall
    jr		$ra					# jump to $ra

credit:
    la   $a0, cr        # printf("FL\n");
    li   $v0, 4
    syscall
    jr		$ra					# jump to $ra

distinction:
    la   $a0, dn        # printf("FL\n");
    li   $v0, 4
    syscall
    jr		$ra					# jump to $ra

high_dist:
    la   $a0, hd        # printf("FL\n");
    li   $v0, 4
    syscall
    jr		$ra					# jump to $ra
    

    .data
prompt:
    .asciiz "Enter a mark: "
fl:
    .asciiz "FL\n"
ps:
    .asciiz "PS\n"
cr:
    .asciiz "CR\n"
dn:
    .asciiz "DN\n"
hd:
    .asciiz "HD\n"
