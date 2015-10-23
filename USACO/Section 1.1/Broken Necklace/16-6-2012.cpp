#include<stdio.h>
#include<string.h>
//#include//
using namespace std;
int length(string s, int &currpos, char currbead)
{
  int currlen = 0; // one (1) is for currpos[0] which is currbead

  if(currbead == 'r')
    while(s[currpos] == 'r' || s[currpos] == 'w')
    {
      currpos++;
      currlen++;
    }

  if(currbead == 'b')
    while(s[currpos] == 'b' || s[currpos] == 'w')
    {
      currpos++;
      currlen++;
    }

  return currlen;
}
int main()
{
  //ofstream cout ("beads.out");
  //ifstream cin ("beads.in");

  string s;
  char bead = 'r';
  int longestlen = 0;
  int currpos = 0, firstlen, secondlen;
  int stringlen;


  cin >> stringlen >> s;
  s = s + s;
  currpos = 0;

  firstlen = length(s, currpos, bead);
  //cout << "firstlen = " << firstlen << endl;
  longestlen = firstlen; //for input like all r's or all b's

  while(currpos < s.length() )
  {
    // toggle bead color
    if(bead == 'r')
      bead = 'b';
    else
      bead = 'r';

    secondlen = length(s, currpos, bead);

    if( (firstlen + secondlen) > longestlen )
      longestlen = firstlen + secondlen;

    int temppos = currpos - secondlen;

    firstlen = secondlen;

    int nw = 0;//no of beads that are 'w'

    while( s[temppos-1] == 'w' && currpos >= 1)
    {
      temppos--;
      nw++;
    }

    firstlen = firstlen + nw;
    if( nw >= s.length())
      break; // because the input string s are all w's

  }

  if(longestlen > s.length() / 2)
    longestlen = s.length() / 2;

  cout << longestlen << endl;

  //system("pause");
}
