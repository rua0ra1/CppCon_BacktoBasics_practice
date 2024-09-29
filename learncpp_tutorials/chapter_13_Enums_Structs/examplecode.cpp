/* unscoped enumeration named color */

/* enum Color{
    red,
    green,
    blue,
};

int main()
{
    Color apple{red};
    Color shirt{green };
} */
// Commonly defined enumerations include days of the week, the cardinal directions, and the suits in a deck
/* enum FileReadResult{
      readResultSuccess,
    readResultErrorFileOpen,
    readResultErrorFileRead,
    readResultErrorFileParse,

};

FileReadResult readFileContents()
{
    if (!openFile())
        return readResultErrorFileOpen;
    if (!readFile())
        return readResultErrorFileRead;
    if (!parseFile())
        return readResultErrorFileParse;

    return readResultSuccess;
}

if (readFileContents() == readResultSuccess)
{
    // do something
}
else
{
    // print error message
} */

// the enum is defined in the global namespace
/* enum Color // this enum is defined in the global namespace
{
    red, // so red is put into the global namespace
    green,
    blue,
};

int main()
{
    Color apple { red }; // my apple is red

    return 0;
} */
