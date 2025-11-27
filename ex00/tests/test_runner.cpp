#include <iostream>

int main(int argc, char **argv) {
    (void)argc;
    (void)argv;
    std::cout << "Running tests..." << std::endl;
    // The actual test object will be linked in
    // when building tests/test_ratefinder.o into this executable.
    // For simplicity, call a function provided by the test translation unit.
    extern int run_all_tests();
    int result = run_all_tests();
    if (result == 0) {
        std::cout << "ALL TESTS PASSED" << std::endl;
    } else {
        std::cout << result << " TEST(S) FAILED" << std::endl;
    }
    return result;
}
