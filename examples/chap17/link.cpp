#include <string>
#include <iostream>

using namespace std;


struct Link {
  string value;
  Link* prev;
  Link* succ;
  Link(const string& v, Link* p = nullptr, Link* s = nullptr)
    :value(v), prev(p), succ(s) { }
};

// insert n before p; return ;
Link* insert(Link* p, Link* n)
{
  if (n == nullptr) return p;
  if (p == nullptr) return n;
  n->succ = p;
  n->prev = p->prev;
  if (n->prev != nullptr) n->prev->succ = n;
  p->prev = n;
  return n;
}

// insert n after p; return n
Link* add(Link* p, Link* n)
{
  if (n == nullptr) return p;
  if (p == nullptr) return n;
  n->prev = p;
  n->succ = p->succ;
  if (n->succ) n->succ->prev = n;
  p->succ = n;
  return n;
}


// remove *p from list; return p's successor
Link* erase(Link* p)
{
  if (p == nullptr) return nullptr;
  if (p->prev) p->prev->succ = p->succ;
  if (p->succ) p->succ->prev = p->prev;
  return p->succ;
}


// find s in list;
// return nullptr for "not found"
Link* find(Link* p, const string& s)
{
  while (p) {
    if (p->value == s) return p;
    p = p->succ;
  }
  return nullptr;
}


// move n positions in list
// return nullptr for "not found"
// positive n moves forward, negative backward
Link* advance(Link* p, int n)
{
  if (p == nullptr) return nullptr;
  if (n > 0) {
    while (n--) {
      cout << "[advance] n = " << n << endl;
      if (p->succ == nullptr) return nullptr;
      p = p->succ;
    }
  } else if (n < 0) {
    while (n++) {
      cout << "[advance] n = " << n << endl;
      if (p->prev == nullptr) return nullptr;
      p = p->prev;
    }
  }
  return p;
}

int main()
{
  Link* norse_gods = new Link("Thor");
  norse_gods = insert(norse_gods, new Link("Odin"));
  norse_gods = insert(norse_gods, new Link("Zeus"));
  norse_gods = insert(norse_gods, new Link("Freia"));

  Link* greek_gods = new Link("Hera");
  greek_gods = insert(greek_gods, new Link("Athena"));
  greek_gods = insert(greek_gods, new Link("Mars"));
  greek_gods = insert(greek_gods, new Link("Poseidon"));
  
  Link* p = find(greek_gods, "Mars");
  if (p) p->value = "Ares";

  Link* p = find(norse_gods, "Zeus");
  if (p) {
    if (p == norse_gods) norse_gods = p->succ;
    erase(p);
    greek_gods = insert(greek_gods,p);
  }
  
  // Try out n--
  int n = 5;
  while (n--) {
    cout << "n = " << n << endl;
  }
  return 0;
}















