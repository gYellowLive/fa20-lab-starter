.globl factorial

.data
n: .word 4

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    addi a1, x0, 1 # make sure the place to store the product is intialized to 1
    # the number is already in a0
loop:
    beq a0, x0, factorial_exit
    mul a1, a0, a1
    addi a0, a0, -1
    j loop

factorial_exit:
    add a0, x0, a1
    jr ra