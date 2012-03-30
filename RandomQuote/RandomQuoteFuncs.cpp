//Author: Kyle Goodman
//Creation Date: 3-29-2012
//Description: Uses iheartquotes RESTful api to return a random quote.

#include "RandomQuoteFuncs.h"

#include <stdexcept>

namespace RandomQuote
{
	//This function returns a random quote in the form of a std::string.
	//The length of the quote is determined by the integers you use as parameters.
	string RandomQuoteFuncs::GetRandomQuote(int maxLines, int minLines, int maxCharacters, int minCharacters)
	{
		if((maxLines < minLines) || (maxCharacters < minCharacters))
		{
			return "Max less than min.  Please ensure min is less than or equal to max.";
		}
		else
		{
			System::String^ str1 = "http://www.iheartquotes.com/api/v1/random?format=text&max_lines=";
			System::String^ str2 = System::Convert::ToString(maxLines);
			System::String^ str3 = "&min_lines=";
			System::String^ str4 = System::Convert::ToString(minLines);
			System::String^ str5 = "&max_characters=";
			System::String^ str6 = System::Convert::ToString(maxCharacters);
			System::String^ str7 = "&min_characters";
			System::String^ str8 = System::Convert::ToString(minCharacters);

			System::String^ call = str1 + str2 + str3 + str4 + str5 + str6 + str7 + str8;

			System::Net::HttpWebRequest^ myRequest = dynamic_cast<HttpWebRequest^>(WebRequest::Create( call ));
			System::Net::WebResponse^ myResponse = myRequest->GetResponse();

			// Obtain a 'Stream' object associated with the response object.
			System::IO::Stream^ ReceiveStream = myResponse->GetResponseStream();

			System::Text::Encoding^ encode = System::Text::Encoding::GetEncoding( "utf-8" );

			// Pipe the stream to a higher level stream reader with the required encoding format.
			System::IO::StreamReader^ readStream = gcnew System::IO::StreamReader( ReceiveStream,encode );
			array<Char>^ read = gcnew array<Char>(maxCharacters);

			int count = readStream->Read( read, 0, maxCharacters );

			String^ str = gcnew String( read,0,count );

			string quote = "";

			MarshalString(str, quote);

			return quote;
		}
	}

	//This function converts a System::String into a std::string.
	//I did not write this, I got it from http://msdn.microsoft.com/en-us/library/1b4az623(v=vs.80).aspx
	void RandomQuoteFuncs::MarshalString ( String ^ s, string& os ) {
	   using namespace Runtime::InteropServices;
	   const char* chars = 
		  (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	   os = chars;
	   Marshal::FreeHGlobal(IntPtr((void*)chars));
	}
}
