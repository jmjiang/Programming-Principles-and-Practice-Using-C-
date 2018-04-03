#include <iostream>

using namespace std;

int mystrlen(const char* s)
{
  int res = 0;
  while (*s != 0) {
    ++res;
    ++s;
  }
  return res;
}


char* mystrdup(const char* s)
{
  char* res = new char(mystrlen(s));
  for (int i=0; i<mystrlen(s); ++i) {
    *(res+i) = *(s+i);
  }
  return res;
}


// s cannot be a const
char* myfindx(char* s, const char* x)
{
  for (int i=0; i<mystrlen(s); ++i) {
    if (*(s+i) == *x) {
      bool found = true;
      for (int j=0; j<mystrlen(x); ++j) {
        if (*(s+i+j) != *(x+j)) {
          found = false;
          break;
        }
      }
      if (found) return (s+i);
    }
  }
  return NULL;
}


int mystrcmp(const char* s1, const char* s2)
{
  if (*s1 == 0) {
    if (*s2 == 0) return 0;
    else return -1;
  } else {
    if (*s2 == 0) return 1;
    else {
      if (*s1 == *s2) return mystrcmp(s1+1, s2+1);
      else if (*s1 < *s2) return -1;
      else return 1;
    }
  }
}


int main()
{
  char* s1 = "exercise1";
  cout << "s1 = " << s1 << endl;
  char* s2 = mystrdup(s1);
  cout << "s2 = " << s2 << endl;

  char* x = "se1";
  char* s3 = myfindx(s2, x);
  cout << "s3 = " << s3 << endl;

  int comp = mystrcmp(s1, x);
  cout << s1;
  if (comp > 0) cout << " AFTER ";
  else if (comp < 0) cout << " BEFORE ";
  else cout << " EQUAL ";
  cout << x << endl;

  return 0;
}










