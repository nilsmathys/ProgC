/* ------------------------------------------------------------------------------
 * title: 	SelbstStudium05				                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: Header for main.c			                -
 --------------------------------------------------------------------------------
 */

typedef struct {
    char *name;
    char *firstname;
    unsigned age;
} Person;

Person* read_person();