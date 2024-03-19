#include "lib/tasks/tasks.h"
#include "messages.h"
#include "colors.h"

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

static int continueTask(int& attempts) {
	char answer;

	is3Attempts(attempts);
	std::cout << std::endl << "Do you want to continue? (y/n) ";
	answer << std::cin;
	if (answer == 'y') return 1;
	else if (answer == 'n') return 0;
	else  {
		noSuchOption(attempts);
		return continueTask(attempts);
	}
}

static int launchTask1() {
	int result;
	int attempts;

	do {
		result = task1(getUserNumber('n'), getUserNumber('m'));
		std::cout << "Result: " << result << std::endl;
		attempts = 0;
	} while (continueTask(attempts));
	return 0;
}

static void getActionFromUser(int&& attempts) {
	char answer;

	is3Attempts(attempts);
	printActionList();
	answer = getAnswer();
	if (answer == '1') attempts = launchTask1();
	else if (answer == '2') attempts = launchTask2();
	else if (answer == '3') launchTask3();
	else if (answer == '4') launchTask4();
	else if (answer == '5') exit(0);
	else {noSuchOption(attempts);};
	getActionFromUser(attempts+0);
}

int main()
{ 
	welcome();
	getActionFromUser(0);
}
