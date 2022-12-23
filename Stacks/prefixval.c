#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define ss 30
double stack[ss];
int top = -1, ans = 0;

void push(int ele)
{
   if (top == ss - 1)
   {
      printf("Stack is full\n");
      return;
   }
   top++;
   stack[top] = ele;
}
int pop()
{
   int a;
   if (top == -1)
   {
      printf("Stack is empty\n");
   }
   else
   {
      a = stack[top];
      top--;
      return a;
   }
}
int evaluatePrefix(char res[20])
{

   int len = strlen(res);

   for (int j = len - 1; j >= 0; j--)
   {

      // Push operand to Stack
      // To convert res[j] to digit subtract
      // '0' from res[j].
      if (isdigit(res[j]))
         push(res[j] - '0');

      else
      {

         // Operator encountered
         // Pop two elements from Stack
         double o1 = pop();

         double o2 = pop();

         // Use switch case to operate on o1
         // and o2 and perform o1 O o2.
         switch (res[j])
         {
         case '+':
            push(o1 + o2);
            break;
         case '-':
            push(o1 - o2);
            break;
         case '*':
            push(o1 * o2);
            break;
         case '/':
            push(o1 / o2);
            break;
         case '^':
            push(pow(o1, o2));
            break;
         }
      }
   }

   return stack[top];
}
void main()
{
   char prefix[25], ele;
   int i = 0;
   printf("Enter the prefix expression\n");
   scanf("%s", prefix);
   printf("prefix expression is %s\n", prefix);
   printf("answer=%d\n", evaluatePrefix(prefix));
}