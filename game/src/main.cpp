#include "Engine.hpp"

using std::make_unique;

int main(int argc, char* argv[])
{
    auto engine = make_unique<bs::Engine>();

    engine->Run();

    return 0;
}