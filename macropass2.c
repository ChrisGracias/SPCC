#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char label[10], opcode[10], operand[10], macroname[10];
    int mntc, mdtc;
    FILE *fp1, *fp2, *fp3, *fp4;

    // Open input and output files
    fp1 = fopen("/Users/vigneshrk/Desktop/spcc/8.2/input.txt", "r");   // Input file
    fp2 = fopen("/Users/vigneshrk/Desktop/spcc/8.2/mnt.txt", "r");     // Macro Name Table file
    fp3 = fopen("/Users/vigneshrk/Desktop/spcc/8.2/mdt.txt", "r");     // Macro Definition Table file
    fp4 = fopen("/Users/vigneshrk/Desktop/spcc/8.2/output.txt", "w"); // Output file

    // Check if file opening is successful
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL) {
        printf("Error opening files.\n");
        return 1; // Exit with error code
    }

    // Initialize Macro Name Table Counter and Macro Definition Table Counter
    mntc = 1;
    mdtc = 1;

    // Read the first line from fp1
    fscanf(fp1, "%s %s %s", label, opcode, operand);

    // Loop until opcode is "END"
    while (strcmp(opcode, "END") != 0) {
        if (strcmp(opcode, "START") == 0 || strcmp(opcode, "USING") == 0 || strcmp(opcode, "DS") == 0 || strcmp(opcode, "DC") == 0) {
            // Write to output file
            fprintf(fp4, "%s %s %s\n", label, opcode, operand);
        } else {
            // Read from Macro Name Table
            fscanf(fp2, "%d %d %s", &mntc, &mdtc, macroname);
            while (!feof(fp2)) {
                if (strcmp(opcode, macroname) == 0) {
                    // Found macro name
                    break;
                }
                fscanf(fp2, "%d %d %s", &mntc, &mdtc, macroname);
            }

            if (strcmp(opcode, macroname) == 0) {
                // Macro found
                while (strcmp(macroname, "MEND") != 0) {
                    // Read and write macro definition
                    fscanf(fp3, "%s %s %s", label, opcode, operand);
                    fprintf(fp4, "%s %s %s\n", label, opcode, operand);
                    fscanf(fp3, "%d %d %s", &mntc, &mdtc, macroname);
                }
            }
        }
        // Read next line from fp1
        fscanf(fp1, "%s %s %s", label, opcode, operand);
    }

    // Write the last line to the output file
    fprintf(fp4, "%s %s %s\n", label, opcode, operand);

    // Close all file pointers
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0; // Indicates successful execution
}
