#include &lt;iostream&gt;
using namespace std;

class Base
{
public:
void Display ()
{
cout &lt;&lt; &quot;Display of Base&quot; &lt;&lt; endl;
}
};

class Derived:public Base
{
public:void Display ()
{
cout &lt;&lt; &quot;Display of Derived &quot; &lt;&lt; endl;
}
};

int main()
{
Base *p = new Derived ();
p-&gt;Display ();
}