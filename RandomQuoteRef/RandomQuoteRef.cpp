#include <iostream>
#include <string>

#include "RandomQuoteFuncs.h"

using namespace std;
using namespace RandomQuote;

int main()
{
	int maxLines = 4;
	int minLines = 1;
	int maxCharacters = 256;
	int minCharacters = 0;
	string moo = RandomQuoteFuncs::GetRandomQuote(maxLines,minLines,maxCharacters,minCharacters);

	cout << moo << endl;

	//Gotta throw in some cin.get()s to slow this thing down!
	cin.get();

    return 0;
}