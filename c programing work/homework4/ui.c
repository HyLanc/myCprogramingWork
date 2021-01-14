#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "ui.h"


void show_menu(void){
    puts("...............................................");
    puts("a: create a sequence of arithmetic problems");
    puts("b: show a sequence arithmetic problems");
    puts("c: save a sequence arithmetic problems to a file");
    puts("d: load a sequence arithmetic problems from a file");
    puts("e: add a problem to the sequence of arithmetic problems");
    puts("f: change a problem in the a sequence of arithmetic problems");
    puts("g: delete a problem from the sequence of arithmetic problems");
    puts("h: show the correct answers of the sequence of arithmetic problems");
    puts("i: create a problem of matrix multiplication problem");
    puts("j: show the correct answer of the matrix multiplication problem");
    puts("q: quit the program");
    puts("...............................................");

}


void clear_input_queue(void){
    while(getchar()!= '\n')
        continue;
}
