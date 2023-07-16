#include "studenti.hh"

double Student::Average() const
{
    if (ArrayDb::size())
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}
const std::string & Student::Name() const
{
    return static_cast<const std::string &>(*this);
}

double & Student::operator[](int i)
{
    return ArrayDb::operator[](i);
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// friend 
std::ostream & operator<<(std::ostream & os, const Student & stu)
{
    os << "Student name: " << static_cast<const std::string &>(stu) << std::endl;
    stu.arr_out(os);

    return os;
}

std::istream & operator>>(std::istream & is, Student & stu)
{   
    is >> static_cast<std::string &>(stu);
    return is;
}

std::istream & getline(std::istream & is, Student & stu)
{
    getline(is, static_cast<std::string &>(stu));
    return is;
}

std::ostream & Student::arr_out(std::ostream& os) const
{
    int len = ArrayDb::size();

    if (len)
    {
        int i;
        for (i = 0; i < len; ++i)
        {
            os << ArrayDb::operator[](i) << ' ';
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
