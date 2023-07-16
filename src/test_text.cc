#include <iostream>

#include "text.hh"

using namespace std;

void runQueries(ifstream & infile)
{
    TextQuery tq(infile);
    string word;

    while (1)
    {
        cout << "enter word to look for, or q to quit: ";
        if (!(cin >> word) || word == "q")
            break;
        cout << tq.query(word) << endl;;
    }
}

int main(int argc, char ** argv)
{
    if (argc != 2)
    {
        cerr << "Usage: ./test_query <file>\n"<<endl;
        return 1;
    }
    ifstream fs;
    string file = argv[1];
    fs.open(file);
    if (!fs.is_open())
    {
        cerr << "cannot open file " << file << endl;
        return 1;
    }
    runQueries(fs);

    return 0;
}