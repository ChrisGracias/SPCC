#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    char label[10], operand[10], opcode[10], mneumonic[10];
    int locctr = 0;

    FILE *fp1, *fp2, *fp3, *fp4;

    fp1 = fopen("/Users/vigneshrk/Desktop/spcc/7/input.txt", "r");
    fp2 = fopen("/Users/vigneshrk/Desktop/spcc/7/mot.txt", "r");
    fp3 = fopen("/Users/vigneshrk/Desktop/spcc/7/out.txt", "w");
    fp4 = fopen("/Users/vigneshrk/Desktop/spcc/7/st.txt", "w");

    // Check if file opening is successful
    if (fp1 == NULL || fp2 == NULL || fp3 == NULL || fp4 == NULL) {
        printf("Error opening files.\n");
        return 1; // Exit with error code
    }

    // Reading data from fp1 and writing to fp3
    fscanf(fp1, "%s %s %s", label, opcode, operand);
    fprintf(fp3, "%s %s %s %s\n", locctr, label, opcode, operand);

    // Loop until opcode is "END"
    while (strcmp(opcode, "END") != 0) {
        // Condition for opcodes "DS" and "DC"
        if (strcmp(opcode, "DS") == 0 || strcmp(opcode, "DC") == 0) {
            fprintf(fp4, "%s %d\n", label, locctr);
            locctr += 4; // Update locctr assuming each instruction takes 4 memory locations
        } else {
            // Reading from fp2 (MOT file)
            while (fscanf(fp2, "%s", mneumonic) != EOF) {
                // If opcode matches mneumonic, update locctr and break
                if (strcmp(opcode, mneumonic) == 0) {
                    locctr += 4; // Update locctr assuming each instruction takes 4 memory locations
                    break;
                }
            }
            // Reset file position indicator for fp2
            fseek(fp2, 0, SEEK_SET);
        }
        // Reading next instruction from fp1
        fscanf(fp1, "%s %s %s", label, opcode, operand);
        fprintf(fp3, "%s %s %s %s\n", locctr, label, opcode, operand);
    }

    // Close all file pointers
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0; // Indicates successful execution
}
