#include "mail.hh"

Message::Message(const Message & msg) : contents(msg.contents), folders(msg.folders)
{
    add_to_Folders(msg);   
}

Message & Message::operator=(const Message & msg)
{
    if (this != &msg)
    {
        remove_from_Folders();
        add_to_Folders(msg);
        folders = msg.folders;
        contents = msg.contents;
    }

    return *this;
}
Message::~Message()
{
    remove_from_Folders();
}


void Message::add_to_Folders(const Message & msg)
{
    for (auto & f : msg.folders)
        f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto & f : folders)
        f->remMsg(this);
}

void Message::save(Folder & f)
{
    folders.insert(&f);
    f.addMsg(this);
}
void Message::remove(Folder & f)
{
    folders.erase(&f);
    f.remMsg(this);
}


void swap(Message & lhs, Message & rhs)
{
    // swap contents
    swap(lhs.contents, rhs.contents);
    // remove from folders
    for (auto & f : lhs.folders)
        f->remMsg(&lhs);

    for (auto & f : rhs.folders)
        f->remMsg(&rhs);

    // add to folders
    lhs.add_to_Folders(rhs);
    rhs.add_to_Folders(lhs);

    // swap folders
    swap(lhs.folders, rhs.folders);
}

void Folder::addMsg(const Message * fm)
{
    messages.insert(fm);
}


void Folder::remMsg(const Message * fm)
{
    messages.erase(fm);
}