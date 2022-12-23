#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define ss 5

char infix[50], prefix[50], mstack[50];
int top = -1, j = 0;
void reverse(char infix[])
{
    int m = 0, n = strlen(infix) - 1;
    while (m <= n)
    {
        int temp = infix[m];
        infix[m] = infix[n];
        infix[n] = temp;
        m++;
        n--;
    }
}

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

    return mstack[top--];
}

void main()
{

    printf("Enter the infix expression\n");
    scanf("%s", infix);

    reverse(infix);

    for (char i = 0; infix[i] != '\0'; i++)
    {
        if (isalpha(infix[i]) || isdigit(infix[i]))
        {
            prefix[j++] = infix[i];
        }
        else
        {
            switch (infix[i])
            {
            case ')':
                push(infix[i]);
                break;
            case '(':
                while (mstack[top] != ')')
                {
                    prefix[j++] = pop();
                }
                pop();
                break;

            case '$':
                push(infix[i]);
                break;
            case '/':
            case '*':
                while (mstack[top] == '$')
                {
                    prefix[j++] = pop();
                }
                push(infix[i]);
                break;

            case '+':
            case '-':
                while (mstack[top] == '$' || mstack[top] == '/' || mstack[top] == '*')
                {
                    prefix[j++] = pop();
                }
                push(infix[i]);
                break;
            }
        }
    }
    while (top != -1)
        prefix[j++] = pop();
    reverse(prefix);
    prefix[j] = '\0';

    printf("The prefix expression is:%s\n", prefix);
}