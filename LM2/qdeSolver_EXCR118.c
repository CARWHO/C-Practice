#include <stdint.h>
#include <math.h>

float calcRoots(float a, float b, float c) 

{
    float root1, root2;
    root1 = (-b + sqrt((b*b) - 4 * a * c)) / (2 * a);
    root2 = (-b - sqrt((b*b) - 4 * a * c)) / (2 * a);
    return root1, root2;

}

int discriminant_calc(float a, float b, float c) 

{
    float discriminant = (b * b) - 4 * a * c;
    return discriminant;
}

void printRoots(float a, float b, float c)

{
    float discriminant = discriminant_calc(a, b, c);
        if (discriminant < 0) {
            printf("Imaginary roots");
        if ('a' == 0) {
            printf("Not a quadratic");
        }

        }
        else
            float root1, root2 = calcRoots(a, b, c); 
            printf("Roots are %f and %f", root1, root2);
    
    {



    }

}

