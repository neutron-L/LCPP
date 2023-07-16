#ifndef TEXT_HH
#define TEXT_HH

#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include <set>

using std::shared_ptr;
using std::vector;
using std::map;
using std::set;
using std::string;
using std::ifstream;

class QueryResult;
class TextQuery
{
public:
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm; 
};


class QueryResult
{
    friend std::ostream & operator<<(std::ostream & , const QueryResult &);
public:
    QueryResult(std::string s, std::shared_ptr<set<TextQuery::line_no>> p,
        shared_ptr<vector<string>> f) 
        : sought(s), lines(p), file(f) {}
private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};

#endif