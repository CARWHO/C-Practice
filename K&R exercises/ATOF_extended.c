#include <stdio.h>
#include <string.h>
#include <math.h>

    float s_to_d(char * string) {
        
        double val, power;
        int i, sign, exp_sign, exponent;
        double converted;

        for (i=0; string[i]==' ' || string[i]=='\n' || string[i]=='\t'; i++); /* skip white space */
            sign = 1;
            if (string[i] == '+' || string[i] == '-') /* sign */
                sign = (string[i++]=='+') ? 1 : -1;

        for (val = 0; string[i] >= '0' && string[i] <= '9'; i++)
            val = 10 * val + string[i] - '0';
        if (string[i] == '.') {
            i++;
        }
            

        for (power = 1; string[i] >= '0' && string[i] <= '9'; i++) {
            val = 10 * val + string[i] - '0';
            power *= 10;
        }

        val = sign * val / power;

        if (string[i] == 'e' || string[i] == 'E') {
                i++;
                exp_sign = (string[i] == '-') ? -1 : 1;
                if (string[i] == '+' || string[i] == '-')
                    i++;
                for (exponent = 0; isdigit(string[i]); i++)
                    exponent = 10 * exponent + (string[i] - '0');
                val = val * pow(10, exp_sign * exponent);
            }

            printf("%f\n", val);
            return val;
}

int main() {

    char string[1000];
    float d;

    printf("Enter a string and I will convert it to double: ");
    scanf("%s", string);
    s_to_d(string);

} 
    
