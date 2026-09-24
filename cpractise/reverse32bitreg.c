/* reverse the value of a 32 bit register */

#include <stdio.h>
#include <stdint.h>
#define SETBIT(basis, bitpos) (basis |= (1 << bitpos))
#define CLRBIT(basis, bitpos) (basis &= ~(1 << bitpos))
#define CHECKBIT(basis, bitpos) (( basis >> bitpos) & 1)
#define TOGGLEBIT(basis, bitpos) \
CHECKBIT(basis, bitpos) ? CLRBIT(basis, bitpos): SETBIT(basis, bitpos)

void reversebits( uint32_t* reg)
{
    uint32_t temp= *reg;
    for (int i =0; i < sizeof(uint32_t)*8; i++)
    TOGGLEBIT(temp, i);
    *reg = temp;
}

int main() {
    uint32_t reg = 0xA5A5A5A5;
    printf("%08X\n", reg);
    reversebits(&reg);
    printf("%08X\n", reg);
    return 0;
}