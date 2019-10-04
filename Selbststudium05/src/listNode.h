/* ------------------------------------------------------------------------------
 * title: 	SelbstStudium05				                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: Header for listNode.c			                -
 --------------------------------------------------------------------------------
 */

typedef struct {
    Person *content;
    void *next;
    void *previous;
} ListNode;

void* new_list();
int insert_person(Person* person, ListNode* header);
int delete_person(Person* person, ListNode* header);
void output_list(ListNode* header);
void clear_list(ListNode* header);
int compare_person(ListNode* node, Person* person2);