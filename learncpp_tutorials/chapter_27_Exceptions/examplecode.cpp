/* #include <iostream>

void D() // called by C()
{
    std::cout << "Start D\n";
    std::cout << "D throwing int exception\n";

    throw - 1;

    std::cout << "End D\n"; // skipped over
}

void C() // called by B()
{
    std::cout << "Start C\n";
    D();
    std::cout << "End C\n";
}

void B() // called by A()
{
    std::cout << "Start B\n";

    try
    {
        C();
    }
    catch (double) // not caught: exception type mismatch
    {
        std::cerr << "B caught double exception\n";
    }

    try
    {
    }
    catch (int) // not caught: exception not thrown within try
    {
        std::cerr << "B caught int exception\n";
    }

    std::cout << "End B\n";
}

void A() // called by main()
{
    std::cout << "Start A\n";

    try
    {
        B();
    }
    catch (int) // exception caught here and handled
    {
        std::cerr << "A caught int exception\n";
    }
    catch (double) // not called because exception was handled by prior catch block
    {
        std::cerr << "A caught double exception\n";
    }

    // execution continues here after the exception is handled
    std::cout << "End A\n";
}

int main()
{
    std::cout << "Start main\n";

    try
    {
        A();
    }
    catch (int) // not called because exception was handled by A
    {
        std::cerr << "main caught int exception\n";
    }
    std::cout << "End main\n";

    return 0;
} */

// catch all exceptions
/* #include <iostream>

int main()
{
	try
	{
		throw 5.5; // throw an int exception
	}
	catch (double x)
	{
		std::cout << "We caught an exception of type double: " << x << '\n';
	}
	catch (...) // catch-all handler
	{
		std::cout << "We caught an exception of an undetermined type\n";
	}
} */

// debugging unhandled exceptions
#include <iostream>
#define NDEBUG

struct GameSession
{
    // Game session data here
};

void runGame(GameSession&)
{
    throw 1;
}

void saveGame(GameSession&)
{
    // Save user's game here
}

class DummyException // a dummy class that can't be instantiated
{
    DummyException() = delete;
};

int main()
{
    GameSession session {};

    try
    {
        runGame(session);
    }
#ifndef NDEBUG // if we're in release node
    catch(...) // compile in the catch-all handler
    {
        std::cerr << "Abnormal termination\n";
    }
#else // in debug mode, compile in a catch that will never be hit (for syntactic reasons)
    catch(DummyException)
    {
    }
#endif

    saveGame(session); // save the user's game (even if catch-all handler was hit)

    return 0;
}