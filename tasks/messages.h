#ifndef MESSAGES_H
#define MESSAGES_H

#define WELCOME_MESSAGE \
  "This program allows you to test 4 tasks of Project#3.\n\n\n" \
  "Author: Ilya Khin\n" \
  "Basics of programming | February 2024\n" \
  "Bauman Moscow State Technical University\n" 

#define LIST_OF_ACTIONS \
  "\nThere is a list of available operations.\n\n1. " \
  "Сумма натуральных чисел.\n2. Произведение.\n5. EXIT\n\nSelect an action: "

#define REQ_NUMBER "Please input value of "
#define ERROR_NO_SUCH_OPTION                                               \
  "There is no such option! Just enter the number of the options printed " \
  "above"

#define DATA_REQUEST "Please, input the data in the following format: 'HH MM'"

#define ERROR_DIGIT "ERROR: Your input value has a literal value, only numeric values are allowed"
#define ERROR_RANGE "ERROR: One of your value is out of range"
#define ERROR_NLTM "ERROR: N must be bigger than M"
#define ERROR_EMPTY "ERROR: Your input is empty"
#define ERROR_BIG_SUM "ERROR: Sorry, the sum of the result exceeded the acceptable range: [0, MAX_UNSIGNED_INT]"
#define MANY_ATTEMPTS "Too many attempts. Think about your life, it seems you do something wrong😢"

#endif

