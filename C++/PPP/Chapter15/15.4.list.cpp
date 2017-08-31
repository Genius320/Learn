#include "std_lib_facilities.h"

template<typename Elem> struct Link {
    Link* prev;
    Link* succ;
    Elem val;
};

template<typename Elem>
class list {
public:
    class iterator;     // ��Ա���ͣ���������Ƕ���ࣩ
    iterator begin();   // ָ����Ԫ�صĵ�����
    iterator end();     // ָ��βԪ��֮��ĵ�����

    iterator insert(iterator p, const Elem& v);     // �� v ���������� p ֮���λ��
    iterator erase(iterator p);                     // ��������ɾ�� p
    
    void push_back(const Elem& v);      // �� v ��������ĩβ
    void push_front(const Elem& v);     // �� v ��������ͷ
    void pop_front();       // ɾ����Ԫ��
    void pop_back();        // ɾ��βԪ��

    Elem& front();          // ��ȡ��Ԫ��
    Elem& back();           // ��ȡβԪ��
};

template<typename Elem>     // request Element<Elem>()
class list<Elem>::iterator {
    Link<Elem>* curr;       // ��ǰ����
public:
    iterator(Link<Elem>* p) : curr { p } { }
    iterator& operator++() { curr = curr->succ; return *this; }
    iterator& operator--() { curr = curr->prev; return *this; }
    Elem& operator*() { return curr->val; }

    bool operator==(const iterator&b) const { return curr == b.curr; }
    bool operator!=(const iterator&b) const { return curr != b.curr; }
};

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p)
            high = p;
    return high;
}

template<typename C>
using Iterator = typename C::iterator;

template<typename C>
using Value_type = typename C::value_type;

void f()
{
    list<int> lst;
    for (int x; cin >> x; )
        lst.push_front(x);
    list<int>::iterator p = high(lst.begin(), lst.end());
    if (p == lst.end())
        cout << "The list is empty";
    else
        cout << "the highest value is " << *p << '\n';
}

void print2(const vector<double>& v, list<double>& lst)
{
    for (double x : v)
        cout << x << '\n';
    for (double x : lst)
        cout << x << '\n';
}

template<typename T>
void user(vector<T>& v, list<T>& lst)
{
    for (auto p = v.begin(); p != v.end(); ++p)
        cout << *p << '\n';
    auto q = find(lst.begin(), lst.end(), T { 42 });
}