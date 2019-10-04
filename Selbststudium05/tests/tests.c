/* ------------------------------------------------------------------------------
 * title: 	test selbststudium05			                	-
 * author:  Nils Mathys				      	-
 * date:    29.09.2019				                        -
 * description: test for selbststudium05		                -
 --------------------------------------------------------------------------------
 */

#include <stdio.h>
#include <stdlib.h>
#include "CUnit/Basic.h"
#include "test_utils.h"

#ifndef TARGET 
#error missing TARGET define
#endif

#define OUTFILE "stdout.txt"
#define ERRFILE "stderr.txt"


static int setup(void)
{
remove_file_if_exists(OUTFILE);
remove_file_if_exists(ERRFILE);
return 0; 
}

static int teardown(void)
{
return 0; 
}

typedef struct {char *name;
char *firstname;
unsigned age;} Person;

typedef struct {
Person *content;
void *next;
void *previous;
} ListNode;

int insertPerson(Person* person, ListNode* header);
int deletePerson(Person* person, ListNode* header);
void outputList(ListNode* header);
void clearList(ListNode* header);
int comparePerson(ListNode* node, Person* person2);
void* newList();

static void test_main_with_equal(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=25;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),0);}


static void test_main_with_smaler_by_name(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=25;
Person *p2;
p2->name="b";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),-1);}

static void test_main_with_smaler_by_firstname(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="a";
p1->age=25;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),-1);}

static void test_main_with_smaler_by_age(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=24;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),-1);}

static void test_main_with_biger_by_name(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="c";
p1->firstname="b";
p1->age=25;
Person *p2;
p2->name="b";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),1);}

static void test_main_with_biger_by_firstname(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="c";
p1->age=25;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),1);}

static void test_main_with_biger_by_age(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=26;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p2),1);}

static void test_main_insert_Person(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=26;
CU_ASSERT_EQUAL(insertPerson(p1,listNode),1);
CU_ASSERT(listNode->next==listNode->previous);
CU_ASSERT(listNode->next!=listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p1),0);}

static void test_main_remove_false(void)
{ListNode *listNode=newList();
Person *p1;
p1->name="a";
p1->firstname="b";
p1->age=26;
Person *p2;
p2->name="a";
p2->firstname="b";
p2->age=25;
insertPerson(p1,listNode);
CU_ASSERT_EQUAL(comparePerson(listNode->next,p1),0);
CU_ASSERT_EQUAL(deletePerson(p2,listNode),0);}

int main(void)
{
TestMainBasic("LinkedList", setup, teardown
,test_main_with_equal
,test_main_with_smaler_by_name
,test_main_with_smaler_by_firstname
,test_main_with_smaler_by_age
,test_main_with_biger_by_name
,test_main_with_biger_by_firstname
,test_main_with_biger_by_age
,test_main_insert_Person
,test_main_remove_false
);
}