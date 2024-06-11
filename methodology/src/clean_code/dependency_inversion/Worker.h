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
// worker copy is not dependent on implementation of reader or writer just on interface (run time dependency)
#pragma once

#include <iostream>

#include "IReader.h"
#include "IWriter.h"

namespace clean_code::solid
{

class Worker
{
public:
    static void Copy(IReader& reader, IWriter& writer)
    {
        int c;
        while((c = reader.Getchar()) != EOF)
        {
            writer.Putchar(c);
        }
    }
};

}