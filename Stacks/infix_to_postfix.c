#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ss 5

char infix[50], postfix[50], mstack[50];
int top = -1, j = 0;
void push(char ele)
{
    if (top == (ss - 1))
        printf("Stack Overflow\n");
    else
    {
        top++;
        mstack[top] = ele;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow\n");
    }
    else
    {
        return mstack[top--];
    }
}

void main()
{

    printf("Enter the infix expression\n");
    scanf("%s", infix);

    for (char i = 0; infix[i] != '\0'; i++)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else
        {
            switch (infix[i])
            {
            case '(':
                push(infix[i]);
                break;
            case ')':
                while (mstack[top] != '(')
                {
                    postfix[j++] = pop();
                }
                pop();
                break;

            case '$':
                push(infix[i]);
                break;
            case '/':
            case '*':
                while (mstack[top] == '$' || mstack[top] == '/' || mstack[top] == '*')
                {
                    postfix[j++] = pop();
                }
                push(infix[i]);
                break;

            case '+':
            case '-':
                while (mstack[top] == '$' || mstack[top] == '/' || mstack[top] == '*' || mstack[top] == '+' || mstack[top] == '-')
                {
                    postfix[j++] = pop();
                }
                push(infix[i]);
                break;
            }
        }
    }
    while (top != -1)
        postfix[j++] = pop();
    postfix[j] = '\0';

    printf("The postfix expression is:%s\n", postfix);
}