#include <iostream>
#include <string>

template <typename T>
concept ComplexConcept = requires(const T v)
{
    {v.hash()} -> std::convertible_to<long>;
    {v.toString()} -> std::same_as<std::string>;
} && !std::has_virtual_destructor<T>::value;

class A
{};

class B
{
private:
    int _v;
public:
    B(const int v):_v(v)
    {}

    virtual ~B()
    {}

    int hash() const
    {
        return _v;
    }
    std::string toString() const
    {
        return std::to_string(_v);
    }
};

class C
{
    int _v;
public:
    C(const int v):_v(v)
    {}

    int hash() const
    {
        return _v;
    }
    std::string toString() const
    {
        return std::to_string(_v);
    }

};

template <ComplexConcept T>
void concept_method(T val)
{
    std::cout << "Hash: " << val.hash() << std::endl;
std::cout << "String: " << val.toString() << std::endl;
}

int main()
{
//    A a;
//    concept_method<A>(a); // Wrong
//    B b(2);
//    concept_method<B>(b);

    C c(4);
    concept_method<C>(c);
    return 0;
}