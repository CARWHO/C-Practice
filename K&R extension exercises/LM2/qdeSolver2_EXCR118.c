#include <stdio.h> 
#include <math.h>

void printRoots(float a, float b, float c)

{
        // check edge cases // ----------------------------------------------------------------------

        float discriminant = (b * b) - 4 * a * c;

        if (discriminant < 0) {
            printf("Imaginary roots");
            return;
        }
        if (a == 0) {
            printf("Not a quadratic");
            return;
        }

        // find root1 and root2 // ------------------------------------------------------------------

        float root1, root2;
            root1 = (-b + sqrt((b*b) - 4 * a * c)) / (2 * a);
            root2 = (-b - sqrt((b*b) - 4 * a * c)) / (2 * a);

            if (root1 > root2) {
                float temp;
                temp = root1;
                root1 = root2;
                root2 = temp;

            }

            printf("Roots are %.4f and %.4f", root1, root2);
        }
        
        // print roots // ------------------------------------------------------------------

       
    


