#include <sstream>
#include <iostream>

#include "text.hh"


std::ostream & operator<<(std::ostream & os, const QueryResult & qr)
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << (qr.lines->size() == 1 ? "time" : "times") << std::endl;
    for (auto num : *qr.lines)
    {
        os << "\t(line " << num << ") "
            << *(qr.file->begin() + num - 1) << std::endl;
    }
    return os;
}

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
    string text;
    std::istringstream line;

    while (getline(is, text))
    {
        file->push_back(text);
        int n = file->size();

        line.str(text);
        string word;
        while (line >> word)
        {
            auto & lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
        line.clear();
    }

    // check
    for (auto & text : *file)
        std::cout << text << std::endl;
}


QueryResult TextQuery::query(const string & sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}