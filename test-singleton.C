# include <cassert>

# include <singleton.H>

using namespace std;

struct Test : public Singleton<Test> { /* empty */ };

int main()
{
  Test & t1 = t1.get_instance();
  Test & t2 = t1.get_instance();
  assert(&t1 == &t2);
  
  return 0;
}
