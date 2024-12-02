#include "pch.h"
#include "CppUnitTest.h"
#include "../5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestInvalidRange)
		{
			int K = 7, N = 5;
			double expected = 1.0;

			Assert::AreEqual(expected, P0(K, N), 0.001, L"P0 does not match");
			Assert::AreEqual(expected, P1(K, N, K), 0.001, L"P1 does not match");
			Assert::AreEqual(expected, P2(K, N, N), 0.001, L"P2 does not match");
			Assert::AreEqual(expected, P3(K, N, K, 1), 0.001, L"P3 does not match");
			Assert::AreEqual(expected, P4(K, N, N, 1), 0.001, L"P4 does not match");
		}

		TEST_METHOD(TestZeroRange)
		{
			int K = 0, N = 0;
			double expected = 1.0;

			Assert::AreEqual(expected, P0(K, N), 0.001, L"P0 does not match");
			Assert::AreEqual(expected, P1(K, N, K), 0.001, L"P1 does not match");
			Assert::AreEqual(expected, P2(K, N, N), 0.001, L"P2 does not match");
			Assert::AreEqual(expected, P3(K, N, K, 1), 0.001, L"P3 does not match");
			Assert::AreEqual(expected, P4(K, N, N, 1), 0.001, L"P4 does not match");
		}
	};
}
