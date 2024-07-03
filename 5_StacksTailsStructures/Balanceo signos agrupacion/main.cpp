
#include "header.h"

using namespace std;
#define Data Element<double>

int main()
{

    Queue<Data> q;
    q.enqueue(Data(1.0));
    q.enqueue(Data(2.0));
    q.dequeue();
    q.dequeue();
    q.enqueue(Data(3.0));
    q.enqueue(Data(4.0));
    q.enqueue(Data(10.0));
    q.enqueue(Data(20.0));

    for (int i = 0; i < 4; i++)
    {
        Data e = q.dequeue();
        if (e.isValid())
        {
            cout << e.get() << endl;
        }
    }

    cout << "=======================" << endl;

    Stack<Data> s;
    s.push(Data(1.0));
    s.push(Data(2.0));
    s.pop();
    s.pop();
    s.push(Data(3.0));
    Data e = s.peek();
    if (e.isValid())
        cout << "peeking: " << e.get() << endl;
    s.push(Data(4.0));
    s.push(Data(10.0));
    s.push(Data(20.0));

    for (int i = 0; i < 4; i++)
    {
        Data e = s.pop();
        if (e.isValid())
        {
            cout << e.get() << endl;
        }
    }

    return 0;
}
