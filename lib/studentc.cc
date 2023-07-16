#include "studentc.hh"

double Student::Average() const
{
    if (scores.size())
        return scores.sum() / scores.size();
    else
        return 0;
}
const std::string & Student::Name() const
{
    return name;
}

double & Student::operator[](int i)
{
    return scores[i];
}

double Student::operator[](int i) const
{
    return scores[i];
}

// friend 
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
    os << "Student name: " << stu.name<< std::endl;
    stu.arr_out(os);

    return os;
}

std::istream & operator>>(std::istream & is, Student & stu)
{   
    is >> stu.name;
    return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
    getline(is, stu.name);
    return is;
}

std::ostream & Student::arr_out(std::ostream& os) const
{
    int len = scores.size();

    if (len)
    {
        int i;
        for (i = 0; i < len; ++i)
        {
            os << scores[i] << ' ';
            if (i % 5 == 4)
                os << std::endl;
        }
        if (i % 5)
            os << std::endl;
    }
    else
        os << "empty";
    return os;
}
