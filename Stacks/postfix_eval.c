#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
// int stack
int mstack[50];
int top = -1;
 char postfix[50];
void push(int item)
{

    mstack[++top] = item;
}
char pop()
{
    return mstack[top--];
}
// evaluates postfix expression
int evaluate(char *postfix)
{
    char ch;
    int i = 0, operand1, operand2;
    while ((ch = postfix[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            push(ch - '0'); // Push the operand
        }
        else
        {
            // Operator,pop two operands
            operand2 = pop();
            operand1 = pop();

            switch (ch)
            {
            case '+':
                push(operand1 + operand2);
                break;
            case '-':
                push(operand1 - operand2);
                break;
            case '*':
                push(operand1 * operand2);
                break;
            case '/':
                push(operand1 / operand2);
                break;
            case '^':
            case '$':
                  push(pow(operand1,operand2));
            }
        }
    }
    return mstack[top];
}
void main()
{
   
    printf("Enter the postfix expression\n");
    scanf("%s",postfix);
    printf("the result=: %d\n", evaluate(postfix));
}