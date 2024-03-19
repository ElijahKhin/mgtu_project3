#ifndef CONSOLE_H
#define CONSOLE_H


class Console {
	private:
		double* userNumericInput = nullptr;
		char* userAlphaInput = nullptr; // alpha - alphabetical
	
	public:
		short retries = 3;

		/*
  	//	Constructors & Destructors
  	*/
		Console();
		~Console();

		/*
  	//	Main Public Methods
  	*/
		double ReadUserNumericInput(std::istream& input, double*& userNumericInput);
		void ReadUserAlphaInput(std::istream& input, char*& userAlphaInput);
		void SendMessage(char* message, bool wait, bool clear);
		bool ContinueTask();

}

#endif
