This dll was created as a school assignment.
I have no intention of keeping it up-to-date or modifying it.

This dll packages the iheartquotes RESTful API into an easy to use c++ library.
Not all the functionality of the iheartsquotes API is in there, such as it cannot get quotes from specific sources.

It only has one callable function: string GetRandomQuote(int maxLines, int minLines, int maxCharacters, int minCharacters);

it will return an error message if the maxs are less than the mins, however they can be equal.

If the parameters you enter cannot be met, the program will chrash, test your stuff.