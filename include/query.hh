#ifndef QUERY_HH
#define QUERY_HH

#include "text.hh"

class Query_base
{
    friend class Query;
protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base()=default;
private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator&(const Query &, const Query &);
    friend Query operator|(const Query &, const Query &);
public:
    Query(const std::string &);
    QueryResult eval(const TextQuery &t) const 
        { return q->eval(t); }
    virtual std::string rep() const { return q->rep(); }
private:
    Query(std::shared_ptr<Query_base> query) : q(query) { }
    std::shared_ptr<Query_base> q;
};

class WordQuery : public Query_base
{
    friend class Query;
    WordQuery(const std::string & s) : query_word(s) {}
    QueryResult eval(const TextQuery & t) const
    { return t.query(query_word); }
    std::string rep() const { return query_word; }
    std::string query_word;
};


class NotQuery : public Query_base
{
    friend Query operator~(const Query &);
    NotQuery(const Query & q) : query(q) { }

    std::string rep() const { return "~(" + query.rep() + ")"; }
    QueryResult eval(const TextQuery &) const;
    Query query;
};


class BinaryQuery : public Query_base
{

};


class AndQuery : public BinaryQuery
{

};


class OrQuery : public BinaryQuery
{

};

#endif