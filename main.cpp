#include <iostream>
#include <cstdlib>
#include <cctype>

// Define the maximum size of the stack
const int MAX_SIZE = 50;

class PostfixCalculator {
private:
    int stack[MAX_SIZE]; // Array to hold the stack elements
    int topIndex;        // Index of the top element in the stack
    char* expression;    // Pointer to the postfix expression

public:
    PostfixCalculator();          // Constructor to initialize the stack
    void setExpression(char* expr);  // Method to set the postfix expression
    void push(int value);            // Method to push an element onto the stack
    int pop();                       // Method to pop an element from the stack
    void calculate();                // Method to evaluate the postfix expression
    void showResult();               // Method to display the result
};

// Constructor to initialize the stack
PostfixCalculator::PostfixCalculator() {
    topIndex = -1;
}

// Method to set the postfix expression
void PostfixCalculator::setExpression(char* expr) {
    expression = expr;
}

// Method to push an element onto the stack
void PostfixCalculator::push(int value) {
    if (topIndex == MAX_SIZE - 1) {
        std::cout << "\nStack is full!";
    } else {
        topIndex++;
        stack[topIndex] = value;
    }
}

// Method to pop an element from the stack
int PostfixCalculator::pop() {
    if (topIndex == -1) {  // Fix: Check if the stack is empty
        std::cout << "\nStack is empty!";
        exit(1);
    }
    int poppedValue = stack[topIndex];
    topIndex--;
    return poppedValue;
}

// Method to evaluate the postfix expression
void PostfixCalculator::calculate() {
    int operand1, operand2, result;
    while (*expression) {
        if (*expression == ' ' || *expression == '\t') {
            expression++;
            continue;
        }
        if (isdigit(*expression)) {
            int value = *expression - '0';
            push(value);
        } else {
            operand1 = pop();
            operand2 = pop();
            switch (*expression) {
                case '+':
                    result = operand2 + operand1;
                    break;
                case '-':
                    result = operand2 - operand1;
                    break;
                case '*':
                    result = operand2 * operand1;
                    break;
                case '/':
                    result = operand2 / operand1;
                    break;
                default:
                    std::cout << "Unknown operator";
                    exit(1);
            }
            push(result);
        }
        expression++;
    }
}

// Method to display the result
void PostfixCalculator::showResult() {
    int finalResult = pop();
    std::cout << "Result is: " << finalResult;
}

int main() {
    char postfixExpression[MAX_SIZE];
    std::cout << "\nEnter the postfix expression to be evaluated: ";
    std::cin.getline(postfixExpression, MAX_SIZE);

    PostfixCalculator calculator;
    calculator.setExpression(postfixExpression);
    calculator.calculate();
    calculator.showResult();

    return 0;
}
