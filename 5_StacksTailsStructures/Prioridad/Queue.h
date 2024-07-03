
#include "header.h"

template <typename D>
class Queue
{

public:
    Queue(){};

    Queue(const Queue &orig){};

    ~Queue(){};

    void enqueue(D d)
    {
        this->a.push_back(d);
    }

    D dequeue()
    {
        if (this->a.size() > 0)
        {
            D d = this->a.at(0);
            auto it = this->a.begin();
            this->a.erase(it);
            return d;
        }
        else
        {
            D d;
            return d;
        }
    }


    void imprimir_cola(){
        D d;
        for (auto i = this -> a.begin(); i != this -> a.end(); ++i){
            d = *i;
            cout << d.get() << ' ';
        }
        cout << endl;
    }

    bool empty(){
        return this -> a.empty();
    }

private:
    vector<D> a;
};
