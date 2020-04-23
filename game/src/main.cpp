#include "Engine.hpp"

using std::make_unique;
using bs::Engine;

int main(int argc, char* argv[])
{
    auto engine = make_unique<Engine>();

    engine->Run();

    return 0;
}