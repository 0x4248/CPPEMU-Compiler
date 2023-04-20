/* CPPEMU compiler 
 * A compiler for CPPEMU
 * Github: https://www.github.com/awesomelewis2007/CPPEMU-Compiler
 * License: GPL-3.0
 * By: Lewis Evans
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Please provide a file to compile" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Could not open file " << filename << endl;
        return 1;
    }

    // Read file and loop through each line
    string output = "";

    string line;
    vector<string> lines;
    while (getline(file, line))
    {
        if(line[0] == '/' && line[1] == '/')
        {
            // Comment
            continue;
        }
        else if (line == "")
        {
            // Empty line
            continue;
        }

        // SEL M   [HEX]  0x01 Select memory location with the next hex number
        // SET M   [HEX]  0x02 Put the next hex number into the selected memory location
        // ADD HM  [HEX]  0x03 Add the next hex number to the selected memory location and store the result in the selected memory location
        // SUB HM  [HEX]  0x04 Subtract the next hex number from the selected memory location and store the result in the selected memory location
        // MUL HM  [HEX]  0x05 Multiply the selected memory location by the next hex number and store the result in the selected memory location
        // DIV HM  [HEX]  0x06 Divide the selected memory location by the next hex number and store the result in the selected memory location

        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'L' && line[3] == ' ' && line[4] == 'M')
        {
            //SEL M [HEX]  0x00 Select the memory location specified by the next hex number
            string hex = line.substr(6, 2);
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'M')
        {
            //SET M [HEX]  0x10 Set the selected memory location to the next hex number
            string hex = line.substr(6, 2);
            output += "02";
            output += hex;
        }
        else if (line[0] == 'A' && line[1] == 'D' && line[2] == 'D' && line[3] == ' ' && line[4] == 'H' && line[5] == 'M')
        {
            //ADD HM [HEX]  0x8A Add the value of the selected memory location to the value of register A and store the result in register A
            string hex = line.substr(7, 2);
            output += "03";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'U' && line[2] == 'B' && line[3] == ' ' && line[4] == 'H' && line[5] == 'M')
        {
            //SUB HM [HEX]  0x9A Subtract the value of the selected memory location from the value of register A and store the result in register A
            string hex = line.substr(7, 2);
            output += "04";
            output += hex;
        }
        else if (line[0] == 'M' && line[1] == 'U' && line[2] == 'L' && line[3] == ' ' && line[4] == 'H' && line[5] == 'M')
        {
            //MUL HM [HEX]  0x8A Multiply the value of the selected memory location by the value of register A and store the result in register A
            string hex = line.substr(7, 2);
            output += "05";
            output += hex;
        }
        else if (line[0] == 'D' && line[1] == 'I' && line[2] == 'V' && line[3] == ' ' && line[4] == 'H' && line[5] == 'M')
        {
            //DIV HM [HEX]  0x8A Divide the value of register A by the value of the selected memory location and store the result in register A
            string hex = line.substr(7, 2);
            output += "06";
            output += hex;
        }

        // SET A   [HEX]  0x1A Set register A to the next hex number
        // SET B   [HEX]  0x1B Set register B to the next hex number
        // SET C   [HEX]  0x1C Set register C to the next hex number
        // SET D   [HEX]  0x1D Set register D to the next hex number

        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'A')
        {
            //SET A [HEX]  0x1A Set register A to the next hex number
            string hex = line.substr(6, 2);
            output += "1A";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'B')
        {
            //SET B [HEX]  0x1B Set register B to the next hex number
            string hex = line.substr(6, 2);
            output += "1B";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'C')
        {
            //SET C [HEX]  0x1C Set register C to the next hex number
            string hex = line.substr(6, 2);
            output += "1C";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'D')
        {
            //SET D [HEX]  0x1D Set register D to the next hex number
            string hex = line.substr(6, 2);
            output += "1D";
            output += hex;
        }
        // SET AM  [HEX]  0x2A Set register A to the selected memory location
        // SET BM  [HEX]  0x2B Set register B to the selected memory location
        // SET CM  [HEX]  0x2C Set register C to the selected memory location
        // SET DM  [HEX]  0x2D Set register D to the selected memory location
        
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'A' && line[5] == 'M')
        {
            //SET AM [HEX]  0x2A Set register A to the selected memory location
            string hex = line.substr(7, 2);
            output += "2A";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'B' && line[5] == 'M')
        {
            //SET BM [HEX]  0x2B Set register B to the selected memory location
            string hex = line.substr(7, 2);
            output += "2B";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'C' && line[5] == 'M')
        {
            //SET CM [HEX]  0x2C Set register C to the selected memory location
            string hex = line.substr(7, 2);
            output += "2C";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'D' && line[5] == 'M')
        {
            //SET DM [HEX]  0x2D Set register D to the selected memory location
            string hex = line.substr(7, 2);
            output += "2D";
            output += hex;
        }

        // SET MA  [HEX]  0x3A Set the selected memory location to the value of register A
        // SET MB  [HEX]  0x3B Set the selected memory location to the value of register B
        // SET MC  [HEX]  0x3C Set the selected memory location to the value of register C
        // SET MD  [HEX]  0x3D Set the selected memory location to the value of register D

        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'M' && line[5] == 'A')
        {
            //SET MA [HEX]  0x3A Set the selected memory location to the value of register A
            string hex = line.substr(7, 2);
            output += "3A";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'M' && line[5] == 'B')
        {
            //SET MB [HEX]  0x3B Set the selected memory location to the value of register B
            string hex = line.substr(7, 2);
            output += "3B";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'M' && line[5] == 'C')
        {
            //SET MC [HEX]  0x3C Set the selected memory location to the value of register C
            string hex = line.substr(7, 2);
            output += "3C";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'E' && line[2] == 'T' && line[3] == ' ' && line[4] == 'M' && line[5] == 'D')
        {
            //SET MD [HEX]  0x3D Set the selected memory location to the value of register D
            string hex = line.substr(7, 2);
            output += "3D";
            output += hex;
        }

        // ADD AM  [HEX]  0x4A Add the value of register A to the selected memory location and store the result in the selected memory location
        // ADD BM  [HEX]  0x4B Add the value of register B to the selected memory location and store the result in the selected memory location
        // ADD CM  [HEX]  0x4C Add the value of register C to the selected memory location and store the result in the selected memory location
        // ADD DM  [HEX]  0x4D Add the value of register D to the selected memory location and store the result in the selected memory location

        else if (line[0] == 'A' && line[1] == 'D' && line[2] == 'D' && line[3] == ' ' && line[4] == 'A' && line[5] == 'M')
        {
            //ADD AM [HEX]  0x4A Add the value of register A to the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "4A";
            output += hex;
        }
        else if (line[0] == 'A' && line[1] == 'D' && line[2] == 'D' && line[3] == ' ' && line[4] == 'B' && line[5] == 'M')
        {
            //ADD BM [HEX]  0x4B Add the value of register B to the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "4B";
            output += hex;
        }
        else if (line[0] == 'A' && line[1] == 'D' && line[2] == 'D' && line[3] == ' ' && line[4] == 'C' && line[5] == 'M')
        {
            //ADD CM [HEX]  0x4C Add the value of register C to the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "4C";
            output += hex;
        }
        else if (line[0] == 'A' && line[1] == 'D' && line[2] == 'D' && line[3] == ' ' && line[4] == 'D' && line[5] == 'M')
        {
            //ADD DM [HEX]  0x4D Add the value of register D to the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "4D";
            output += hex;
        }

        // SUB AM  [HEX]  0x5A Subtract the value of register A from the selected memory location and store the result in the selected memory location
        // SUB BM  [HEX]  0x5B Subtract the value of register B from the selected memory location and store the result in the selected memory location
        // SUB CM  [HEX]  0x5C Subtract the value of register C from the selected memory location and store the result in the selected memory location
        // SUB DM  [HEX]  0x5D Subtract the value of register D from the selected memory location and store the result in the selected memory location

        else if (line[0] == 'S' && line[1] == 'U' && line[2] == 'B' && line[3] == ' ' && line[4] == 'A' && line[5] == 'M')
        {
            //SUB AM [HEX]  0x5A Subtract the value of register A from the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "5A";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'U' && line[2] == 'B' && line[3] == ' ' && line[4] == 'B' && line[5] == 'M')
        {
            //SUB BM [HEX]  0x5B Subtract the value of register B from the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "5B";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'U' && line[2] == 'B' && line[3] == ' ' && line[4] == 'C' && line[5] == 'M')
        {
            //SUB CM [HEX]  0x5C Subtract the value of register C from the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "5C";
            output += hex;
        }
        else if (line[0] == 'S' && line[1] == 'U' && line[2] == 'B' && line[3] == ' ' && line[4] == 'D' && line[5] == 'M')
        {
            //SUB DM [HEX]  0x5D Subtract the value of register D from the selected memory location and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "5D";
            output += hex;
        }

        // MUL AM  [HEX]  0x6A Multiply the selected memory location by the value of register A and store the result in the selected memory location
        // MUL BM  [HEX]  0x6B Multiply the selected memory location by the value of register B and store the result in the selected memory location
        // MUL CM  [HEX]  0x6C Multiply the selected memory location by the value of register C and store the result in the selected memory location
        // MUL DM  [HEX]  0x6D Multiply the selected memory location by the value of register D and store the result in the selected memory location

        else if (line[0] == 'M' && line[1] == 'U' && line[2] == 'L' && line[3] == ' ' && line[4] == 'A' && line[5] == 'M')
        {
            //MUL AM [HEX]  0x6A Multiply the selected memory location by the value of register A and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "6A";
            output += hex;
        }
        else if (line[0] == 'M' && line[1] == 'U' && line[2] == 'L' && line[3] == ' ' && line[4] == 'B' && line[5] == 'M')
        {
            //MUL BM [HEX]  0x6B Multiply the selected memory location by the value of register B and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "6B";
            output += hex;
        }
        else if (line[0] == 'M' && line[1] == 'U' && line[2] == 'L' && line[3] == ' ' && line[4] == 'C' && line[5] == 'M')
        {
            //MUL CM [HEX]  0x6C Multiply the selected memory location by the value of register C and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "6C";
            output += hex;
        }
        else if (line[0] == 'M' && line[1] == 'U' && line[2] == 'L' && line[3] == ' ' && line[4] == 'D' && line[5] == 'M')
        {
            //MUL DM [HEX]  0x6D Multiply the selected memory location by the value of register D and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "6D";
            output += hex;
        }

        // DIV AM  [HEX]  0x7A Divide the selected memory location by the value of register A and store the result in the selected memory location
        // DIV BM  [HEX]  0x7B Divide the selected memory location by the value of register B and store the result in the selected memory location
        // DIV CM  [HEX]  0x7C Divide the selected memory location by the value of register C and store the result in the selected memory location
        // DIV DM  [HEX]  0x7D Divide the selected memory location by the value of register D and store the result in the selected memory location

        else if (line[0] == 'D' && line[1] == 'I' && line[2] == 'V' && line[3] == ' ' && line[4] == 'A' && line[5] == 'M')
        {
            //DIV AM [HEX]  0x7A Divide the selected memory location by the value of register A and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "7A";
            output += hex;
        }
        else if (line[0] == 'D' && line[1] == 'I' && line[2] == 'V' && line[3] == ' ' && line[4] == 'B' && line[5] == 'M')
        {
            //DIV BM [HEX]  0x7B Divide the selected memory location by the value of register B and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "7B";
            output += hex;
        }
        else if (line[0] == 'D' && line[1] == 'I' && line[2] == 'V' && line[3] == ' ' && line[4] == 'C' && line[5] == 'M')
        {
            //DIV CM [HEX]  0x7C Divide the selected memory location by the value of register C and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "7C";
            output += hex;
        }
        else if (line[0] == 'D' && line[1] == 'I' && line[2] == 'V' && line[3] == ' ' && line[4] == 'D' && line[5] == 'M')
        {
            //DIV DM [HEX]  0x7D Divide the selected memory location by the value of register D and store the result in the selected memory location
            string hex = line.substr(7, 2);
            output += "7D";
            output += hex;
        }

        // HALT    0xAA Stop the program
        // PRN M   0xAB Print the value of the selected memory location
        // PRN A   0xBA Print the value of register A
        // PRN B   0xBB Print the value of register B
        // PRN C   0xBC Print the value of register C
        // PRN D   0xBD Print the value of register D

        else if (line[0] == 'H' && line[1] == 'A' && line[2] == 'L' && line[3] == 'T')
        {
            //HALT    0xAA Stop the program
            output += "AA";
        }
        else if (line[0] == 'P' && line[1] == 'R' && line[2] == 'N' && line[3] == ' ' && line[4] == 'M')
        {
            //PRN M   0xAB Print the value of the selected memory location
            string hex = line.substr(6, 2);
            output += "AB";
            output += hex;
        }
        else if (line[0] == 'P' && line[1] == 'R' && line[2] == 'N' && line[3] == ' ' && line[4] == 'A')
        {
            //PRN A   0xBA Print the value of register A
            output += "BA";
        }
        else if (line[0] == 'P' && line[1] == 'R' && line[2] == 'N' && line[3] == ' ' && line[4] == 'B')
        {
            //PRN B   0xBB Print the value of register B
            output += "BB";
        }
        else if (line[0] == 'P' && line[1] == 'R' && line[2] == 'N' && line[3] == ' ' && line[4] == 'C')
        {
            //PRN C   0xBC Print the value of register C
            output += "BC";
        }
        else if (line[0] == 'P' && line[1] == 'R' && line[2] == 'N' && line[3] == ' ' && line[4] == 'D')
        {
            //PRN D   0xBD Print the value of register D
            output += "BD";
        }
    }
    cout << output << endl;
    return 0;
}
