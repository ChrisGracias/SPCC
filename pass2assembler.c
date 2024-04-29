#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char label[10], opcode[10], operand[10], locctr[10], mlabel[10], mneumonic[10];
    
    FILE *fp1, *fp2, *fp3, *fp4, *fp5;

    // Open input and output files
    fp1 = fopen("/Users/vigneshrk/Desktop/spcc/7.2/input.txt", "r");
    fp2 = fopen("/Users/vigneshrk/Desktop/spcc/7.2/mot.txt", "r");
    fp3 = fopen("/Users/vigneshrk/Desktop/spcc/7.2/output.txt", "r");
    fp4 = fopen("/Users/vigneshrk/Desktop/spcc/7.2/output.txt", "w");
    fp5 = fopen("/Users/vigneshrk/Desktop/spcc/7.2/BT.txt", "w");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL || fp5 == NULL) {
        printf("Error opening files.\n");
        return 1; // Exit with error code
    }

    // Read data from fp3 and write to fp5
    fscanf(fp3, "%s %s %s", label, opcode, operand);
    fscanf(fp3, "%s %s %s", label, opcode, operand);
    fprintf(fp5, "Y %c%c", operand[2], operand[3]);

    // Loop until opcode is "END"
    while (strcmp(opcode, "END") != 0) {
        // Condition for opcode "DC"
        if (strcmp(opcode, "DC") == 0) {
            fprintf(fp4, "%s \t%c\n", locctr, operand[2]);
        }
        // Condition for opcode "DS"
        else if (strcmp(opcode, "DS") == 0) {
            fprintf(fp4, "%s\n", locctr);
        }
        else {
            // Read from fp2 (MOT file)
            while (fscanf(fp2, "%s %s", mneumonic, mlabel) != EOF) {
                if (strcmp(opcode, mneumonic) == 0) {
                    fprintf(fp4, "%s\t%s\n", mlabel, operand);
                    break;
                }
            }
            // Reset file position indicator for fp2
            fseek(fp2, 0, SEEK_SET);
        }
        // Read next instruction from fp3
        fscanf(fp3, "%s %s %s %s", locctr, label, opcode, operand);
    }

    // Close all file pointers
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);
    fclose(fp5);

    return 0; // Indicates successful execution
}
