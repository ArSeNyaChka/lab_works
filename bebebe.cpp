#include <fstream>
#include <string>


int main(int argc, char* argv[]) {
    std::ofstream f("out.cpp");
    f << "bool isChetnoe(int a) {";

    for (int i = 0; i < std::stoi(argv[1]); i++)
        f << "\n    if (a == " + std::to_string(i) + ")\n       return " + (i % 2 == 0 ? "true" : "false") + ";";

    f << "\n}";

    return 0;
}