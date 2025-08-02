#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for isdigit()

// ---- Character Stack for Infix to Postfix Conversion ----
char stack[25];
int top = -1;

void push(char item) {
    stack[++top] = item;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// ---- Integer Stack for Postfix Evaluation ----
int stack_int[25];
int top_int = -1;

void push_int(int item) {
    stack_int[++top_int] = item;
}

int pop_int() {
    return stack_int[top_int--];
}

// ---- Helper Functions ----

// Returns the precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3; // Highest precedence
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0; // For parentheses and other characters
    }
}

// ---- Core Logic Functions ----

// Converts an infix expression to a postfix expression
void convert(char infix[], char postfix[]) {
    int i = 0; // Infix scanner
    int j = 0; // Postfix writer
    char symbol;
    
    // Push a low precedence symbol onto stack to handle empty stack case
    push('#'); 

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];
        
        if (isdigit(symbol) || isalpha(symbol)) { // Check for operand
            postfix[j++] = symbol;
        } else if (symbol == '(') { // Check for opening parenthesis
            push(symbol);
        } else if (symbol == ')') { // Check for closing parenthesis
            while (stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Pop the '(' from the stack
        } else { // Operator encountered
            while (precedence(stack[top]) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    // Pop remaining operators from the stack
    while (stack[top] != '#') {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; // Null-terminate the postfix string
}

// Evaluates a postfix expression
int evaluate(char *postfix) {
    char ch;
    int i = 0;
    int operand1, operand2;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            push_int(ch - '0'); // Push the integer value of the digit
        } else {
            // Operator, pop two operands
            operand2 = pop_int();
            operand1 = pop_int();
            
            switch (ch) {
                case '+':
                    push_int(operand1 + operand2);
                    break;
                case '-':
                    push_int(operand1 - operand2);
                    break;
                case '*':
                    push_int(operand1 * operand2);
                    break;
                case '/':
                    push_int(operand1 / operand2);
                    break;
            }
        }
    }
    return stack_int[top_int];
}


// ---- Main Function ----
int main() {
    char infix[25] = "1*(2+3)";
    char postfix[25];
    
    // Reset stacks before use (good practice)
    top = -1;
    top_int = -1;

    convert(infix, postfix);
    
    printf("Infix expression is: %s\n", infix);
    printf("Postfix expression is: %s\n", postfix);
    printf("Evaluated expression is: %d\n", evaluate(postfix));
    
    return 0;
}