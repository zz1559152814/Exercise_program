#include <stdio.h>

int main( void )
{
    int i; /* outer counter */
    int j; /* inner counter */ int number; /* current number */

    printf( "Enter 5 numbers between 1 and 30: " );
    /* loop 5 times */
    for ( i = 1; i <= 5; i++ )
    {
        scanf( "%d", &number );

        /* print asterisks corresponding to current input */
        for ( j = 1; j <= number; j++ )
        {
            printf( "*" );
        } /* end for */

        printf( "\n" );
    } /* end for */

    return 0; /* indicate successful termination */

}
