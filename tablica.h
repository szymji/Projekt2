


class Tablica
{
    private:
    struct Element{ int value; Element * next; };
    Element * start;
    Element * it;

    int tabSize;

    public:
    Tablica();
    void Add(int);
    void Add(int,int);
    void indexRemove (int);
    void valueRemove (int,int=0,bool=0);
    void cRemove();
    void Print();
    int indexGet(int);
    int getSize();

    Tablica operator+(Tablica);
    Tablica operator-(Tablica);
    Tablica operator=(Tablica);
    int operator[](int);
    bool operator>(Tablica);
    bool operator<(Tablica);
};
