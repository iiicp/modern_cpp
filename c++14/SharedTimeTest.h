/**********************************
 * File:     SharedTimeTest.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef C_14_TEST_SHAREDTIMETEST_H
#define C_14_TEST_SHAREDTIMETEST_H
#include <thread>
#include <shared_mutex>
class SharedTimeTest {
public:
  SharedTimeTest() {}
  ~SharedTimeTest() {}

  void numberIncrement() {
    std::lock_guard<std::shared_timed_mutex> lock(m_mutex);
    for (int i = 0; i < 10000; ++i)
      ++value;
  }

  void numberDecrement() {
    std::lock_guard<std::shared_timed_mutex> lock(m_mutex);
    for (int i = 0; i < 10000; ++i)
      --value;
  }

  unsigned int numberPrint() {
    std::lock_guard<std::shared_timed_mutex> lock(m_mutex);
    return value;
  }

private:
  mutable std::shared_timed_mutex m_mutex;
  unsigned int value;
};

#endif // C_14_TEST_SHAREDTIMETEST_H
