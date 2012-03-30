//Author: Kyle Goodman
//Creation Date: 3-29-2012
//Description: Uses iheartquotes RESTful api to return a random quote.

// RandomQuoteFuncs.h
#ifndef RANDOMQUOTEFUNCS_H
#define RANDOMQUOTEFUNCS_H
#include <string>

#using <mscorlib.dll>
#using <System.dll>

using namespace System;
using namespace System::Net;
using namespace std;

namespace RandomQuote
{
	class RandomQuoteFuncs
	{
		public:
			static __declspec(dllexport) string GetRandomQuote(int maxLines, int minLines, int maxCharacters, int minCharacters);
		private:
			static void MarshalString ( String ^ s, string& os );
	};
}
#endif