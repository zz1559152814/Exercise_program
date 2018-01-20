#include <iostream>

template <typename T>
inline T const& max(T const& a,T const& b)
{
    return a<b?b:a;
}

max(static_cast<double>(4),4.2);
max<double>(4,4.2);


static_cast