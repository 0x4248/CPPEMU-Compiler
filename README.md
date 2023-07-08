# CPPEMU-Compiler
This is a compiler for CPPEMU. Please see the [CPPEMU repository](https://github.com/lewisevans2007/CPPEMU) for more information about the emulator.

## Instructions
There are many instructions that the emulator can execute. The instructions are as follows:
```
SEL M [HEX]  0x01 Select memory location with the next hex number
SET M [HEX]  0x02 Put the next hex number into the selected memory location
ADD HM [HEX]  0x03 Add the next hex number to the selected memory location and store the result in the selected memory location
SUB HM [HEX]  0x04 Subtract the next hex number from the selected memory location and store the result in the selected memory location
MUL HM [HEX]  0x05 Multiply the selected memory location by the next hex number and store the result in the selected memory location
DIV HM [HEX]  0x06 Divide the selected memory location by the next hex number and store the result in the selected memory location
```
```
SET A [HEX]  0x1A Set register A to the next hex number
SET B [HEX]  0x1B Set register B to the next hex number
SET C [HEX]  0x1C Set register C to the next hex number
SET D [HEX]  0x1D Set register D to the next hex number
```
```
SET AM [HEX]  0x2A Set register A to the selected memory location
SET BM [HEX]  0x2B Set register B to the selected memory location
SET CM [HEX]  0x2C Set register C to the selected memory location
SET DM [HEX]  0x2D Set register D to the selected memory location
```
```
SET MA [HEX]  0x3A Set the selected memory location to the value of register A
SET MB [HEX]  0x3B Set the selected memory location to the value of register B
SET MC [HEX]  0x3C Set the selected memory location to the value of register C
SET MD [HEX]  0x3D Set the selected memory location to the value of register D
```
```
ADD AM [HEX]  0x4A Add the value of register A to the selected memory location and store the result in the selected memory location
ADD BM [HEX]  0x4B Add the value of register B to the selected memory location and store the result in the selected memory location
ADD CM [HEX]  0x4C Add the value of register C to the selected memory location and store the result in the selected memory location
ADD DM [HEX]  0x4D Add the value of register D to the selected memory location and store the result in the selected memory location
```
```
SUB AM [HEX]  0x5A Subtract the value of register A from the selected memory location and store the result in the selected memory location
SUB BM [HEX]  0x5B Subtract the value of register B from the selected memory location and store the result in the selected memory location
SUB CM [HEX]  0x5C Subtract the value of register C from the selected memory location and store the result in the selected memory location
SUB DM [HEX]  0x5D Subtract the value of register D from the selected memory location and store the result in the selected memory location
```
```
MUL AM [HEX]  0x6A Multiply the selected memory location by the value of register A and store the result in the selected memory location
MUL BM [HEX]  0x6B Multiply the selected memory location by the value of register B and store the result in the selected memory location
MUL CM [HEX]  0x6C Multiply the selected memory location by the value of register C and store the result in the selected memory location
MUL DM [HEX]  0x6D Multiply the selected memory location by the value of register D and store the result in the selected memory location
```
```
DIV AM [HEX]  0x7A Divide the selected memory location by the value of register A and store the result in the selected memory location
DIV BM [HEX]  0x7B Divide the selected memory location by the value of register B and store the result in the selected memory location
DIV CM [HEX]  0x7C Divide the selected memory location by the value of register C and store the result in the selected memory location
DIV DM [HEX]  0x7D Divide the selected memory location by the value of register D and store the result in the selected memory location
```
```
HALT   0xAA Stop the program
PRN M  0xAB Print the value of the selected memory location
PRN A  0xBA Print the value of register A
PRN B  0xBB Print the value of register B
PRN C  0xBC Print the value of register C
PRN D  0xBD Print the value of register D
```
Other instructions
```
//    Comment
```

## Example
Here is an example program that adds 2 numbers together and prints the result:
```
SET A 01
SEL M 00
SET M 01
ADD AM 01
HALT
```
The program is compiled to the following hex:
```
1A010002014A01AA
```

## Licence

This project is licensed under the GPL-3.0 License - see the [LICENCE](LICENCE) file for details