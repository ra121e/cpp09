#include <iostream>
#include <map>
#include <string>
#include <cmath>

#include "../RateFinder.hpp"

static int tests_failed = 0;

static void assert_true(bool cond, const char* msg) {
    if (!cond) {
        std::cerr << "ASSERT FAILED: " << msg << std::endl;
        ++tests_failed;
    }
}

int test_find_exact_date() {
    std::map<std::string,double> m;
    m["2025-01-01"] = 100.0;
    RateFinder rf;
    try {
        double v = rf.findRate(m, "2025-01-01");
        assert_true(std::fabs(v - 100.0) < 1e-9, "exact date should return exact rate");
    } catch (...) {
        assert_true(false, "exception thrown for exact date");
    }
    return tests_failed;
}

int test_find_nearest_past() {
    std::map<std::string,double> m;
    m["2024-12-31"] = 90.0;
    m["2025-01-01"] = 100.0;
    RateFinder rf;
    try {
        double v = rf.findRate(m, "2025-01-02");
        // should pick 2025-01-01 (most recent <= date)
        assert_true(std::fabs(v - 100.0) < 1e-9, "nearest past date selection");
    } catch (...) {
        assert_true(false, "exception thrown for nearest past");
    }
    return tests_failed;
}

int test_no_rate_before() {
    std::map<std::string,double> m;
    m["2025-01-10"] = 110.0;
    RateFinder rf;
    try {
        rf.findRate(m, "2025-01-01");
        assert_true(false, "expected exception when no earlier rate");
    } catch (std::exception &e) {
        // expected
    } catch (...) {
        assert_true(false, "unexpected exception type");
    }
    return tests_failed;
}

int run_all_tests() {
    tests_failed = 0;
    test_find_exact_date();
    test_find_nearest_past();
    test_no_rate_before();
    return tests_failed;
}
