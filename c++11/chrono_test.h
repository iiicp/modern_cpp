/**********************************
 * File:     chrono_test.h
 *
 * Author:   caipeng
 *
 * Email:    iiicp@outlook.com
 *
 * Date:     2021/9/28
 ***********************************/

#ifndef CPP11TEST_CHRONO_TEST_H
#define CPP11TEST_CHRONO_TEST_H

#include <thread>
#include <chrono>
#include <string>

/// 0, 首先选择时钟，一般是system_clock或者steady_clock
/// 1. 获取开始时间点
///     time_since_epoch 表示获取到距离1970年的时间ms
/// 2. 获取结束时间点
///      时间点间可以进行time_point_cast<>
/// 3, 时间点的差值就是 duration
///      duration之间也可以进行转换,使用duration_cast<>
///    最后打印的时候都是通过count()来做

class ChronoTest {
public:
  void sum10000() {
    float sum = 1;
    for (int i = 0; i < 10000; ++i) {
      for (int j = 0; j < 10000; ++j) {
        sum += (i+j+1);
      }
    }
  }
  void testSystemClock() {
    using namespace std::chrono;

    /// 获取开始时间点
    time_point<system_clock> start = system_clock::now();
    sum10000();
    ///std::this_thread::sleep_for(std::chrono::seconds(2));
    /// 获取结束时间点
    time_point<system_clock> end = system_clock::now();

    duration<double> elapsed_s = (end - start);
    duration<double, std::milli> elapsed_ms =  end - start;
    duration<double, std::micro> elepsed_mics = end - start;
    duration<double, std::nano> elepsed_nanos = end - start;
    std::cout << "Elapsed time: " << elapsed_s.count() << " s" << std::endl;
    std::cout << "Elapsed time: " << elapsed_ms.count() << " ms" << std::endl;
    std::cout << "Elapsed time: " << elepsed_mics.count() << " mics" << std::endl;
    std::cout << "Elapsed time: " << elepsed_nanos.count() << " mics" << std::endl;

    /// 获取时间戳
    /// 默认是us
    std::cout << start.time_since_epoch().count() << std::endl;
    /// 时间点可以转换成其它单位，eg 转成了second
    auto s = time_point_cast<seconds>(start);
    std::cout << s.time_since_epoch().count() << std::endl;
  }

  void testSteadyClock() {
    using namespace std::chrono;

    time_point<steady_clock> start = steady_clock::now();
    sum10000();
    time_point<steady_clock> end = steady_clock::now();

    auto elapsed_int = duration_cast<std::chrono::seconds>(end - start);
    std::cout << "Elapsed time: " << elapsed_int.count() << "s" << std::endl;
  }

  void getSystemTime() {
    using namespace std::chrono;

    time_point<system_clock> s = system_clock::now();
    std::time_t tt = system_clock::to_time_t(s);

    std::string stt = std::ctime(&tt);
    std::cout << stt << std::endl;
    std::tm* now = std::gmtime(&tt);
    printf("%4d年%02d月%02d日 %02d:%02d:%02d\n",
           now->tm_year+1900, now->tm_mon+1, now->tm_mday, now->tm_hour, now->tm_min, now->tm_sec);
  }

  void testDuration() {
    using namespace std::chrono;
    auto t1 = system_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    auto t2 = system_clock::now();
    duration<double, std::milli> fp_ms = t2-t1;
    std::cout << fp_ms.count() << std::endl;

    auto int_ms = duration_cast<std::chrono::milliseconds>(fp_ms);
    std::cout << "int ms: " << int_ms.count() << std::endl;

    duration<long, std::micro> int_usec = int_ms;
    std::cout << "usec: " << int_usec.count() << std::endl;
  }

  void testTimepoint() {
    using namespace std::chrono;
    auto t = system_clock::now();
    auto t2 = time_point_cast<seconds>(t);
    auto t3 = steady_clock::now();
    std::cout << t.time_since_epoch().count() << " us" << std::endl;
    std::cout << t2.time_since_epoch().count() << " s" << std::endl;
    std::cout << t3.time_since_epoch().count() << " us" << std::endl;
  }
};

#endif // CPP11TEST_CHRONO_TEST_H
