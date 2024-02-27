#include "tasks/tasks.h"
#include "messages.h"
#include "colors.h"

inline static void	isDigit(int ch) {
	if (!(ch >= 48 && ch <= 57)) throw std::invalid_argument(ERROR_DIGIT);
}

inline static void	isAllowedRange(unsigned long num) {
	if (num > MAX_UNSIGNED_INT) throw std::invalid_argument(ERROR_RANGE);
}

inline static void isEmptyInput(int flgEmpty) {
	if (flgEmpty) throw std::invalid_argument(ERROR_EMPTY);
}

inline static void waitUser() {
  std::cout << "\nPress Enter to continue…" << std::endl;
  std::cin.get();
}

inline static void welcome() {
	system("clear");
	std::cout << std::endl << WELCOME_MESSAGE << std::endl;
	waitUser();
}

inline static void printActionList() {
	system("clear");
	std::cout << LIST_OF_ACTIONS;
}

inline static void noSuchOption(int& attempts) {
	std::cout << ERROR_NO_SUCH_OPTION << std::endl; 
	attempts++;
}

inline static void is3Attempts(int& attempts) {
	if (attempts == 3) {
		system("clear");
		std::cout << std::endl << MANY_ATTEMPTS << std::endl;
		exit(1);
	}
}

inline static size_t strLen(char *str)
{
	size_t	i = 0;

	while (str && str[i]) i++; return (i);
}

static int getAnswer() {
	char* answer = new char;
	int i = 0;
	char ch;

    while ((std::cin).get(ch) && ch != '\n') answer[i++] = ch;
	if (strLen(answer) == 1) ch = answer[0];
	delete answer; 
	std::cout << std::endl;
	return ch;
}

static int continueTask(int& attempts) {
	char answer;

	is3Attempts(attempts);
	std::cout << std::endl << "Do you want to continue? (y/n) ";
	answer = getAnswer();
	if (answer == 'y') return 1;
	else if (answer == 'n') return 0;
	else  {
		noSuchOption(attempts);
		return continueTask(attempts);
	}
}

static unsigned getUserNumber(char number_type) {
	char ch;
	unsigned long num = 0;
	int flgEmpty = 1;
	
	std::cout <<  REQ_NUMBER << number_type << ": ";
    while ((std::cin).get(ch) && ch != '\n') {
		isDigit(ch);
		flgEmpty = 0; // flgEmpty = 0 means that user's input isn't empty
		num = num * 10 + (ch - '0');
		isAllowedRange(num);
	}
	isEmptyInput(flgEmpty);
	return num;
}

static int launchTask1() {
	int attempts;

	do {
		task1(getUserNumber('n'), getUserNumber('m'));
		attempts = 0;
	} while (continueTask(attempts));
	return 0;
}

static int launchTask234(int (*task)(int)) {
	char ch;
	int attempts;

	(std::cin).get(ch);
	do task(getUserNumber('n')); while (continueTask(attempts));
	return 0;
}

static void getActionFromUser(int&& attempts) {
	char answer;

	is3Attempts(attempts);
	printActionList();
	answer = getAnswer();
	if (answer == '1') attempts = launchTask1();
	else if (answer == '2') attempts = launchTask234(&task2);
//	else if (answer == '3') launchTask3();
//	else if (answer == '4') launchTask4();
	else if (answer == '5') exit(0);
	else {noSuchOption(attempts); waitUser();};
	getActionFromUser(attempts+0);
}

int main()
{ 
	welcome();
	getActionFromUser(0);
}
