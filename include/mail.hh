#ifndef MAIL_HH
#define MAIL_HH

#include <set>
#include <string>

class Folder;
class Message
{
    friend void swap(Message & lhs, Message & rhs);
public:
    explicit Message(const std::string & str = "") :
        contents(str) {}
    Message(const Message &);
    Message & operator=(const Message & );
    ~Message();

    void save(Folder &);
    void remove(Folder &);
private:
    std::string contents;
    std::set<Folder *> folders;

    void add_to_Folders(const Message &);
    void remove_from_Folders();
};

class Folder
{
public:
    void addMsg(const Message *);
    void remMsg(const Message *);
private:
    std::set<const Message *> messages;
};

#endif