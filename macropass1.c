#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char operand[10], opcode[10], label[10];  
    int mntc = 1, mdtc = 1;  
    FILE *fp1, *fp2, *fp3, *fp4;  

    // Opening input and output files
    fp1 = fopen("/Users/vigneshrk/Desktop/spcc/8.1/input.txt", "r");  
    fp2 = fopen("/Users/vigneshrk/Desktop/spcc/8.1/mnt.txt", "w");   
    fp3 = fopen("/Users/vigneshrk/Desktop/spcc/8.1/mdt.txt", "w");   
    fp4 = fopen("/Users/vigneshrk/Desktop/spcc/8.1/copy.txt", "w");  

    // Check if file opening is successful
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL) {
        printf("Error opening files.\n");
        return 1; // Exit with error code
    }

    // Read the first line from fp1
    fscanf(fp1, "%s %s %s", label, opcode, operand);

    // Loop until opcode is "END"
    while (strcmp(opcode, "END") != 0) {
        if (strcmp(opcode, "MACRO") == 0) {  
            // Write to MNT
            fprintf(fp2, "%s %d\n", label, mdtc);  
            mntc++;

            // Loop until opcode is "MEND"
            while (strcmp(opcode, "MEND") != 0) {
                // Write to MDT and update MDT counter
                fprintf(fp3, "%d %s %s %s\n", mdtc, label, opcode, operand);
                mdtc++;
                // Read next line from fp1
                fscanf(fp1, "%s %s %s", label, opcode, operand);
            }
        } else {  
            // Write to copy file
            fprintf(fp4, "%s %s %s\n", label, opcode, operand);
            // Read next line from fp1
            fscanf(fp1, "%s %s %s", label, opcode, operand);
        }
    }

    // Write the last line to the copy file
    fprintf(fp4, "%s %s %s\n", label, opcode, operand);

    // Close all file pointers
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0; // Indicates successful execution
}
