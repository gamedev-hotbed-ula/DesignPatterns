# include <cassert>
# include <iostream>

# include <singleton.H>

using namespace std;

struct Test : public Singleton<Test>
{
  ~Test()
  {
    cout << "Destructor de Test fue llamado correctamente\n";
  }
};

int main()
{
  Test & t1 = t1.get_instance();
  Test & t2 = t1.get_instance();
  assert(&t1 == &t2);
  
  return 0;
}
