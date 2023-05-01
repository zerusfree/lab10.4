#include "pch.h"
#include "CppUnitTest.h"
#include "../Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest104
{
	TEST_CLASS(UnitTest104)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			string inputLine = "sdmaskc awda daw.wd w";
			int numWords = 0, numDelimiters = 0;

			countWordsAndDelimiters(inputLine, numWords, numDelimiters);

			Assert::AreEqual(5, numWords);
			Assert::AreEqual(1, numDelimiters);
		}
	};
}
