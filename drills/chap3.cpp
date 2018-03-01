
#include <iostream>
#include <string>
using namespace std;

int main() {
  cout << "Enter the name of the person you want to write to\n";
  string first_name = " ";
  cin >> first_name;

  cout << "Enter the name of a friend\n";
  string friend_name = " ";
  cin >> friend_name;

  cout << "Enter an m if the friend is male and an ef if female\n";
  char friend_sex = 0;
  cin >> friend_sex;

  cout << "Enter the age of the recipient\n";
  int age = -1;
  cin >> age;
  if ((age <= 0) || (age >= 110)) {
    cout << "you're kidding!\n";
    exit(1);
  }

  // 1
  cout << "Dear " << first_name << ",\n";

  // 2
  cout << "    How are you? I am fine. \n";

  // 3
  cout << "    Have you seen " << friend_name << " lately? ";

  // 4
  cout << "If you see " << friend_name << " please ask ";
  if (friend_sex == 'm') cout << "him ";
  else if (friend_sex == 'f') cout << "her ";
  cout << "to call me.\n";

  // 5
  cout << "    I hear you just had a birthday and you are " << age << " years old. ";

  // 6
  if (age < 12) cout << "Next year you will be " << age + 1 << ".\n";
  else if (age == 17) cout << "Next year you will be able to vote.\n";
  else if (age > 70) cout << "I hope you are enjoying retirement.\n";

  // 7
  cout << "Yours sincerely,\n\n\nJiaming Jiang\n";

  return 0;
}
