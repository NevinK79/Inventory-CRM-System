/*
 * EE312 Simple CRM Project
 *
 * YOUR INFO HERE!
 */

#include "Invent.h"
#include "MyString.h"
#include <assert.h>
#include <stdio.h>

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

int num_books = 0;
int num_dice = 0;
int num_figures = 0;
int num_towers = 0;


/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */


/* clear the inventory and reset the customer database to empty */
void reset(void) { /* your code here */
    for(int i = 0;i<num_customers;i++){
    StringDestroy(&(customers[i].name));
    customers[i].books = 0;
    customers[i].dice = 0;
    customers[i].figures = 0;
    customers[i].towers = 0;
    }
    num_customers = 0;
    num_books = 0;
    num_dice = 0;
    num_figures = 0;
    num_towers = 0;
}

void processSummarize() {
int book_index = 0;
int dice_index = 0;
int figures_index = 0;
int towers_index = 0;
int book_max = 0;
int dice_max = 0;
int figures_max = 0;
int towers_max = 0;
for(int i  = 0;i<num_customers;i++){
    if(customers[i].books>book_max){
        book_max = customers[i].books;
        book_index = i;
    }
    if(customers[i].dice>dice_max){
        dice_max = customers[i].dice;
        dice_index = i;
    }
    if(customers[i].figures>figures_max){
        figures_max = customers[i].figures;
        figures_index = i;
    }
    if(customers[i].towers>towers_max){
        towers_max = customers[i].towers;
        towers_index = i;
    }
 }

printf("There are %d Books %d Dice %d Figures and %d Towers in inventory\n", num_books, num_dice, num_figures, num_towers);
printf("we have had a total of %d different customers\n", num_customers);
if(book_max>0){
    StringPrint(&(customers[book_index].name));
    printf(" has purchased the most Books (%d)\n", book_max);

 }
else{
    printf("no one has purchased any Books\n");
}

if(dice_max>0){
    StringPrint(&(customers[dice_index].name));
    printf(" has purchased the most Dice (%d)\n", dice_max);
}
else{
    printf("no one has purchased any Dice\n");
}

if(figures_max>0){
    StringPrint(&(customers[figures_index].name));
    printf(" has purchased the most Figures (%d)\n", figures_max);
}
else{
    printf("no one has purchased any Figures\n");
}

if(towers_max>0){
    StringPrint(&(customers[towers_index].name));
    printf(" has purchased the most Towers (%d)\n", towers_max);
}
else{
    printf("no one has purchased any Towers\n");
}

}

void processPurchase() {
    int there = 0;
    int index = 0;
    String books = StringCreate("Books");
    String dice = StringCreate("Dice");
    String figures = StringCreate("Figures");
    String towers = StringCreate("Towers");
    String name;
    String type;
    int num;
    readString(&name);
    readString(&type);
    readNum(&num);
    for(int i = 0;i<num_customers;i++){
        if(StringIsEqualTo(&name,&(customers[i].name))){
            there = 1;
            index = i;
        }
    }
    if((there !=0)&&(num>0)){
        if(StringIsEqualTo(&type, &books))
    {
        if(num_books>=num){
        customers[index].books +=num;
        num_books-=num;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_books);
            StringPrint(&type);
            printf("\n");
        }
    }
        
    else if (StringIsEqualTo(&type, &dice))
    {
        if(num_dice>=num){
        customers[index].dice +=num;
        num_dice-=num;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_dice);
            StringPrint(&type);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type, &figures))
    {
        if(num_figures>=num){
        customers[index].figures +=num;
        num_figures-=num;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_figures);
            StringPrint(&type);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type, &towers))
    {
        if(num_towers>=num){
        customers[index].towers +=num;
        num_towers-=num;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_towers);
            StringPrint(&type);
            printf("\n");
        }
    }
    
}
else if (num>0){
     if(StringIsEqualTo(&type, &books))
    {
        if(num_books>=num){
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].books =num;
        num_books-=num;
        num_customers++;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_books);
            StringPrint(&type);
            printf("\n");
        }
    }
        
    else if (StringIsEqualTo(&type, &dice))
    {
        if(num_dice>=num){
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].dice =num;
        num_dice-=num;
        num_customers++;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_dice);
            StringPrint(&type);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type, &figures))
    {
        if(num_figures>=num){
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].figures =num;
        num_figures-=num;
        num_customers++;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_figures);
            StringPrint(&type);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type, &towers))
    {
        if(num_towers>=num){
        customers[num_customers].name = StringDup(&name);
        customers[num_customers].towers =num;
        num_towers-=num;
        num_customers++;
        }
        else{
            printf("Sorry ");
            StringPrint(&name);
            printf(", we only have %d ", num_towers);
            StringPrint(&type);
            printf("\n");
        }
    }
}
StringDestroy(&type);
StringDestroy(&name);
StringDestroy(&books);
StringDestroy(&dice);
StringDestroy(&figures);
StringDestroy(&towers);

}

void processReturn() {

    int index2 = 0;
    int there = 0;
    String name2;
    String type2;
    int num2;
    readString(&name2);
    readString(&type2);
    readNum(&num2);
    String books2 = StringCreate("Books");
    String dice2 = StringCreate("Dice");
    String figures2 = StringCreate("Figures");
    String towers2 = StringCreate("Towers");

for(int i = 0;i<num_customers;i++){
        if(StringIsEqualTo(&name2,&(customers[i].name))){
            index2 = i;
            there = 1;
        }
    }
// ASK TA CAN HAVE MORE RETURN THAT PURHCASE???*********************

if(there !=0){
        if(StringIsEqualTo(&type2, &books2))
    {
        if(customers[index2].books>=num2){
        customers[index2].books -=num2;
        num_books+=num2;
        }
        else{
            StringPrint(&name2);
            printf(", you do not have %d ", num2);
            StringPrint(&type2);
            printf("\n");
        }
    }
        
    else if (StringIsEqualTo(&type2, &dice2))
    {
        if(customers[index2].dice>=num2){
        customers[index2].dice -=num2;
        num_dice+=num2;
        }
        else{
            StringPrint(&name2);
            printf(", you do not have %d ", num2);
            StringPrint(&type2);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type2, &figures2))
    {
        if(customers[index2].figures>=num2){
        customers[index2].figures -=num2;
        num_figures+=num2;
        }
        else{
            StringPrint(&name2);
            printf(", you do not have %d ", num2);
            StringPrint(&type2);
            printf("\n");
        }
    }
    else if (StringIsEqualTo(&type2, &towers2))
    {
        if(customers[index2].towers>=num2){
        customers[index2].towers -=num2;
        num_towers+=num2;
        }
        else{
            StringPrint(&name2);
            printf(", you do not have %d ", num2);
            StringPrint(&type2);
            printf("\n");
        }
    }
}
else{
    printf("Sorry ");
    StringPrint(&name2);
    printf(", we do not have you in our database\n");
}



StringDestroy(&type2);
StringDestroy(&name2);
StringDestroy(&books2);
StringDestroy(&dice2);
StringDestroy(&figures2);
StringDestroy(&towers2);

}

void processInventory() {
String type;
int num;
readString(&type);
readNum(&num);
String books = StringCreate("Books");
String dice = StringCreate("Dice");
String figures = StringCreate("Figures");
String towers = StringCreate("Towers");
if(StringIsEqualTo(&type, &books))
{
num_books+=num;

}
else if (StringIsEqualTo(&type, &dice))
{
num_dice+=num;
}
else if (StringIsEqualTo(&type, &figures))
{
num_figures+=num;
}
else if (StringIsEqualTo(&type, &towers))
{
num_towers+=num;
}

StringDestroy(&type);
StringDestroy(&books);
StringDestroy(&dice);
StringDestroy(&figures);
StringDestroy(&towers);

}
