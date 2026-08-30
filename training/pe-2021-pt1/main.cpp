#include "circularIntLinkedList.h"
#include <ctime>
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////
//      Feel free to modify this file to do testing and debuging          //
//      However, you should NOT submit any of these to coursemology       //
////////////////////////////////////////////////////////////////////////////

namespace {

void advanceHeadEmptyTest() {
  CircularList l;

  l.advanceHead();

  testing::internal::CaptureStdout();
  l.print();
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, "\n");
}

void advanceHeadTest() {
  std::stringstream buffer;
  std::streambuf *old_stdout =
      std::cout.rdbuf(buffer.rdbuf()); // redirect stdout to our buffer
  CircularList l;

  l.insertHead(1);
  l.insertHead(2);
  l.insertHead(3);

  l.print();
  EXPECT_EQ(buffer.str(), "3 2 1 \n");
  buffer.str(""); // reset content in buffer

  l.advanceHead();
  l.print();
  EXPECT_EQ(buffer.str(), "2 1 3 \n");
  buffer.str(""); // reset content in buffer

  l.advanceHead();
  l.print();
  EXPECT_EQ(buffer.str(), "1 3 2 \n");
  buffer.str(""); // reset content in buffer

  l.advanceHead();
  l.print();
  EXPECT_EQ(buffer.str(), "3 2 1 \n");
  buffer.str(""); // reset content in buffer

  l.advanceHead();
  l.print();
  EXPECT_EQ(buffer.str(), "2 1 3 \n");
  buffer.str(""); // reset content in buffer

  std::cout.rdbuf(
      old_stdout); // NOTE: redirect back to stdout, if not will segfault
}

TEST(CircularList, emptyHeadItemTest) {
  CircularList l;

  EXPECT_THROW(l.headItem(), std::out_of_range);
}

TEST(CircularList, headItemTest) {
  CircularList l;
  l.insertHead(123);
  l.insertHead(11);
  l.insertHead(9);
  l.insertHead(1);
  l.insertHead(20);

  EXPECT_EQ(l.headItem(), 20);
}

TEST(CircularList, emptyExistTest) {
  CircularList l;

  EXPECT_EQ(l.exist(9999), false);
}

TEST(CircularList, notExistTest) {

  CircularList l;
  l.insertHead(123);
  l.insertHead(11);
  l.insertHead(9);
  l.insertHead(1);
  l.insertHead(20);

  EXPECT_EQ(l.exist(9999), false);
}

TEST(CircularList, existTest) {
  CircularList l;
  l.insertHead(123);
  l.insertHead(11);
  l.insertHead(9);
  l.insertHead(1);
  l.insertHead(20);

  EXPECT_EQ(l.exist(9), true);
}

TEST(CircularList, removeHeadTest) {
  std::stringstream buffer;
  std::streambuf *old_stdout =
      std::cout.rdbuf(buffer.rdbuf()); // redirect stdout to our buffer
  CircularList l;

  l.insertHead(123);
  l.insertHead(11);
  l.insertHead(9);
  l.insertHead(1);
  l.insertHead(20);

  l.print();
  EXPECT_EQ(buffer.str(), "20 1 9 11 123 \n");
  buffer.str(""); // reset content in buffer

  std::vector<int> exp{20, 1, 9, 11, 123};
  for (int i = 0; i < 5; i++) {
    // cout << "After removing the head, the current list is: ";
    l.removeHead();
    l.print();

    std::ostringstream oss;
    for (size_t j = i + 1; j < 5; j++) {
      oss << exp[j];
      if (j < exp.size() - 1) {
        oss << " "; // Add delimiter between elements
      }
    }
    if (i != 4) { // last element no " "
      oss << " ";
    }
    oss << "\n";

    EXPECT_EQ(buffer.str(), oss.str());
    buffer.str("");
  }

  std::cout.rdbuf(
      old_stdout); // NOTE: redirect back to stdout, if not will segfault
}

TEST(CircularList, insertHeadTest2) {
  CircularList l;
  l.insertHead(123);
  l.insertHead(11);
  l.insertHead(9);
  l.insertHead(1);
  l.insertHead(20);

  testing::internal::CaptureStdout();
  l.print();
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, "20 1 9 11 123 \n");
}

TEST(CircularList, insertHeadTest) {
  CircularList l;
  // Alternative:
  // testing::internal::CaptureStdout();
  // std::cout << "First message";
  // std::string output1 = testing::internal::GetCapturedStdout();
  std::stringstream buffer;
  std::streambuf *old_stdout =
      std::cout.rdbuf(buffer.rdbuf()); // redirect stdout to our buffer

  // cout << "insertHeadtest()" << endl;
  l.insertHead(123);
  // cout << "After adding 123" << endl;
  l.print();
  EXPECT_EQ(buffer.str(), "123 \n");
  buffer.str(""); // reset content in buffer

  l.insertHead(11);
  // cout << "After adding 11" << endl;
  l.print();
  EXPECT_EQ(buffer.str(), "11 123 \n");
  buffer.str("");

  l.insertHead(9);
  // cout << "After adding 9" << endl;

  l.print();
  EXPECT_EQ(buffer.str(), "9 11 123 \n");
  buffer.str("");

  l.insertHead(1);
  // cout << "After adding 1" << endl;
  l.print();
  EXPECT_EQ(buffer.str(), "1 9 11 123 \n");
  buffer.str("");
  l.insertHead(20);
  // cout << "After adding 20" << endl;
  l.print();
  EXPECT_EQ(buffer.str(), "20 1 9 11 123 \n");
  buffer.str("");
  // cout << endl;

  std::cout.rdbuf(old_stdout); // redirect back to stdout
}
} // namespace

// void insertHeadTest();
// void existTest();
// void advanceHeadTest();
// void removeHeadTest();
// void removeAndAdvanceHeadTest();
// void timingTest();
//
// int main() {
//   // Feel free to uncomment the following functions to test/debug your code
//   insertHeadTest();
//   // existTest();
//   // advanceHeadTest();
//   // removeHeadTest();
//   // removeAndAdvanceHeadTest();
//   // timingTest();
//   return 0;
// }
//
// void insertHeadTest() {}
//
//
// void existTest() {
//   CircularList l;
//   cout << "existTest()" << endl;
//   l.insertHead(123);
//   l.insertHead(11);
//   l.insertHead(9);
//   l.insertHead(1);
//   l.insertHead(20);
//
//   cout << "The list is: ";
//   l.print();
//   cout << "Does 9 exist in the list? " << (l.exist(9) ? "Yes" : "No") << endl
//        << endl;
//   cout << "Does 11 exist in the list? " << (l.exist(11) ? "Yes" : "No") <<
//   endl
//        << endl;
//   cout << "Does 99 exist in the list? " << (l.exist(99) ? "Yes" : "No") <<
//   endl
//        << endl;
//   cout << endl;
// }
//
// void removeHeadTest() {
//
//   CircularList l;
//   cout << "removeHeadtest()" << endl;
//   l.insertHead(123);
//   l.insertHead(11);
//   l.insertHead(9);
//   l.insertHead(1);
//   l.insertHead(20);
//   for (int i = 0; i < 5; i++) {
//     l.removeHead();
//     cout << "After removing the head, the current list is: ";
//     l.print();
//     cout << "Does 9 exist in the list? " << (l.exist(9) ? "Yes" : "No") <<
//     endl
//          << endl;
//   }
//   cout << endl;
// }
//
// void removeAndAdvanceHeadTest() {
//   CircularList l;
//   cout << "removeAndAdvanceHeadTest()" << endl;
//   l.insertHead(123);
//   l.insertHead(11);
//   l.insertHead(9);
//   l.insertHead(1);
//   l.insertHead(20);
//
//   for (int i = 0; i < 4; i++) {
//     cout << "The current list is: ";
//     l.print();
//     cout << "Does 9 exist in the list? " << (l.exist(9) ? "Yes" : "No") <<
//     endl
//          << endl;
//     l.removeHead();
//     l.advanceHead();
//     cout << "Now we remove the head and advance it once" << endl;
//   }
//   cout << endl;
// }
//
// void timingTest() {
//   cout << "Timing Test" << endl;
//   for (int nt = 1; nt <= 1000000; nt *= 10) {
//     clock_t begin = clock();
//
//     CircularList l; // a new list
//     for (int i = 0; i < nt; i++)
//       l.insertHead(i);
//
//     clock_t end = clock();
//     double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//     cout << "Time taken for adding " << nt << " items : " << elapsed_secs <<
//     "s"
//          << endl;
//
//     begin = clock();
//     for (int i = 0; i < (3 * nt / 4); i++)
//       l.advanceHead();
//     end = clock();
//     elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
//     cout << "Time taken for advancing three quarters of the list: "
//          << elapsed_secs << "s" << endl;
//     cout << "(Head item = " << l.headItem() << ")" << endl << endl;
//   }
// }
