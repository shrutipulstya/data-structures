#include<iostream>
using namespace std;

const int t_size = 10;  
int t[t_size];

class HashTableEntry 
{
    public:
    int k;
    int v;
    HashTableEntry(int k, int v) 
    {
        this->k = k;
        this->v = v;
    }
};

class HashMapTable 
{

    private:
    HashTableEntry **t;
    public:
    HashMapTable() 
    {
        t = new HashTableEntry* [t_size];  //declare arrray of pointers
        for (int i = 0; i< t_size; i++) 
        {
            t[i] = nullptr;
        }
    }
    int HashFunc(int k) 
    {
    return k % t_size;
    }
    void Insert(int k) 
    {
        int index = HashFunc(k);
        if(t[index] != nullptr)
        {   
            index++;
        }
        cout << k <<" "<<index<<endl;     
    }
};

int main() 
{
    HashMapTable hash;
    int k;
    hash.Insert(66);
    hash.Insert(32);
    hash.Insert(11);
    hash.Insert(67);
    hash.Insert(27);
    return 0;
}

//rough code that works 

#include<iostream>
using namespace std;

const int t_size = 10;  
int t[t_size];
int k = 32;


int HashFunc(int k)  
{
    return k % t_size;
}

void insert()
{
    int index = HashFunc(k);
    cout << k <<" stored at "<<index<<endl;
}
int main()
{
    insert();
    return 0;
}