#ifndef __STACK__
#define __STACK__

template <typename T>
class Stack
{
public:
    Stack() = default;
    Stack(const Stack &);
    ~Stack();
    bool empty() const;
    T peek() const;
    void push(T val);
    T pop();
    int getSize() const;

private:
    T *elements{};
    int size{};
    int capacity{};
    void ensureCapacity();
};

template <typename T>
Stack<T>::Stack(const Stack &stk) : size(stk.size), capacity(stk.capacity)
{
    elements = new T[stk.capacity];
    for (int i = 0; i < size; ++i)
        elements[i] = stk.elements[i];
}

template <typename T>
Stack<T>::~Stack()
{
    delete[] elements;
}

template <typename T>
bool Stack<T>::empty() const
{
    return size == 0;
}

template <typename T>
T Stack<T>::peek() const
{
    return elements[size - 1];
}

template <typename T>
void Stack<T>::push(T val)
{
    ensureCapacity();
    elements[size++] = val;
}

template <typename T>
T Stack<T>::pop()
{
    return elements[--size];
}

template <typename T>
int Stack<T>::getSize() const
{
    return size;
}

template <typename T>
void Stack<T>::ensureCapacity()
{
    if (size == capacity)
    {
        capacity <<= 1;
        T *old = elements;

        elements = new T[capacity];

        for (int i = 0; i < size; ++i)
            elements[i] = old[i];
        delete[] old;
    }
}

#endif