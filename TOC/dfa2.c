#include <stdio.h>
#include <string.h>

// DFA transition function
int transition(int currentState, char input) {
    switch (currentState) {
        case 0:
            if (input == '0') {
                return 0; 
            } else if (input == '1') {
                return 1; 
            } else {
                return -1; 
            }
        case 1:
            if (input == '0') {
                return 2; 
            } else if (input == '1') {
                return 1; 
            } else {
                return -1; 
            }
        case 2:
            if (input == '0') {
                return 0; 
            } else if (input == '1') {
                return 3; 
            } else {
                return -1; 
            }
        case 3:
                return 3; 
        default:
            return -1; 
    }
}


int isAccepted(char *input) {
    int currentState = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        currentState = transition(currentState, input[i]);
        if (currentState == -1) {
            return 0; 
        }
    }
    
    return currentState == 3;
}

int main() {
    char input[100];
    
    
    printf("Enter a binary number: ");
    scanf("%s", input);
    
    
    if (isAccepted(input)) {
        printf("Accepted\n");
    } else {
        printf("Not Accepted\n");
    }
    
    return 0;
}