/*   Με αυτο το module μπορουμε να κανουμε swap 2 αριθμους ανεξαρτητα απο το
     type data τους    */
//   Εναλλακτικος τροπος ειναι μεσω void*

#include <stdio.h>
#include <stdbool.h>
#include "numb.h"

int main() {

    struct Number Num1,Num2;

    //Integer segment
    Num1.i = INT1;
    Num2.i = INT2;
    printf("Before swap: a=%d    b=%d\n",Num1.i,Num2.i);
    swap(&Num1,&Num2);
    printf("After swap: a=%d    b=%d\n",Num1.i,Num2.i);
    printf("\n");

    //Float segment
    Num1.f = FL1;
    Num2.f = FL2;
    printf("Before swap: a=%f    b=%f\n",Num1.f,Num2.f);
    swap(&Num1,&Num2);
    printf("After swap: a=%f    b=%f\n",Num1.f,Num2.f);
    printf("\n");

    return 0;

}