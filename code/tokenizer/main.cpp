#include <utilities/utilities-tokenizer.h>
#include <iostream>
#include <list>

int main()
{
  //delim related
  char delim(';');
  char delimbuf[2] = {delim, '\0'};
  std::string delimstr(delimbuf);
  std::string ddelimstr(delimstr+delimstr);

  //test strings
  std::list<std::string> testlist;
  testlist.push_back("one");
  testlist.push_back("one two");
  testlist.push_back("one two three");
  testlist.push_back(delimstr+"one");
  testlist.push_back("one"+delimstr);
  testlist.push_back("one"+delimstr+"two");
  testlist.push_back("one"+delimstr+"two"+delimstr+"three");
  testlist.push_back(ddelimstr+"one");
  testlist.push_back("one"+ddelimstr);
  testlist.push_back("one"+ddelimstr+"two");
  testlist.push_back("one"+ddelimstr+"two"+ddelimstr+"three");
  testlist.push_back("one"+ddelimstr+"two"+ddelimstr+"three"+delimstr+"four");
  testlist.push_back(ddelimstr+delimstr+"one");
  testlist.push_back("one"+ddelimstr+delimstr);
  testlist.push_back("one"+ddelimstr+delimstr+"two");
  testlist.push_back(ddelimstr+ddelimstr+"one");
  testlist.push_back("one"+ddelimstr+ddelimstr);
  testlist.push_back("one"+ddelimstr+ddelimstr+"two");

  //test with escape off
  for(std::list<std::string>::const_iterator it(testlist.begin());
      it != testlist.end(); ++it)
  {
    std::cout << "Testing " << *it << " with escape off" << std::endl;

    Utilities::TokenList tokens(Utilities::tokenize(*it, delim, false));
    for(Utilities::TokenList::const_iterator it2(tokens.begin());
        it2 != tokens.end(); ++it2)
    {
      std::cout << "Arg: " << *it2 << std::endl;
    }
  }
  std::cout << std::endl;

  //test with escape on
  for(std::list<std::string>::const_iterator it(testlist.begin());
      it != testlist.end(); ++it)
  {
    std::cout << "Testing " << *it << " with escape on" << std::endl;

    Utilities::TokenList tokens(Utilities::tokenize(*it, delim, true));
    for(Utilities::TokenList::const_iterator it2(tokens.begin());
        it2 != tokens.end(); ++it2)
    {
      std::cout << "Arg: " << *it2 << std::endl;
    }
  }

  return 0;
}
