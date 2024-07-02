#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 20 /* max size of operand, operator */
#define NUMBER '0' /* signal that number found */
#define TOOBIG '9' /* signal that string is too big */
#define MAXVAL 100 /* max depth of input (value) stack */


    int sp = 0;
    double val[MAXVAL];

    void push(double f) {
          if (sp < MAXVAL) {
            val[sp++] = f;
          }
          else
            printf("Stack overflow, **SP>MAXVAL");

    }

    double pop() {
    if (sp > 0)
      return val[--sp];
    else {
      printf("Empty Stack **SP<=0");
      return 0.0;
    }
}

    void clear() /* clear stack */
    {
      sp = 0;
    }

    int getop(char s[], char numeric_expression[], int *index) {
        int i = 0;
        char c;
        
          while ((s[0] = c = numeric_expression[(*index)++]) == ' ' || c == '\t') { // Skip white space
          ;
          }

          if (c == '\n' || c == '\0') { // If we've reached the end of the string, return EOF
          return EOF;

          }

          s[1] = '\0';

          if (!isdigit(c) && c != '.') { // find operators
              return c;
          } 

          i = 0;
          if (isdigit(c) || c == '.') { // Collect the integer and fractional part
            while (isdigit(s[++i] = c = numeric_expression[(*index)++]) || c == '.') {
              ;
              }

          (*index)--; // Step back to the last valid character
              }

        s[i] = '\0';

    return NUMBER;
    }

void calculator (char * numeric_expression) {  /* reverse Polish desk calculator */
  int type;
  char s[MAXOP];
  double op2, atof();
  int index = 0;

  while ((type = getop(s, numeric_expression, &index)) != EOF)
    switch (type) {

      case NUMBER:
          push(atof(s));
          break;
      case '+':
          push(pop() + pop());
          break;
      case '*':
          push(pop() * pop());
          break;
      case '-':
          op2 = pop();
          push(pop() - op2);
          break;
      case '/':
          op2 = pop();
          if (op2 != 0.0)
            push(pop() / op2);
          else
            printf("zero divisor popped\n");
          break;
      case '=':
          printf("\t%f\n", pop());
          break;
      case 'c':
          clear();
          break;
      case TOOBIG:
          printf("%.20s ... is too long\n", s);
          break;
      default:
          printf("unknown command %c\n", type);
          break;
      }

          if (sp > 0) {
        printf("Final result: %f\n", val[sp-1]);
          }
  }



int main() {

  char numeric_expression[1000]; 

  printf("I am a calculator. Please input a maths function: ");
  fgets(numeric_expression, sizeof(numeric_expression), stdin);
  calculator(numeric_expression);
  
}