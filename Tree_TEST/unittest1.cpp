#include "stdafx.h"
#include "CppUnitTest.h"
#include "../SDP_dom_4/Tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tree_TEST
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AreIsomorphic)
		{
			// TODO: Your test code here
			Tree a, b;

			a.build("(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})");

			b.build("(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})");

			a.AssigCanonName();
			b.AssigCanonName();
			Assert::AreEqual(a.GetCanonName(), b.GetCanonName());
		}

		TEST_METHOD(AreNotIsomorphic)
		{
			// TODO: Your test code here
			Tree a, b;
			a.build("(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})");
			b.build("(7{(15 {(7 {}) (10 {})}) (3 {})})");

			a.AssigCanonName();
			b.AssigCanonName();
			Assert::AreNotEqual(a.GetCanonName(), b.GetCanonName());
		}

		TEST_METHOD(Isomorphic2)
		{
			// TODO: Your test code here
			Tree a, b;
			a.build("(5 {(9 {}) (1 {(4 {}) (12 {}) (42 {})})})");
			b.build("(7 {(15 {(7 {}) (10 {}) (8 {})}) (3 {})})");

			Assert::IsTrue(a.AreIsomorphic(b));
		}
	};
}