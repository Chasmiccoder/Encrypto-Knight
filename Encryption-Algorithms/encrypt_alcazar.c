/*
This file is responsible for taking a string and converting it to cipher-text using
the Dynamic Alcazar Algorithm.
Its explanation can be found in the README file.
*/

#include <stdio.h>

char* char_to_ascii_string( char character ) {
    /*
    This function takes a character and returns a string containing the ASCII form of that character.
    Example: input = 'a', return value = '097'
    */
    int number = (int) character;
    static char num_in_str_format[3] = "---";
    int i = 2;

    while ( number > 0 ) {
        num_in_str_format[ i-- ] = number%10 + '0';
        number = number / 10;
    }

    if (num_in_str_format[ 0 ] == '-') {
        num_in_str_format[ 0 ] = '0';
    }
    
    return num_in_str_format;
}


char* tier_one_encryption( char* message, int len_message ) {
    /*
    Converting a string to its ascii form and separating each character's ascii string by white spaces.
    Example: input = 'hi', return value = '104 105 '
    */
    char* new_message;
    char delimiter = ' ';
    int i = 0;
    
    for ( i = 0; i < len_message; i++ ) {
        //char c = message + i;
        ;

    }
    

}

int main() {
    char* demo;
    char c = 'A';
    demo = char_to_ascii_string( c );
    printf( "%s\n", demo );

    return 0;   
}
