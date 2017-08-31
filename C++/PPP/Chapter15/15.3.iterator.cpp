#include "std_lib_facilities.h"

double* get_from_jack(int* count);  // Jack �� double ֵ����һ�����鲢��Ԫ�ظ������� *count ����
vector<double>* get_from_jill();    // Jill ��� vector

template<typename Iterator>
Iterator high(Iterator first, Iterator last)
{
    Iterator high = first;
    for (Iterator p = first; p != last; ++p)
        if (*high < *p)
            high = p;
    return high;
}

int main()
{
    int jack_count = 0;
    double* jack_data = get_from_jack(&jack_count);
    vector<double>* jill_date = get_from_jill();

    double* jack_high = high(jack_data, jack_data+jack_count);
    vector<double>& v = *jill_date;
    double* jill_high = high(&v[0], &v[0]+v.size());

    delete[] jack_data;
    delete jill_date;
}