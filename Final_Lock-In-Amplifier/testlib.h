#ifndef TESTLIB1_H_INCLUDED
#define TESTLIB1_H_INCLUDED

#include <iostream>
#include <sstream>

/*!
 * \brief Macros to run test function in a test class
 *
 * \details Macros to run test function in a test class
 *
 */
#define RUN_TEST(tr, func)                           \
    tr.runTest(func, std::string(#func))

/*!
 * \brief Macros to run test function in a test class with a message string
 *
 * \details Macros to run test function in a test class with a message string
 *
 */
#define RUN_TEST_MSG(tr, func, msg)                  \
    tr.runTest(func, std::string(#func)              \
                     + " "                           \
                     + std::string(msg))

/*!
 * \brief Assert macros for equality check
 *
 * \details Assert macros for equality check
 *
 */
#define ASSERT_EQUAL(x, y) {                         \
    std::ostringstream os;                           \
    os << ", file " << __FILE__                      \
       << ", function " << __func__                  \
       << ", line " << __LINE__;                     \
    Testlib::AssertEqual(x, y, os.str());            \
}

/*!
 * \brief Assert macros for equality check and message printing
 *
 * \details Assert macros for equality check and message printing
 *
 */
#define ASSERT_EQUAL_MSG(x, y, msg) {                \
    std::ostringstream os;                           \
    os << "message: " << msg                         \
       << ", file " << __FILE__                      \
       << ", function " << __func__                  \
       << ", line " << __LINE__;                     \
    if (Testlib::AssertEqual(x, y, os.str()) &&      \
        Testlib::__assert_print_if_ok) {             \
        cerr << msg << " - OK\n";                    \
    }                                                \
}

/*!
 * \brief Assert macros
 *
 * \details Assert macros
 *
 */
#define ASSERT(x) {                                  \
    std::ostringstream os;                           \
    os << ", file " << __FILE__                      \
       << ", function " << __func__                  \
       << ", line " << __LINE__;                     \
    Testlib::Assert(x, os.str());                    \
}

/*!
 * \brief Assert macros and message printing
 *
 * \details Assert macros and message printing
 *
 */
#define ASSERT_MSG(x, msg) {                         \
    std::ostringstream os;                           \
    os << "message: " << msg                         \
       << ", file " << __FILE__                      \
       << ", function " << __func__                  \
       << ", line " << __LINE__;                     \
    if (Testlib::Assert(x, os.str()) &&              \
        Testlib::__assert_print_if_ok) {             \
        std::cerr << msg << " - OK\n";               \
    }                                                \
}


/*!
* \brief Namespace with functions ans classes for unit testing
*
* \details Namespace with functions ans classes for unit testing
*
*/
namespace Testlib {
    extern bool __assert_print_to_stderr; ///< Turn on to enable std::cerr output
    extern bool __assert_print_if_ok;     ///< Print if test is passed, not only fails
    extern bool __assert_throw_exception; ///< Throw exception if test is failed
    extern bool __test_print_to_stderr;   ///< Print to std::cerr during testing
    extern bool __test_throw_exception;   ///< Throw exception during testing if test is failed

    /*!
    * \brief Assert function for equality check
    *
    * \details Assert function for equality check
    *
    */
    template < class T , class V >
    bool AssertEqual(const T  &rhs, const V   &lhs, const std::string &info = "") {
        if (!(rhs == lhs)) {
            std::ostringstream os;
            os << "Assertion failed: " << rhs << " != " << lhs;

            if (!info.empty()) {
                os << ", info: " << info;
            }

            if (__assert_print_to_stderr) {
                std::cerr << os.str() << std::endl;
            }

            if (__assert_throw_exception) {
                throw std::runtime_error(os.str());
            }

            return false;
        }

        return true;
    }

    /*!
    * \brief Assert function
    *
    * \details Assert function
    *
    */
    inline bool Assert(const bool &value, const std::string &info = "") {
        return AssertEqual(value, true, info);
    }

    /*!
    * \brief Class for unit testing
    *
    * \details Class for unit testing
    *
    */
    class Test {
    public:
        /*!
        * \brief Function for test running
        *
        * \details Function for test running
        *
        */
        template < class TestFunction >
        void runTest(TestFunction func, const std::string &test_name = "") {
            try {
                func();

                std::ostringstream os;
                os << test_name << ": OK";

                if (__test_print_to_stderr) {
                    std::cerr << os.str() << std::endl;
                }
            } catch (std::exception &e) {
                ++fail_count;

                std::ostringstream os;
                os << test_name << ": FAIL";
                if (!__assert_print_to_stderr) {
                    os << ": " << e.what();
                }

                if (__test_print_to_stderr) {
                    std::cerr << os.str() << std::endl;
                }

                if (__test_throw_exception) {
                    throw std::runtime_error(os.str());
                }
            } catch (...) {
                ++fail_count;

                std::ostringstream os;
                os << "Unknown exception caught";

                if (__test_print_to_stderr) {
                    std::cerr << os.str() << std::endl;
                }

                if (__test_throw_exception) {
                    throw std::runtime_error(os.str());
                }
            }
        }

        /*!
        * \brief Get fail count
        *
        * \details Get fail count
        *
        */
        int failCount() const {
            return fail_count;
        }

        /*!
        * \brief Fail count reset
        *
        * \details Fail count reset
        *
        */
        void resetFailCount() {
            fail_count = 0;

            return;
        }

        /*!
        * \brief Destructor
        *
        * \details Destructor prints amount of failed tests and throws exception is the settings oblige
        *
        */
        ~Test() {
            if (fail_count > 0) {
                std::ostringstream os;
                os << "FAILED " << fail_count << " TESTS" << std::endl;

                if (__test_print_to_stderr) {
                    std::cerr << os.str();
                }

                if (__test_throw_exception) {
                    throw std::runtime_error(os.str()); /// PVS V509 - throw inside destructor is illegal
                }
            } else {
                if (__test_print_to_stderr) {
                    std::cerr << "ALL TESTS PASSED \n";
                }
            }
        }

    protected:
        int fail_count = 0; ///< Amount of failed tests
    };
}




#endif // TESTLIB1_H_INCLUDED
