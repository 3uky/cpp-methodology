// BEFORE
/*
bool GptFlag = false;
bool GpunchFlag = false;
// Remember to clear

void copy ()
{
    int c;
    while ((c = (GptFlag ? readPt() : readKeyboard())) != EOF)
    {
        GpunchFlag ? writePunch(c) : writePrinter(c);
    }
}
*/


// AFTER
#pragma once

#include <iostream>

using namespace std;

namespace solid
{

class Reader
{
public:
    virtual int Getchar() = 0;
};

class Writer
{
public:
    virtual void Putchar(int c) = 0;
};

class Worker
{
public:
    static void Copy(Reader& reader, Writer& writer)
    {
        int c;
        while((c = reader.Getchar()) != EOF)
        {
            writer.Putchar(c);
        }
    }
};

class Keyboard : public Reader
{
    int Getchar() override
    {
        int x;
        cin >> x;
        return x;
    }

};

class Printer : public Writer
{
    void Putchar(int c) override
    {
        cout << static_cast<char>(c);
    }
};

}