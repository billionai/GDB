#as:
#readelf: -x.rodata -wL
#name: DWARF2 17
# The am33 cr16 crx ft32 mn10 msp430 nds32 and rl78 targets do not evaluate the subtraction of symbols at assembly time.
# The mep target tries to relay code sections which breaks symbolic view computations.
# The riscv targets do not support the subtraction of symbols.
# The loongarch targets do not support the subtraction of symbols.
#xfail: am3*-* cr16-* crx-* ft32*-* loongarch*-* mep-* mn10*-* msp430-* nds32*-* riscv*-* rl78-*

Hex dump of section '\.rodata':
  0x00000000 00 *.*

Contents of the \.debug_line section:

CU: dwarf2-17\.c:
File name +Line number +Starting address +View  +Stmt
dwarf2-17\.c +1 +0 +x
dwarf2-17\.c +2 +0x8 +x
dwarf2-17\.c +3 +0x10 +x
dwarf2-17\.c +- +0x18
